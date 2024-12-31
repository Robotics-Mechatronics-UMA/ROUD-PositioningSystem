#!/bin/bash

# Variables
CONTAINER_NAME="ros1_multilateration"
IMAGE_NAME="ros-noetic-multilateration"

# Directorios
BAG_DIR_INPUT="$PWD/Dataset"
BAG_DIR_OUTPUT="$PWD/Code/SARFIS/Matlab functions/ROS"
FIGURES_DIR="$PWD/Figures"

# Modo de ejecución (por defecto: OLS)
MODE=${1:-OLS}

# Velocidad de reproducción (por defecto: 1)
PLAYBACK_SPEED=${2:-1}

# Validar velocidad de reproducción
if ! [[ "$PLAYBACK_SPEED" =~ ^[0-9]+(\.[0-9]+)?$ ]]; then
    echo "[ERROR] Playback speed must be a positive number."
    exit 1
fi

# Configuración de X11
echo "Configuring X11 access..."
xhost +local:root

# Crear directorios si no existen
mkdir -p "$BAG_DIR_INPUT"
mkdir -p "$BAG_DIR_OUTPUT"
mkdir -p "$FIGURES_DIR"

# Generar un nombre dinámico para el rosbag basado en el modo y la marca de tiempo
TIMESTAMP=$(date +"%Y-%m-%d_%H-%M-%S")
OUTPUT_BAG_NAME="rawRosbag_${MODE}_${TIMESTAMP}.bag"

# Lanzar el contenedor
echo "[INFO] Launching the container..."
docker run -it \
    --net=host \
    --name "$CONTAINER_NAME" \
    --env="DISPLAY=$DISPLAY" \
    --env="QT_X11_NO_MITSHM=1" \
    --volume="$PWD/Code":/root/Code \
    --volume="$PWD/Dataset":/root/Dataset \
    --volume="$PWD/Figures":/root/Figures \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    "$IMAGE_NAME" \
    bash -c "
    source /opt/ros/noetic/setup.bash &&
    echo 'Running jemerg.sh with MODE=$MODE and PLAYBACK_SPEED=$PLAYBACK_SPEED...' &&
    bash /root/Dataset/jemerg.sh $MODE $PLAYBACK_SPEED &&
    echo 'Starting rosbag play and recording...';

    # Archivo de entrada para rosbag
    INPUT_BAG_FILE=/root/Dataset/rawRosbag.bag

    if [ ! -f \$INPUT_BAG_FILE ]; then
        echo '[ERROR] Input bag file \$INPUT_BAG_FILE not found.'
        exit 1
    fi

    # Reproducir el rosbag de entrada
    echo '[INFO] Playing input bag at speed -r \$PLAYBACK_SPEED...'
    rosbag play \"\$INPUT_BAG_FILE\" -r \"\$PLAYBACK_SPEED\" &
    PLAY_PID=\$!

    # Grabar un nuevo rosbag
    OUTPUT_BAG_PATH=\"/root/Code/SARFIS/Matlab functions/ROS/$OUTPUT_BAG_NAME\"
    rosbag record -a -O \"\$OUTPUT_BAG_PATH\" &
    RECORD_PID=\$!

    # Esperar a que termine la reproducción del rosbag
    wait \$PLAY_PID

    # Detener la grabación del rosbag
    echo '[INFO] Stopping rosbag record...'
    kill \$RECORD_PID

    # Procesar el rosbag grabado
    echo '[INFO] Processing the recorded bag...'
    BAG_INFO=\$(rosbag info --yaml \"\$OUTPUT_BAG_PATH\")
    BAG_START_TIME=\$(echo \"\$BAG_INFO\" | grep -m 1 'start' | awk '{print \$2}')
    BAG_END_TIME=\$(echo \"\$BAG_INFO\" | grep -m 1 'end' | awk '{print \$2}')

    echo '[INFO] Bag Path: \$OUTPUT_BAG_PATH'
    echo '[INFO] Start Time: \$BAG_START_TIME'
    echo '[INFO] End Time: \$BAG_END_TIME'

    # Ejecutar el script de visualización
    echo '[INFO] Executing graph generation script...'
    python3 /root/Code/Multilateration/data_visualization.py \
        /root/Figures \
        \"$MODE\" \
        \"$PLAYBACK_SPEED\" \
        \"$TIMESTAMP\"
    echo '[INFO] Graph generation script executed.'

    echo '[INFO] Rosbag play and recording completed. Container is still active for visualization.'
    bash
    "

# Revocar permisos de X11 al final
echo "[INFO] Revoking X11 permissions..."
xhost -local:root
