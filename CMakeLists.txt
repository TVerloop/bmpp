# -*- mode: CMake -*-
#==============================================================================#
# File:     CMakeLists.txt
# Author:   Tom Verloop   <T93.Verloop@gmail.com>
# Version:  0.1
# Date:     08-06-2018
#
# Bare Metal Plus Plus
#
#==============================================================================#
cmake_minimum_required(VERSION 3.0)

project(BMPP
  VERSION
    0.1.0   # Version.
  LANGUAGES
    C       # C language.
    CXX     # C++ language.
    ASM     # Assembler language.
)

# always export compile commands database,
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable testing.
enable_testing()

#------------------------------------------------------------------------------#
# Hardware Abstraction Layer.
#------------------------------------------------------------------------------#

add_subdirectory(hal)

#------------------------------------------------------------------------------#
# Operating System Abstraction Layer.
#------------------------------------------------------------------------------#

add_subdirectory(osal)

#------------------------------------------------------------------------------#
# Application Layer.
#------------------------------------------------------------------------------#

add_subdirectory(appl)

#==============================================================================#
# EOF
#==============================================================================#
