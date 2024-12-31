#!/bin/bash

# Container and image names
CONTAINER_NAME="ros1_multilateration"
IMAGE_NAME="ros-noetic-multilateration"

# Directories
BAG_DIR_INPUT="$PWD/Dataset"
BAG_DIR_OUTPUT="$PWD/Code/SARFIS/Matlab functions/ROS"

# Execution mode (default: OLS)
MODE=${1:-OLS}

# Playback speed (default: 1)
PLAYBACK_SPEED=${2:-1}

# Validate playback speed
if ! [[ "$PLAYBACK_SPEED" =~ ^[0-9]+(\.[0-9]+)?$ ]]; then
    echo "[ERROR] Playback speed must be a positive number."
    exit 1
fi

# X11 configuration
echo "Configuring X11 access..."
xhost +local:root

# Ensure the rosbag directories exist
mkdir -p "$BAG_DIR_INPUT"
mkdir -p "$BAG_DIR_OUTPUT"

# Launch the container
echo "[INFO] Launching the container..."
docker run -it \
    --net=host \
    --name "$CONTAINER_NAME" \
    --env="DISPLAY=$DISPLAY" \
    --env="QT_X11_NO_MITSHM=1" \
    --volume="$PWD/Code":/root/Code \
    --volume="$PWD/Dataset":/root/Dataset \
    --volume="$PWD/Demo":/root/Demo \
    --volume="$PWD/Figures":/root/Figures \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    "$IMAGE_NAME" \
    bash -c "
    source /opt/ros/noetic/setup.bash &&
    bash /root/Dataset/Real_JEMERG23.sh $MODE $PLAYBACK_SPEED
    "

# Revoke X11 permissions at the end
echo "[INFO] Revoking X11 permissions..."
xhost -local:root
