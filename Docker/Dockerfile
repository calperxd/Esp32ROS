# Use uma imagem base Ubuntu
FROM ubuntu:latest

# Defina o diretório de trabalho
WORKDIR /workspace

# Instale as dependências necessárias
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

# Instale o ESP-IDF
RUN git clone --recursive https://github.com/espressif/esp-idf.git
ENV IDF_PATH=/workspace/esp-idf
RUN ./esp-idf/install.sh

# Configure o ambiente
RUN echo ". $IDF_PATH/export.sh" >> ~/.bashrc

# Use o bash como shell padrão
SHELL ["/bin/bash", "-c"]

# Continue a configuração do seu projeto aqui...
