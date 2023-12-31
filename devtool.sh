#!/bin/bash

# Script to manage ESP32 project development tasks

# Variables for Docker image name and Dockerfile
IMAGE_NAME="esp-idf-project"
DOCKERFILE="Docker/Dockerfile"
PROJECT_NAME="EspROS"
BUILD_DIR="build sdkconfig"
USB_DEVICE="/dev/ttyUSB0"

function build_env() {
    echo "Building Docker development environment..."
    docker build -t $IMAGE_NAME -f $DOCKERFILE .
}

function enter_env() {
    echo "Entering Docker development environment..."
    docker run -it --rm --device=$USB_DEVICE -v $(pwd):/workspace/$PROJECT_NAME $IMAGE_NAME
}

function compile_project() {
    echo "Compiling the project..."
    idf.py build
}

function flash_esp32() {
    echo "Flashing ESP32..."
    idf.py -p $USB_DEVICE flash
}

function clean_project() {
    echo "Cleaning the project..."
    rm -rf $BUILD_DIR
    echo "Build directory $BUILD_DIR has been cleaned."
}

function show_help() {
    echo "Usage: $0 [command]"
    echo "Commands:"
    echo "  buildenv    Build the Docker development environment"
    echo "  enterenv    Enter the Docker development environment"
    echo "  compile     Compile the project"
    echo "  flash       Flash the ESP32 device"
    echo "  clean       Clean the project build directory"
}

# Check if at least one argument is provided
if [ $# -eq 0 ]; then
    show_help
    exit 1
fi

# Handle the provided argument
case "$1" in
    buildenv)
        build_env
        ;;
    enterenv)
        enter_env
        ;;
    compile)
        compile_project
        ;;
    flash)
        flash_esp32
        ;;
    clean)
        clean_project
        ;;
    *)
        echo "Error: Unknown command '$1'"
        show_help
        exit 1
        ;;
esac