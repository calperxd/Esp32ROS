# Project Development Script README

## Overview
This README provides instructions for using the `devtool.sh` script, which facilitates various development tasks for an ESP32 project within a Docker environment.

## Prerequisites
- Docker installed on your machine
- Basic knowledge of Docker and ESP32 development

## Script Functions
- `buildenv`: Builds the Docker development environment
- `enterenv`: Enters the Docker development environment
- `compile`: Compiles the ESP32 project
- `flash`: Flashes the ESP32 device

## Usage
To use the script, run it with one of the following commands:
- `./devtool.sh buildenv`
- `./devtool.sh enterenv`
- `./devtool.sh compile`
- `./devtool.sh flash`

## Error Handling
If an incorrect command is passed, the script will display an error message along with usage instructions.