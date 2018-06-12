# -*- mode:CMake -*-
#==============================================================================#
# File:     CMakeLists.txt
# Author:   Tom Verloop   <T93.Verloop@gmail.com>
# Version:  0.1
# Date:     11-06-2018
#
# Architecture specific libraries.
#
#==============================================================================#

if(CMAKE_SYSTEM_PROCESSOR STREQUAL ARM) # if processor is of ARM type.

  add_subdirectory(arm)

endif()

#==============================================================================#
# EOF.
#==============================================================================#
