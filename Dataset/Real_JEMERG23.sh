#!/bin/bash

# Variables
ROS_SETUP="/opt/ros/noetic/setup.bash"
SCRIPT_DIR="/root/Code/Multilateration"
BAG_DIR="/root/Code/SARFIS/Matlab functions/ROS"
INPUT_BAG_FILE="/root/Dataset/rawRosbag.bag"

# Funciones
validate_file() {
    if [ ! -f "$1" ]; then
        echo "[ERROR] File $1 not found."
        exit 1
    fi
}

stop_process() {
    local pid=$1
    if [ -n "$pid" ] && kill -0 "$pid" 2>/dev/null; then
        echo "[INFO] Stopping process with PID $pid..."
        kill "$pid"
    else
        echo "[INFO] Process with PID $pid is not running."
    fi
}

log_info() {
    echo "[INFO] $1"
}

log_warn() {
    echo "[WARN] $1"
}

log_error() {
    echo "[ERROR] $1" >&2
}

# Trap para limpiar procesos al salir
trap "stop_process $ROSCORE_PID; stop_process $ROSBAG_RECORD_PID; stop_process $ROSBAG_PLAY_PID; stop_process $ROS_WRAPPER_PID; stop_process $SERVER_PID" EXIT

# Validar argumentos
if [ -z "$1" ]; then
    log_error "Usage: $0 <Mode> <Playback Speed>"
    echo "Example: $0 OLS 1"
    exit 1
fi
MODE=$1
PLAYBACK_SPEED=$2

# Validar velocidad de reproducción
if ! [[ "$PLAYBACK_SPEED" =~ ^[0-9]+(\.[0-9]+)?$ ]]; then
    log_error "Playback speed must be a positive number."
    exit 1
fi
log_info "Playback speed set to -r $PLAYBACK_SPEED."

# Preparar directorios
mkdir -p "$BAG_DIR"
TIMESTAMP=$(date +"%Y-%m-%d_%H-%M-%S")
BAG_FILE="${BAG_DIR}/rawRosbag_${MODE}_${TIMESTAMP}.bag"
log_info "Expected rosbag file: $BAG_FILE"

# Iniciar roscore
if nc -z localhost 11311; then
    log_info "roscore is already running on localhost:11311"
else
    log_info "Starting roscore..."
    source $ROS_SETUP
    roscore &
    ROSCORE_PID=$!
    sleep 5
fi

# Validar rosbag de entrada
validate_file "$INPUT_BAG_FILE"

# Ejecutar scripts ROS necesarios
SCRIPTS=(
    "${SCRIPT_DIR}/server_ros_bridge.py"
    "${SCRIPT_DIR}/ros_wrapper.py"
)
for SCRIPT in "${SCRIPTS[@]}"; do
    validate_file "$SCRIPT"
done

log_info "Starting server_ros_bridge.py..."
python3 "${SCRIPT_DIR}/server_ros_bridge.py" > /tmp/server_ros_bridge.log 2>&1 &
SERVER_PID=$!
log_info "server_ros_bridge.py started with PID $SERVER_PID."

log_info "Starting ros_wrapper.py..."
python3 "${SCRIPT_DIR}/ros_wrapper.py" > /tmp/ros_wrapper.log 2>&1 &
ROS_WRAPPER_PID=$!
log_info "ros_wrapper.py started with PID $ROS_WRAPPER_PID."

# Reproducir y grabar rosbag
log_info "Playing input bag at speed -r $PLAYBACK_SPEED..."
rosbag play "$INPUT_BAG_FILE" -r "$PLAYBACK_SPEED" &
ROSBAG_PLAY_PID=$!

log_info "Recording rosbag to $BAG_FILE..."
rosbag record -a -O "$BAG_FILE" > /tmp/rosbag_record.log 2>&1 &
ROSBAG_RECORD_PID=$!

# Esperar que termine la reproducción
wait $ROSBAG_PLAY_PID

# Detener grabación del rosbag
log_info "Stopping rosbag record..."
stop_process $ROSBAG_RECORD_PID

# Esperar a que el rosbag grabado esté disponible
for i in {1..5}; do
    if [ -f "$BAG_FILE" ]; then
        log_info "Rosbag file $BAG_FILE found."
        break
    else
        log_warn "Rosbag file $BAG_FILE not yet available. Retrying in 2 seconds..."
        sleep 2
    fi
done

# Validar existencia del rosbag después del bucle
if [ ! -f "$BAG_FILE" ]; then
    log_error "Rosbag file $BAG_FILE not found. Check /tmp/rosbag_record.log for details."
    cat /tmp/rosbag_record.log
    exit 1
fi

# Procesar el rosbag grabado
log_info "Processing the recorded rosbag..."
BAG_INFO=$(rosbag info --yaml "$BAG_FILE")
log_info "Rosbag info: $BAG_INFO"

BAG_START_TIME=$(echo "$BAG_INFO" | grep -m 1 "start" | awk '{print $2}')
BAG_END_TIME=$(echo "$BAG_INFO" | grep -m 1 "end" | awk '{print $2}')
log_info "Start Time: $BAG_START_TIME"
log_info "End Time: $BAG_END_TIME"

if [ -z "$BAG_START_TIME" ] || [ -z "$BAG_END_TIME" ]; then
    log_error "Failed to extract start or end time from rosbag. Aborting graph generation."
else
    log_info "Executing graph generation script..."
    python3 "${SCRIPT_DIR}/data_visualization.py" "$BAG_FILE" "$BAG_START_TIME" "$BAG_END_TIME" > /tmp/data_visualization.log 2>&1
    if [ $? -eq 0 ]; then
        log_info "Graph generation script executed successfully."
    else
        log_error "Graph generation script failed. Check /tmp/data_visualization.log for details."
        cat /tmp/data_visualization.log
    fi
fi

# Detener roscore
log_info "Stopping roscore..."
stop_process $ROSCORE_PID

# Detener scripts adicionales
log_info "Stopping server_ros_bridge.py..."
stop_process $SERVER_PID

log_info "Stopping ros_wrapper.py..."
stop_process $ROS_WRAPPER_PID

log_info "All processes terminated successfully. Interactive shell available."
bash
