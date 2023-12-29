#!/bin/bash

# Script to manage ESP32 project development tasks

# Variables for Docker image name and Dockerfile
IMAGE_NAME="esp-idf-project"
DOCKERFILE="Docker/Dockerfile"
PROJECT_NAME="JapanTest"

function build_env() {
    echo "Building Docker development environment..."
    docker build --no-cache -t $IMAGE_NAME -f $DOCKERFILE .
}

function enter_env() {
    echo "Entering Docker development environment..."
    docker run -it --rm -v $(pwd):/workspace/$PROJECT_NAME $IMAGE_NAME
}

function compile_project() {
    echo "Compiling the project..."
}

function flash_esp32() {
    echo "Flashing ESP32..."
}

function show_help() {
    echo "Usage: $0 [command]"
    echo "Commands:"
    echo "  buildenv    Build the Docker development environment"
    echo "  enterenv    Enter the Docker development environment"
    echo "  compile     Compile the project"
    echo "  flash       Flash the ESP32 device"
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
    *)
        echo "Error: Unknown command '$1'"
        show_help
        exit 1
        ;;
esac
