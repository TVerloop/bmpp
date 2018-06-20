#! /bin/bash
#==============================================================================#
# File:     bootstrap.sh
# Author:   Tom Verloop   <T93.Verloop@gmail.com>
# Version:  0.1
# Date:     15-06-2018
#
# Bootstrap
#
# Sets up default build directory with the default toolchain and default build type.
# Maskes symbolic link of the compile commands database.
#==============================================================================#

# Save positional arguments.
POSITIONAL=()
# Default build directory.
BUILD_DIR=build
# Default build type.
BUILD_TYPE=Release
# Default toolchain.
TOOLCHAIN=gcc-arm-none-eabi.cmake

# step through all commandline arguments.
while [[ $# -gt 0 ]]; do

    key="$1"

    case $key in
        # If build dir is specified.
        -d|--build-dir)
            # Override default buil dir.
            BUILD_DIR="$2"
            shift
            shift
            ;;
        # If build type is specified.
        -b|--build-type)
            # Override default build type.
            BUILD_TYPE="$2"
            shift
            shift
            ;;
        # If toolchain is specified.
        -t|--toolchain)
            # Override default toolchain.
            TOOLCHAIN="$2"
            shift;
            shift;
            ;;
        # Else
        *)
            # Save positional flag.
            POSITIONAL+=("$1")
            shift
            ;;
    esac
done

# Apply positional arguments.
set -- "${POSITIONAL[@]}"


function index_rdm() {
    if [ -z "$(ps aux | grep -m 1 '[r]dm' | awk '{print $2}')" ]; then
        rdm &
        local RDM_PID=$!
        sleep .5
    fi

    rc -J .

    if [ ! -z "$RDM_PID"]; then
        kill ${RDM_PID}
    fi
}

# If build dir does not exist create it.
if [ ! -d ${BUILD_DIR} ]; then
    mkdir ${BUILD_DIR}
fi

cd ${BUILD_DIR}

# call cmake to setup build directory.
cmake -DCMAKE_TOOLCHAIN_FILE=toolchains/${TOOLCHAIN} \
      -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
      ..

index_rdm

# Move out of build directory.
cd ..

