#include "gpio.hpp"
#include "rcc.hpp"

namespace bmpp {

namespace hal {

namespace stm32f10xxx {

void Gpio::Impl_initialize() const {
    rcc.enable_gpio((address - Gpio::base_address) / Gpio::block_size);
}

void Gpio::Impl_set_pin_state(const uint8_t& pin, const Pin::State& state) const {
    odr = masked_write(odr, 1UL, static_cast<uint32_t>(state), pin);
}

void Gpio::Impl_config_pin(const uint8_t& pin, const Pin::Config& config) const {
    volatile uint32_t & cfg_reg = pin > 7UL ? crh : crl;
    uint8_t pin_nr = pin % 8UL;
    switch(config) {
    case Pin::Config::output_pushpull:
        cfg_reg = masked_write(cfg_reg, 15UL, 2UL, (pin_nr * 4UL));
        break;
    case Pin::Config::output_opendrain:
        cfg_reg = masked_write(cfg_reg, 15UL, 6UL, (pin_nr * 4UL));
        break;
    case Pin::Config::input_analog:
        cfg_reg = masked_write(cfg_reg, 15UL, 0UL, (pin_nr * 4UL));
        break;
    case Pin::Config::input_floating:
        cfg_reg = masked_write(cfg_reg, 15UL, 4UL, (pin_nr * 4UL));
        break;
    case Pin::Config::input_pull:
        cfg_reg = masked_write(cfg_reg, 15UL, 8UL, (pin_nr * 4UL));
        break;
    }
}

Gpio::Pin::State Gpio::Impl_get_pin_state(const uint8_t& pin) const {
    return static_cast<Pin::State>((idr >> pin) & 1U);
}

uint32_t Gpio::Impl_get_identifier() const {
    return (address - Gpio::base_address) / Gpio::block_size;
}

} /* namespace stm32f10xx */

} /* namespace hal */

} /* namespace bmpp */
