# Use the official ROS Noetic image
FROM ros:noetic-ros-core

# Configure keyboard layout
RUN apt-get update && apt-get install -y debconf && \
    echo "keyboard-configuration keyboard-configuration/layoutcode select es" | debconf-set-selections && \
    echo "keyboard-configuration keyboard-configuration/xkb-keymap select es" | debconf-set-selections

# Update and install necessary packages, including RQT, RVIZ, psmisc, and Terminator
RUN apt-get update && apt-get install -y \
    python3-rosbag \
    python3-pip \
    python3-tk \
    python3-pyqt5 \
    nano \
    iputils-ping \
    x11-apps \
    libgl1-mesa-glx \
    ros-noetic-desktop \
    ros-noetic-rqt \
    ros-noetic-rviz \
    keyboard-configuration \
    psmisc \
    terminator \
    netcat \
    && rm -rf /var/lib/apt/lists/*

# Install Python packages
RUN pip3 install --no-cache-dir \
    rospkg \
    catkin_pkg \
    geopy \
    numpy==1.21 \
    pandas \
    pyproj \
    flask \
    matplotlib

# Copy the Real_JEMERG23.sh script to the container's root directory
COPY Dataset/Real_JEMERG23.sh /root/Real_JEMERG23.sh
RUN chmod +x /root/Real_JEMERG23.sh

# Configure environment variables for X11 and ROS
ENV DISPLAY=:1
ENV QT_X11_NO_MITSHM=1

# Add ROS Noetic source to bashrc
RUN echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc

# Define the entry point
CMD ["bash"]

