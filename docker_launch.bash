#!/bin/bash

# Container and image names
CONTAINER_NAME="ros1_multilateration"
IMAGE_NAME="ros-noetic-multilateration"

# Directory where recorded rosbags are saved
BAG_DIR="$PWD/Dataset"

# Execution mode (default: OLS)
MODE=${1:-OLS}

# X11 configuration
echo "Configuring X11 access..."
xhost +local:root

# Ensure the rosbag directory exists
mkdir -p "$BAG_DIR"

# Function to process the recorded bag
process_bag() {
    echo "Detecting the recorded rosbag..."
    BAG_FILE=$(ls -t "$BAG_DIR" | grep ".bag" | head -n 1)

    if [ -z "$BAG_FILE" ]; then
        echo "Error: No .bag file found in $BAG_DIR"
        return
    fi

    BAG_PATH="$BAG_DIR/$BAG_FILE"
    echo "Found rosbag file: $BAG_PATH"

    echo "Extracting the rosbag start and end times..."
    BAG_INFO=$(rosbag info --yaml "$BAG_PATH")
    BAG_START_TIME=$(echo "$BAG_INFO" | grep -m 1 "start" | awk '{print $2}')
    BAG_END_TIME=$(echo "$BAG_INFO" | grep -m 1 "end" | awk '{print $2}')

    if [ -z "$BAG_START_TIME" ] || [ -z "$BAG_END_TIME" ]; then
        echo "Error: Failed to extract the start or end time from the rosbag."
        return
    fi

    echo "Bag Path: $BAG_PATH"
    echo "Start Time: $BAG_START_TIME"
    echo "End Time: $BAG_END_TIME"
}

# Launch the main container
echo "Launching the main container..."
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
    echo 'Running Real_JEMERG23.sh with MODE=$MODE...' &&
    bash /root/Dataset/Real_JEMERG23.sh $MODE &&
    echo 'Starting rosbag play and recording...';

    # Start rosbag play
    rosbag play /root/Dataset/input.bag &
    PLAY_PID=\$!

    # Start rosbag record
    rosbag record -a -O $BAG_DIR/recorded.bag &
    RECORD_PID=\$!

    # Wait for rosbag play to finish
    wait \$PLAY_PID

    # Stop rosbag record
    echo 'Stopping rosbag record...'
    kill \$RECORD_PID

    # Process the recorded bag
    echo 'Processing the recorded bag...'
    rosbag info $BAG_DIR/recorded.bag
    process_bag || echo 'Error processing the bag.'
    
    # Keep the container running
    exec bash
    "

# Revoke X11 permissions at the end
echo "Revoking X11 permissions..."
xhost -local:root

