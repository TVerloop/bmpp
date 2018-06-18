#ifndef BMPP_HAL_STM32F10XX_GPIO_HPP__
#define BMPP_HAL_STM32F10XX_GPIO_HPP__

#include <array>

#include "pinset_base.hpp"
#include "mem_access.hpp"

namespace bmpp {

namespace hal {

namespace stm32f10xxx {
  
class Gpio : public Pinset_base<Gpio> {
public:

    friend Pinset_base<Gpio>;
    friend Pin_base<Gpio>;

    static const uint32_t base_address = 0x4001'0800UL;
    static const uint32_t block_size = 0x400UL;

    constexpr Gpio(const uint32_t & address);

private:

    void Impl_initialize() const;
    void Impl_set_pin_state(const uint8_t& pin, const Pin::State& state) const;
    void Impl_config_pin(const uint8_t& pin, const Pin::Config& config) const;
    Pin::State Impl_get_pin_state(const uint8_t& pin) const;
    uint32_t Impl_get_identifier() const;

    Memory_register<Access_policy::read_write> crl;
    Memory_register<Access_policy::read_write> crh;
    Memory_register<Access_policy::read_only>  idr;
    Memory_register<Access_policy::read_write> odr;
    Memory_register<Access_policy::write_only> bsrr;
    Memory_register<Access_policy::write_only> brr;
    Memory_register<Access_policy::read_write> lckr;


    const uint32_t address;

};


constexpr Gpio::Gpio(const uint32_t & address) :
    crl     (address, 0x00UL),
    crh     (address, 0x04UL),
    idr     (address, 0x08UL),
    odr     (address, 0x0CUL),
    bsrr    (address, 0x10UL),
    brr     (address, 0x14UL),
    lckr    (address, 0x18UL),
    address (address) {

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
    
constexpr std::array<Pinset, 7> pin_sets = {
    gpio_a,
    gpio_b,
    gpio_c,
    gpio_d,
    gpio_e,
    gpio_f,
    gpio_g
};
  
} /* namespace hal */

} /* namespace bmpp */

#endif /* BMPP_HAL_STM32F10XX_GPIO_HPP__ */
