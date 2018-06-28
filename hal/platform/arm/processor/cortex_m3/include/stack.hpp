/* -*- mode: c++ -*- */
/**
 * @file    stack.hpp
 * @author  T. Verloop <t93.verloop@gmail.com>
 * @version 0.1
 * @date    01-06-2018
 * @brief   utilities for accessing io Memory.
 */

#ifndef BMPP_HAL_CORTEX_M3_STACK_HPP__
#define BMPP_HAL_CORTEX_M3_STACK_HPP__

/* System. */
#include <cstdint>      /* Fixed size integers. */

/* Third-party. */


/* Local. */
#include "mem_access.hpp"

extern "C" {

extern const volatile uint32_t __main_stack_start;       /**< Start of main stack.      */
extern const volatile uint32_t __main_stack_end;         /**< End of main stack.        */

extern const volatile uint32_t __process_stack_start;    /**< Start of process stack.   */
extern const volatile uint32_t __process_stack_end;      /**< End of process stack.     */

} /* extern "C" */

namespace bmpp {

namespace hal {

namespace cortex_m3 {

/**
 *  Get pointer to main stack.
 *  @return Pointer to main stack.
 */
volatile uint32_t* get_msp();

/**
 *  Get pointer to process stack.
 *  @return Pointer to process stack.
 */
volatile uint32_t* get_psp();

constexpr Array_wrapper<const volatile uint32_t> main_stack(&__main_stack_start, &__main_stack_end);
constexpr Array_wrapper<const volatile uint32_t> process_stack(&__main_stack_start, &__main_stack_end);

} /* cortex_m3 */

} /* hal */

} /* bmpp */

#endif /* BMPP_HAL_CORTEX_M3_STACK_HPP__ */
