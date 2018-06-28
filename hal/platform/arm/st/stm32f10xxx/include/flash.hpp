#ifndef BMPP_HAL_STM32F10XXX_FLASH_HPP__
#define BMPP_HAL_STM32F10XXX_FLASH_HPP__

#include "mem_access.hpp"

namespace bmpp {

namespace hal {

namespace stm32f10xxx {

class Flash {
public:

    static const uint32_t base_address = 0x4002'2000;   /**< Base address of peripheral. */

    constexpr Flash();

    void set_latency(const uint8_t& latency) const;

private:

    Memory_register<Access_policy::read_write> acr;     /**< Access control register.   */
    Memory_register<Access_policy::write_only> keyr;    /**< PEC key register.          */
    Memory_register<Access_policy::write_only> optkeyr; /**< OPT key register.          */
    Memory_register<Access_policy::read_write> sr;      /**< Status register.           */
    Memory_register<Access_policy::read_write> cr;      /**< Control register.          */
    Memory_register<Access_policy::write_only> ar;      /**< Address register.          */
                                                        /*   Reserved.                  */
    Memory_register<Access_policy::read_only> obr;      /**< Option byte register       */
    Memory_register<Access_policy::read_only> wrpr;     /**< Write protection register. */

};


constexpr Flash::Flash() :
    acr     (base_address + 0x00),
    keyr    (base_address + 0x04),
    optkeyr (base_address + 0x08),
    sr      (base_address + 0x0C),
    cr      (base_address + 0x10),
    ar      (base_address + 0x14),
    /* Reserved             0x18 */
    obr     (base_address + 0x1C),
    wrpr    (base_address + 0x20) {

}

} /* namespace stm32f10xxx */

constexpr stm32f10xxx::Flash flash;

} /* namespace hal */

} /* namespace bmpp */

#endif /* BMPP_HAL_STM32F10XXX_FLASH_HPP__ */
