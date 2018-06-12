# -*- mode:CMake -*-
#==============================================================================#
# File:     CMakeLists.txt
# Author:   Tom Verloop   <T93.Verloop@gmail.com>
# Version:  0.1
# Date:     08-06-2018
#
# GCC arm toolchain.
#
#==============================================================================#

set(CMAKE_SYSTEM_NAME Generic)      # No Operating System.

set(CMAKE_SYSTEM_PROCESSOR ARM)     # ARM family compiler.

#------------------------------------------------------------------------------#
# Compiler tools.
#------------------------------------------------------------------------------#

set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
# C compiler.
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
# Assembler compiler.
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc -x with-assembler-with-cpp)

set(CMAKE_AR    arm-none-eabi-ar      CACHE INTERNAL "Archiver tool.")
set(OBJDUMP     arm-none-eabi-objdump CACHE INTERNAL "Objdump tool.")
set(OBJCOPY     arm-none-eabi-objcopy CACHE INTERNAL "Objcopy tool.")
set(SIZE        arm-none-eabi-size    CACHE INTERNAL "Size tool.")

# Alternative root to find filesystem items.
set(CMAKE_FIND_ROOT_PATH /usr/arm-none-eabi)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_EXE_LINKER_FLAGS_INIT "-nostartfiles")

set(CMAKE_CXX_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_DEBUG   "")
set(CMAKE_ASM_FLAGS_DEBUG "")

set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG")
set(CMAKE_C_FLAGS_RELEASE   "-DNDEBUG")
set(CMAKE_ASM_FLAGS_RELEASE "-DNDEBUG")
    
set(CMAKE_EXECUTABLE_SUFFIX ".elf" CACHE INTERNAL "Elf executable suffix.")
#==============================================================================#
# EOF
#==============================================================================#
