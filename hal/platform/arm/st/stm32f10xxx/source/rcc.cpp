#include <array>

#include "rcc.hpp"
#include "flash.hpp"

namespace bmpp {

namespace hal {

namespace stm32f10xxx {

void Rcc::set_clock(const uint32_t & hz) const {

    (void) hz;

    /* Enable Clock security system. */
    /* Enable HSE. */
    cr |= ((1UL << 19UL) | (1UL << 16UL));

    while(!(cr & (1UL << 17UL))) {
        /* Wait for HSE Ready. */
    }

    /* HSE as pll clock source. */
    /* Multiply by 6. */
    cfgr |= ((1U << 16U) | (4U << 18U));

    /* Enable PLL */
    cr |= (1UL << 24UL);

    while(!(cr & (1UL << 25UL))) {
        /* Wait for PLL Ready. */
    }

    /* Set flash latency to two wait states. */
    flash.set_latency(2);

    /* Set pll as main source. */
    cfgr |= 2U;
    while(!((cfgr & (3U << 2U)) & (2U << 2U))) {
        /* Wait for system clock to switch source. */
    }
}

void Rcc::enable_gpio(const uint8_t& port_nr) const {
    apb2enr |= (1UL << (port_nr + 2UL));
}

void Rcc::disable_gpio(const uint8_t & port_nr) const {
    apb2enr &= ~(1UL << (port_nr + 2UL));
}

} /* namespace stm32f10xxx */

} /* namespace hal */

} /* namespace bmpp */
