/**
 * @file rcc.hpp
 * @author T. Verloop <t93.verloop@gmail.com>
 * @version 0.1
 * @date 04-06-2018
 * @brief Reset and clock control.
 */

#ifndef BMPP_HAL_STM32F10XXX_RCC_HPP__
#define BMPP_HAL_STM32F10XXX_RCC_HPP__

/* System. */
#include <cstdint>                      /* Fixed size integers. */

/* Third-party. */

/* Local. */
#include "mem_access.hpp"               /* Mapped memory access. */

namespace bmpp {

namespace hal {    

namespace stm32f10xxx {

class Rcc {
public:
 
    static const uint32_t base_address = 0x4002'1000;
 
    Rcc(const Rcc&) = delete;
    Rcc(Rcc&&) = delete;
    
    constexpr Rcc() : 
        cr        {base_address, 0x00},
        cfgr      {base_address, 0x04},
        cir       {base_address, 0x08},
        apb2rstr  {base_address, 0x0C},
        apb1rstr  {base_address, 0x10},
        ahbenr    {base_address, 0x14},
        apb2enr   {base_address, 0x18},
        apb1enr   {base_address, 0x1C},
        bdcr      {base_address, 0x20},
        csr       {base_address, 0x24} {}

    void set_clock(const uint32_t & hz) const;
    void enable_gpio(const uint8_t & port_nr) const;
    void disable_gpio(const uint8_t & port_nr) const;

private:

    Memory_register<Access_policy::read_write> cr;
    Memory_register<Access_policy::read_write> cfgr;
    Memory_register<Access_policy::read_write> cir;
    Memory_register<Access_policy::read_write> apb2rstr;
    Memory_register<Access_policy::read_write> apb1rstr;
    Memory_register<Access_policy::read_write> ahbenr;
    Memory_register<Access_policy::read_write> apb2enr;
    Memory_register<Access_policy::read_write> apb1enr;
    Memory_register<Access_policy::read_write> bdcr;
    Memory_register<Access_policy::read_write> csr;

};

} /* namespace stm32f10xx */

constexpr stm32f10xxx::Rcc rcc;

} /* namespace hal */

} /* namespace bmpp */
    

#endif /* BMPP_HAL_STM32F10XXX_RCC_HPP__ */
