#include "rcc.hpp"

namespace bmpp {

namespace hal {

namespace stm32f10xxx {

void Rcc::set_clock(const uint32_t & hz) const {

    /* Enable Clock security system. */
    /* Enable HSE. */
    cr |= ((1UL << 19UL) | (1UL << 16UL));

    while(!(cr & (1UL << 17UL))) {
        /* Wait for HSE Ready. */
    }

    /* Enable PLL */
    cr |= (1UL << 24UL);

    while(!(cr & (1UL << 25UL))) {
        /* Wait for PLL Ready. */
    }

    cfgr = masked_write(cfgr, 4UL, 3UL, 18UL);

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
