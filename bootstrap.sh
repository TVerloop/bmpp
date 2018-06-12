# /bin/bash

POSITIONAL=()
BUILD_DIR=build
BUILD_TYPE=Release
TOOLCHAIN=gcc-arm-none-eabi.cmake

while [[ $# -gt 0 ]]; do

    key="$1"

    case $key in
        -d|--build-dir)
            BUILD_DIR="$2"
            shift
            shift
            ;;
        -b|--build-type)
            BUILD_TYPE="$2"
            shift
            shift
            ;;
        -t|--toolchain)
            TOOLCHAIN="$2"
            shift;
            shift;
            ;;
        *)
            POSITIONAL+=("$1")
            shift
            ;;
    esac
done

set -- "${POSITIONAL[@]}"

if [ ! -d ${BUILD_DIR} ]; then
    mkdir ${BUILD_DIR}
fi

cd ${BUILD_DIR}

cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/${TOOLCHAIN} -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

cd ..

ln -sfr ${BUILD_DIR}/compile_commands.json compile_commands.json
