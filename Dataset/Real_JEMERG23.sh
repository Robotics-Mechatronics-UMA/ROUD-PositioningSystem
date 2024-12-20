#!/bin/bash

# Directories
ROS_SETUP="/opt/ros/noetic/setup.bash"
SCRIPT_DIR="/root/Code/Multilateration"

# Check if ROS setup file exists
if [ ! -f "$ROS_SETUP" ]; then
    echo "File $ROS_SETUP not found."
    exit 1
fi

# Check if Mode parameter is passed
if [ -z "$1" ]; then
    echo "Usage: $0 <Mode>"
    echo "Example: $0 OLS"
    exit 1
fi

MODE=$1  # Get Mode from user input

# Determine the filename for the rosbag
BAG_DIR="/root/Code/SARFIS/Matlab functions/ROS"
for i in $(seq -w 000 999); do
    BAG_FILE="${BAG_DIR}/rawRosbag_${MODE}_offline${i}.bag"
    if [ ! -f "$BAG_FILE" ]; then
        break
    fi
done

if [ -f "$BAG_FILE" ]; then
    echo "Error: Could not determine a unique filename for the rosbag."
    exit 1
fi

# Start roscore in the background
echo "Starting roscore..."
source $ROS_SETUP
roscore &
ROSCORE_PID=$!
sleep 5

# Play rosbag in the background
echo "Playing input bag..."
rosbag play /root/Dataset/input.bag &
ROSBAG_PLAY_PID=$!
sleep 2

# Start recording rosbag in the background
echo "Recording rosbag to $BAG_FILE..."
rosbag record -a -o "$BAG_FILE" &
ROSBAG_RECORD_PID=$!
sleep 2

# Wait for rosbag play to finish
wait $ROSBAG_PLAY_PID

# Stop rosbag record
echo "Stopping rosbag record..."
kill $ROSBAG_RECORD_PID

# Stop roscore
echo "Stopping roscore..."
kill $ROSCORE_PID

# Process the bag
process_bag() {
    echo "Bag Path: $BAG_FILE"
    echo "Start Time: $(rosbag info --yaml $BAG_FILE | grep start | awk '{print $2}')"
    echo "End Time: $(rosbag info --yaml $BAG_FILE | grep end | awk '{print $2}')"
}
process_bag

echo "All processes terminated successfully."

