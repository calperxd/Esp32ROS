# latest ubuntu image
FROM ubuntu:latest

# workdir
WORKDIR /workspace

# dependencies
RUN apt-get update && apt-get install -y \
    git \
    wget \
    flex \
    bison \
    gperf \
    python3 \
    python3-pip \
    python3-setuptools \
    python3-venv \
    cmake \
    ninja-build \
    ccache \
    libffi-dev \
    libssl-dev \
    dfu-util \
    libusb-1.0-0

# Install ESP-IDF
RUN git clone -b v5.1.2 --recursive https://github.com/espressif/esp-idf.git
ENV IDF_PATH=/workspace/esp-idf
RUN ./esp-idf/install.sh esp32

# Config env
RUN echo ". $IDF_PATH/export.sh" >> ~/.bashrc

# Bash as default
SHELL ["/bin/bash", "-c"]
