#include "rcc.hpp"

namespace bmpp {

namespace hal {

namespace stm32f10xxx {

void Rcc::enable_gpio(uint8_t port_nr) const {
    apb2enr |= (1UL << (port_nr + 2UL));
}

void Rcc::disable_gpio(uint8_t port_nr) const {
    apb2enr &= ~(1UL << (port_nr + 2UL));
}

} /* namespace stm32f10xxx */

} /* namespace hal */

} /* namespace bmpp */
