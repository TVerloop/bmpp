# -*- mode:CMake -*-
#==============================================================================#
# File:     CMakeLists.txt
# Author:   Tom Verloop   <T93.Verloop@gmail.com>
# Version:  0.1
# Date:     11-06-2018
#
# Cortex-M3 specific library.
#
#==============================================================================#

if(CMAKE_SYSTEM_NAME STREQUAL Generic)
  set(CORTEX_M3_AVAILABLE ON CACHE INTERNAL "Availability of Cortex-M3")
else()
  set(CORTEX_M3_AVAILABLE OFF CACHE INTERNAL "Availability of Cortex-M3")
  return()
endif()

#==============================================================================#
# Properties.
#==============================================================================#

#------------------------------------------------------------------------------#
# Main stack size.
#------------------------------------------------------------------------------#

define_property(TARGET
    PROPERTY
        CORTEX_M3_MAIN_STACK_SIZE
    BRIEF_DOCS "Size of the main stack."
    FULL_DOCS  "Size of the main stack."
)

#------------------------------------------------------------------------------#
# Process stack size.
#------------------------------------------------------------------------------#

define_property(TARGET
    PROPERTY
        CORTEX_M3_PROCESS_STACK_SIZE
    BRIEF_DOCS "Size of the process stack."
    FULL_DOCS  "Size of the process stack."
)

#==============================================================================#
# Cortex-M3
#==============================================================================#

#------------------------------------------------------------------------------#
# Library definition.
#------------------------------------------------------------------------------#

add_library(__CORTEX_M3 INTERFACE)
add_library(hal::arm::cortex_m3 ALIAS __CORTEX_M3)

#------------------------------------------------------------------------------#
# Source files.
#------------------------------------------------------------------------------#

target_sources(__CORTEX_M3
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/source/stack.cpp
)

#------------------------------------------------------------------------------#
# Include directories.
#------------------------------------------------------------------------------#

target_include_directories(__CORTEX_M3
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#------------------------------------------------------------------------------#
# Linked libraries.
#------------------------------------------------------------------------------#

#------------------------------------------------------------------------------#
# Compiler definitions.
#------------------------------------------------------------------------------#

target_compile_definitions(__CORTEX_M3
  INTERFACE
    CORTEX_M=3
    CORTEX_M3
)

#------------------------------------------------------------------------------#
# Compiler options.
#------------------------------------------------------------------------------#

target_compile_options(__CORTEX_M3
  INTERFACE
    -mfloat-abi=soft
    -mtune=cortex-m3
    -march=armv7-m
    -mthumb
)

#------------------------------------------------------------------------------#
# Linker options.
#------------------------------------------------------------------------------#

target_link_libraries(__CORTEX_M3
  INTERFACE
    -T${CMAKE_CURRENT_SOURCE_DIR}/link/cortex_m3.ld
    -Wl,--defsym=main_stack_size=$<TARGET_PROPERTY:CORTEX_M3_MAIN_STACK_SIZE>
    -Wl,--defsym=process_stack_size=$<TARGET_PROPERTY:CORTEX_M3_PROCESS_STACK_SIZE>
    -mfloat-abi=soft
    -mtune=cortex-m3
    -march=armv7-m
    -mthumb
)

#==============================================================================#
# EOF.
#==============================================================================#
