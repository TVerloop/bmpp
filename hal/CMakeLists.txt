# -*- mode:CMake -*-
#==============================================================================#
# File:     CMakeLists.txt
# Author:   Tom Verloop   <T93.Verloop@gmail.com>
# Version:  0.1
# Date:     08-06-2018
#
# Hardware abstraction layer.
#
#==============================================================================#

#==============================================================================#
# Hardware Abstraction Layer
#==============================================================================#

#------------------------------------------------------------------------------#
# Library definition.
#------------------------------------------------------------------------------#

add_library(__HAL INTERFACE)
add_library(hal::hal ALIAS __HAL)

#------------------------------------------------------------------------------#
# Source files.
#------------------------------------------------------------------------------#

target_sources(__HAL
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/source/mem_access.cpp
)

#------------------------------------------------------------------------------#
# Include directories.
#------------------------------------------------------------------------------#

target_include_directories(__HAL
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#------------------------------------------------------------------------------#
# Linked libraries.
#------------------------------------------------------------------------------#

#------------------------------------------------------------------------------#
# Compiler definitions.
#------------------------------------------------------------------------------#

#------------------------------------------------------------------------------#
# Compiler options.
#------------------------------------------------------------------------------#

target_compile_options(__HAL
  INTERFACE
    -Wall                                       # All warnings.
    -Wextra                                     # Extra warnings.
    -Wchkp                                      # Invalid memory access warnings.
    -Wdouble-promotion                          # Implicit float to double promotion warnings.
    -Wnull-dereference                          # Null dereference warnings.
    -Wno-maybe-uninitialized                    # NO possibly uninitialized variable access warnings.
    -Wno-unused-local-typedefs                  # NO unused local typedef warnings.
    -Wno-unused-function                        # NO unused function warnings.
    -fdata-sections                             # Section per variable.
    -ffunction-sections                         # Section per function.
    -fomit-frame-pointer
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>  # Disable exception handling.
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>        # Disable runtime type information.
    $<$<CONFIG:Debug>:-Og>                      # Debug optimization.
    $<$<CONFIG:Debug>:-g>                       # Debug information.
    $<$<CONFIG:Debug>:-ggdb>                    # GDB Debug information.
    $<$<CONFIG:Release>:-Os>                    # Size optimization.
    $<$<CONFIG:Release>:-flto>                  # Link time optimization.
)

#------------------------------------------------------------------------------#
# Linker options.
#------------------------------------------------------------------------------#

target_link_libraries(__HAL
  INTERFACE
    -ffunction-sections                             # Section per function.
    -fdata-sections                                 # Section per variable.
    -fno-exceptions                                 # Disable exception handling.
    -fno-rtti                                       # Disable runtime type information.
    $<$<CONFIG:Debug>:-g>                           # Debug information.
    $<$<CONFIG:Debug>:-Og>                          # Debug optimization.
    $<$<CONFIG:Debug>:-ggdb>                        # GDB Debug information.
    $<$<CONFIG:Release>:-Os>                        # Size optimization.
    $<$<CONFIG:Release>:-flto>                      # Link time optimization.
    -Wl,-Map=$<TARGET_PROPERTY:NAME>.map            # Create symbol map.
    -Wl,--cref,--no-warn-mismatch
    $<$<CONFIG:Release>:-Wl,--gc-sections>   # Remove unused sections.
)



#------------------------------------------------------------------------------#
# Sub-directories.
#------------------------------------------------------------------------------#

add_subdirectory(platform)

#==============================================================================#
# EOF.
#==============================================================================#
