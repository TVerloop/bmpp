/* -*- mode: c++ -*- */
/**
 * @file    gpio.hpp
 * @author  T. Verloop <t93.verloop@gmail.com>
 * @version 0.1
 * @date    04-06-2018
 * @brief   General purpose Input/Output.
 */

#ifndef BMPP_HAL_STM32F10XXX_GPIO_HPP__
#define BMPP_HAL_STM32F10XXX_GPIO_HPP__

/* System. */
#include <cstdint>

/* Third-party, */

/* Local. */
#include "mem_access.hpp"
#include "pinset_base.hpp"

namespace bmpp {

namespace hal {

namespace stm32f10xxx {

class Gpio : public Pinset_base<Gpio> {
public:

    static const uint32_t base_address = 0x4001'0800UL;
    static const uint32_t block_size = 0x400UL;

    explicit constexpr Gpio(const uint32_t& address);

    void initialize() const;
    void set_pin_state(const uint8_t& pin, const Pin::State& state) const;
    void config_pin(const uint8_t& pin, const Pin::Config& config) const;
    Pin::State get_pin_state(const uint8_t& pin) const;
    uint32_t get_identifier() const;

private:

    static const uint32_t pin_count = 15UL;

    const uint32_t address;

    /**
     *  Port configuration register low.
     *  Address offset: 0x00
     *  Reset value   : 0x4444'4444
     */
    Memory_register<Access_policy::read_write> crl;

    /**
     *  Port configuration register high.
     *  Address offset: 0x04
     *  Reset value   : 0x4444'4444
     */
    Memory_register<Access_policy::read_write> crh;

    /**
     *  Port input data register.
     *  Address offset: 0x08
     *  Reset value:    0x0000'XXXX
     */
    Memory_register<Access_policy::read_only> idr;

    /**
     *  Port output data register.
     *  Address offset: 0x0C
     *  Reset value:    0x0000'0000
     */
    Memory_register<Access_policy::read_write> odr;

    /**
     *  Port bit set/reset register.
     *  Address offset: 0x10
     *  Reset value:    0x0000'0000
     */
    Memory_register<Access_policy::write_only> bsrr;

    /**
     *  Port bit reset register.
     *  Address offset: 0x14
     *  Reset value:    0x0000'0000
     */
    Memory_register<Access_policy::write_only> brr;

    /**
     *  Port configuration lock register.
     *  Address offset: 0x18
     *  Reset value:    0x0000'0000
     */
    Memory_register<Access_policy::read_write> lckr;

};

constexpr Gpio::Gpio(const uint32_t & address) :
    address (address),
    crl     (address + 0x00UL),
    crh     (address + 0x04UL),
    idr     (address + 0x08UL),
    odr     (address + 0x0CUL),
    bsrr    (address + 0x10UL),
    brr     (address + 0x14UL),
    lckr    (address + 0x18UL) {

}

} /* namespace stm32f10xxx */

using Pinset = stm32f10xxx::Gpio;
using Pin = Pinset::Pin;

constexpr Pinset gpio_a(Pinset::base_address + (Pinset::block_size * 0x00UL));
constexpr Pinset gpio_b(Pinset::base_address + (Pinset::block_size * 0x01UL));
constexpr Pinset gpio_c(Pinset::base_address + (Pinset::block_size * 0x02UL));
constexpr Pinset gpio_d(Pinset::base_address + (Pinset::block_size * 0x03UL));
constexpr Pinset gpio_e(Pinset::base_address + (Pinset::block_size * 0x04UL));
constexpr Pinset gpio_f(Pinset::base_address + (Pinset::block_size * 0x05UL));
constexpr Pinset gpio_g(Pinset::base_address + (Pinset::block_size * 0x06UL));

} /* namespace hal */

} /* namespace bmpp */

#endif /* BMPP_HAL_STM32F10XXX_GPIO_HPP__ */
