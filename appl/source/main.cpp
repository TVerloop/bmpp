/* -*- mode: c++ -*- */
/**
   @file main.cpp
   @author T. Verloop <t93.verloop@gmail.com>
   @version 0.1
   @date 01-06-2018
   @brief Entry point of the program.
*/

/******************************************************************************/
/* Includes.                                                                  */
/******************************************************************************/

/* System. */
#include <cstdint>

/* Third Party. */

/* Local. */
#include "gpio.hpp"

using namespace bmpp::hal;

int main() {

    gpio_a.initialize();

    auto pin = gpio_a[5];

    pin.config(Pin::Config::output_pushpull);

    while(true) {

        pin.set(Pin::State::high);

        for(volatile uint32_t i = 0; i < 100000; i++) {
            // Wait a bit.
        }

        pin.set(Pin::State::low);

        for(volatile uint32_t i = 0; i < 100000; i++) {
            // Wait a bit.
        }
    }

    return 0;
}
