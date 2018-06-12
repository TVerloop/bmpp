# -*- mode:CMake -*-
#==============================================================================#
# File:     CMakeLists.txt
# Author:   Tom Verloop   <T93.Verloop@gmail.com>
# Version:  0.1
# Date:     08-06-2018
#
# Application Layer.
#
#==============================================================================#

function(bmpp_add_executable target ...)
  add_executable(${ARGV})

  add_custom_target(${target}.lss ALL
    COMMAND ${CMAKE_OBJDUMP} -S $<TARGET_FILE:${target}> > ${CMAKE_CURRENT_BINARY_DIR}/${target}.lss
    DEPENDS ${target}
    )
  add_custom_target(${target}.dmp ALL
    COMMAND ${CMAKE_OBJDUMP} -x --syms $<TARGET_FILE:${target}> > ${CMAKE_CURRENT_BINARY_DIR}/${target}.dmp
    DEPENDS ${target}
  )
  add_custom_target(${target}.hex ALL
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${target}> ${CMAKE_CURRENT_BINARY_DIR}/${target}.hex
    DEPENDS ${target}
  )
  add_custom_target(${target}.bin ALL
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${target}> ${CMAKE_CURRENT_BINARY_DIR}/${target}.bin
    DEPENDS ${target}
  )

  add_custom_command(TARGET ${target}
    POST_BUILD
      COMMAND size ARGS -B -t --common $<TARGET_FILE:${target}>
  )

  set_target_properties(${target}
    PROPERTIES
      SUFFIX
        .elf
  )

endfunction(bmpp_add_executable)

if(CORTEX_M3_AVAILABLE)

  bmpp_add_executable(STM32F103x8xx
    ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp
  )

  target_link_libraries(STM32F103x8xx
    PRIVATE
      hal::arm::st::stm32f103x8xx
      osal
  )

  set_target_properties(STM32F103x8xx
    PROPERTIES
      CORTEX_M3_MAIN_STACK_SIZE
        1k
      CORTEX_M3_PROCESS_STACK_SIZE
        0
        CXX_CLANG_TIDY
        clang-tidy;-checks=*;-warnings-as-errors
  )

  # include directories.
  target_include_directories(STM32F103x8xx
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/include
      ${CMAKE_CURRENT_SOURCE_DIR}/source
  )

endif()
