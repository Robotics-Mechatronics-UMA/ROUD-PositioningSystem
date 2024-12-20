# Usa la imagen oficial de ROS Noetic
FROM ros:noetic-ros-core

# Configura la selección de país de origen para el teclado en España
RUN apt-get update && apt-get install -y debconf && \
    echo "keyboard-configuration keyboard-configuration/layoutcode select es" | debconf-set-selections && \
    echo "keyboard-configuration keyboard-configuration/xkb-keymap select es" | debconf-set-selections

# Actualiza e instala paquetes necesarios, incluyendo RQT, RVIZ, psmisc, y terminator
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
    && rm -rf /var/lib/apt/lists/*

# Instala paquetes de Python
RUN pip3 install --no-cache-dir \
    rospkg \
    catkin_pkg \
    geopy \
    numpy==1.21 \
    pandas \
    pyproj \
    flask \
    matplotlib

# Copia el script Real_JEMERG23.sh al directorio principal del contenedor
COPY Dataset/Real_JEMERG23.sh /root/Real_JEMERG23.sh
RUN chmod +x /root/Real_JEMERG23.sh

# Configura las variables de entorno para X11 y ROS
ENV DISPLAY=:1
ENV QT_X11_NO_MITSHM=1

# Agrega el source de ROS Noetic al bashrc
RUN echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc

# Define el punto de entrada
CMD ["bash"]

