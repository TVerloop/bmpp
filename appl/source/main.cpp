/* -*- mode: c++ -*- */
/**
 * @file    main.cpp
 * @author  T. Verloop <t93.verloop@gmail.com>
 * @version 0.1
 * @date    01-06-2018
 * @brief   Entry point of the program.
 */

/******************************************************************************/
/* Includes.                                                                  */
/******************************************************************************/

/* System */
#include <cstdint>

/* Third Party */

/* Local */
#include "gpio.hpp"
#include "rcc.hpp"

using namespace bmpp::hal;

int main() {

    /* Set clock 48Mhz */
    rcc.set_clock(48'000'000UL);
    /* Initialize gpio port A */
    gpio_a.initialize();
    /* Get pin 5 op gpio port A */
    auto pin = gpio_a[5];
    /* Configure pin A5 to ouput using push pull drive */
    pin.config(Pin::Config::output_pushpull);

    while(true) {   /* Loop forever */

        /* Set pin high. */
        pin.set(Pin::State::high);
        /* Wait X */
        for(volatile uint32_t i = 0; i < 100000; i++) {
            // Wait a bit.
        }
        /* Set pin low. */
        pin.set(Pin::State::low);

        /* Wait X */
        for(volatile uint32_t i = 0; i < 100000; i++) {
            // Wait a bit.
        }
    }

    return 0;
}
