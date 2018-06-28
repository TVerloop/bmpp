/**
   @file vectors.cpp
   @author T. Verloop <t93.verloop@gmail.com>
   @version 0.1
   @date 15-05-2018
   @brief Interrupt vector table.

   @detail Contains a default definition for every interrupt. Theses defaults
   Can be overwritten by any other definition as these are all weak linked.
*/

#include <cstdint>
#include <array>
#include "stack.hpp"
#include "startup.hpp"
#include "interrupts.hpp"

namespace bmpp {

namespace hal {

namespace stm32f10xxx {

extern "C" {

void default_handler() {
    while(1) {
        __asm__("BKPT");
    }
}

}  /* extern "C" */

[[gnu::interrupt("IRQ"), gnu::alias("default_handler")]]
static void reserved_handler();

/**
   @brief  Vector table.
*/
[[gnu::used, gnu::section(".vectors")]]
const std::array<void(*)(), 76> irq_vector = {
    *reinterpret_cast<void (*)()>(cortex_m3::main_stack.end()),
    reset_handler,
    nmi_handler,
    hardfault_handler,
    memmanage_handler,
    busfault_handler,
    usagefault_handler,
    reserved_handler,
    reserved_handler,
    reserved_handler,
    reserved_handler,
    svcall_handler,
    reserved_handler,
    reserved_handler,
    pendsv_handler,
    systick_handler,
    wwdg_handler,
    pvd_handler,
    tamper_handler,
    rtc_handler,
    flash_handler,
    rcc_handler,
    exti0_handler,
    exti1_handler,
    exti2_handler,
    exti3_handler,
    exti4_handler,
    dma1_channel1_handler,
    dma1_channel2_handler,
    dma1_channel3_handler,
    dma1_channel4_handler,
    dma1_channel5_handler,
    dma1_channel6_handler,
    dma1_channel7_handler,
    adc1_2_handler,
    usb_hp_can_tx_handler,
    usb_lp_can_rx0_handler,
    can_rx1_handler,
    can_sce_handler,
    exti9_5_handler,
    tim1_brk_handler,
    tim1_up_handler,
    tim1_trg_com_handler,
    tim1_cc_handler,
    tim2_handler,
    tim3_handler,
    tim4_handler,
    i2c1_ev_handler,
    i2c1_er_handler,
    i2c2_ev_handler,
    i2c2_er_handler,
    spi1_handler,
    spi2_handler,
    usart1_handler,
    usart2_handler,
    usart3_handler,
    exti15_10_handler,
    rtc_alarm_handler,
    usb_wakeup_handler,
    tim8_brk_handler,
    tim8_up_handler,
    tim8_trg_com_handler,
    tim8_cc_handler,
    adc3_handler,
    fsmc_handler,
    sdio_handler,
    tim5_handler,
    spi3_handler,
    uart4_handler,
    uart5_handler,
    tim6_handler,
    tim7_handler,
    dma2_channel1_handler,
    dma2_channel2_handler,
    dma2_channel3_handler,
    dma2_channel4_5_handler
};

/**
   @} End of group Vectors.
 */

} /* namespace stm32f10xxx */

} /* namespace hal */

} /* namespace bmpp */
