#ifndef BMPP_HAL_STM32F10XXX_INTERRUPTS_HPP__
#define BMPP_HAL_STM32F10XXX_INTERRUPTS_HPP__

#include <cstdint>

namespace bmpp {

namespace hal {

namespace stm32f10xxx {

/**
 *  Non Maskable Interrupt handler.
 *  Addr 0x0000'0008
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void nmi_handler();

/**
 *  All class of fault handler.
 *  Address: 0x0000'000C
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void hardfault_handler();

/**
 *  Memory management interrupt handler.
 *  Address: 0x0000'0010
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void memmanage_handler();

/**
 *  Pre-fetch fault, memory access fault handler.
 *  Address: 0x0000'0014
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void busfault_handler();

/**
 *  Undefined instruction or illigal state fault handler.
 *  Address: 0x0000'0018
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void usagefault_handler();

/**
 *  System service call handler.
 *  Address: 0x0000'002C
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void svcall_handler();

/**
 * Debug Monitor Interrupt handler.
 * Address: 0x0000'0030
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void debug_monitor_handler();

/**
 *  Pendable request for system service handler.
 *  Address: 0x0000'0038
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void pendsv_handler();

/**
 *  System tick timer interrupt handler.
 *  Address: 0x0000'003C
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void systick_handler();

/**
 *  Window Watchdog interrupt handler.
 *  Address: 0x0000'0040
 *  IRQ0
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void wwdg_handler();

/**
 *  PVD through IXTI Line detection interrupt handler.
 *  Address: 0x0000'0044
 *  IRQ1
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void pvd_handler();

/**
 *  tamper interrupt handler.
 *  Address: 0x0000'0048
 *  IRQ2
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tamper_handler();

/**
 *  Real Time Clock interrupt handler.
 *  Address: 0x0000'004C
 *  IRQ3
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void rtc_handler();

/**
 *  Flash global interrupt handler.
 *  Address: 0x0000'0050
 *  IRQ4
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void flash_handler();

/**
 *  RCC global interrupt handler.
 *  Address: 0x0000'0054
 *  IRQ5
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void rcc_handler();

/**
 *  EXTI0 global interrupt handler.
 *  Address: 0x0000'0058
 *  IRQ6
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void exti0_handler();

/**
 *  EXTI1 global interrupt handler.
 *  Address: 0x0000'005C
 *  IRQ7
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void exti1_handler();

/**
 *  EXTI2 global interrupt handler.
 *  Address: 0x0000'0060
 *  IRQ8
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void exti2_handler();

/**
 *  EXTI3 global interrupt handler.
 *  Address: 0x0000'0064
 *  IRQ9
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void exti3_handler();

/**
 *  EXTI4 global interrupt handler.
 *  Address: 0x0000'0068
 *  IRQ10
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void exti4_handler();

/**
 *  DMA1 Channel 1 global interrupt handler.
 *  Address: 0x0000'006C
 *  IRQ11
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void dma1_channel1_handler();

/**
 *  DMA1 Channel 2 global interrupt handler.
 *  Address: 0x0000'0070
 *  IRQ12
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void dma1_channel2_handler();

/**
 *  DMA1 Channel 3 global interrupt handler.
 *  Address: 0x0000'0074
 *  IRQ13
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void dma1_channel3_handler();

/**
 *  DMA1 Channel 4 global interrupt handler.
 *  Address: 0x0000'0078
 *  IRQ14
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void dma1_channel4_handler();

/**
 *  DMA1 Channel 5 global interrupt handler.
 *  Address: 0x0000'007C
 *  IRQ15
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void dma1_channel5_handler();

/**
 *  DMA1 Channel 6 global interrupt handler.
 *  Address: 0x0000'0080
 *  IRQ16
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void dma1_channel6_handler();

/**
 *  DMA1 Channel 7 global interrupt handler.
 *  Address: 0x0000'084
 *  IRQ17
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void dma1_channel7_handler();

/**
 *  ADC 1 & 2 global interrupt handler.
 *  Address: 0x0000'0088
 *  IRQ18
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void adc1_2_handler();

/**
 *  USB high priority and CAN TX interrupt handler.
 *  Address: 0x0000'008C
 *  IRQ19
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void usb_hp_can_tx_handler();

/**
 *  USB low priority and CAN RX0 interrupt handler.
 *  Address: 0x0000'0090
 *  IRQ20
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void usb_lp_can_rx0_handler();

/**
 *  CAN RX1 interrupt handler.
 *  Address: 0x0000'0094
 *  IRQ21
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void can_rx1_handler();

/**
 *  CAN SCE interrupt handler.
 *  Address: 0x0000'0098
 *  IRQ22
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void can_sce_handler();

/**
 *  EXTI Line [9:5] interrupt handler.
 *  Address: 0x0000'009C
 *  IRQ23
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void exti9_5_handler();

/**
 *  TIM1 break interrupt handler.
 *  Address: 0x0000'00A0
 *  IRQ24
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim1_brk_handler();

/**
 *  TIM1 update interrupt handler.
 *  Address: 0x0000'00A4
 *  IRQ25
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim1_up_handler();

/**
 *  TIM1 Trigger and Commutation interrupt handler.
 *  Address: 0x0000'00A8
 *  IRQ26
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim1_trg_com_handler();

/**
 *  TIM1 capture compare interrupt handler.
 *  Address: 0x0000'00AC
 *  IRQ27
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim1_cc_handler();

/**
 *  TIM2 global interrupt handler.
 *  Address: 0x0000'00B0
 *  IRQ28
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim2_handler();

/**
 *  TIM3 global interrupt handler.
 *  Address: 0x0000'00B4
 *  IRQ29
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim3_handler();

/**
 *  TIM4 global interrupt handler.
 *  Address: 0x0000'00B8
 *  IRQ30
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim4_handler();

/**
 *  I2C1 event interrupt handler.
 *  Address: 0x0000'00BC
 *  IRQ31
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void i2c1_ev_handler();

/**
 *  I2C1 error interrupt handler.
 *  Address: 0x0000'00C0
 *  IRQ32
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void i2c1_er_handler();

/**
 *  I2C2 event interrupt handler.
 *  Address: 0x0000'00C4
 *  IRQ33
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void i2c2_ev_handler();

/**
 *  I2C2 error interrupt handler.
 *  Address: 0x0000'00C8
 *  IRQ34
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void i2c2_er_handler();

/**
 *  SPI1 global interrupt handler.
 *  Address: 0x0000'00CC
 *  IRQ35
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void spi1_handler();

/**
 *  SPI2 global interrupt handler.
 *  Address: 0x0000'00D0
 *  IRQ36
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void spi2_handler();

/**
 *  USART1 global interrupt handler.
 *  Address: 0x0000'00D4
 *  IRQ37
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void usart1_handler();

/**
 *  USART2 global interrupt handler.
 *  Address: 0x0000'00D8
 *  IRQ38
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void usart2_handler();

/**
 *  USART3 global interrupt handler.
 *  Address: 0x0000'00DC
 *  IRQ39
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void usart3_handler();

/**
 *  EXTI Line [15:10] interrupt handler.
 *  Address: 0x0000'00E0
 *  IRQ40
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void exti15_10_handler();

/**
 *  Realtime clock alarm interrupt handler.
 *  Address: 0x0000'00E4
 *  IRQ41
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void rtc_alarm_handler();

/**
 *  USB wakeup through EXTI line interrupt handler.
 *  Address: 0x0000'00E8
 *  IRQ42
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void usb_wakeup_handler();

/**
 *  TIM8 Break interrupt handler.
 *  Address: 0x0000'00EC
 *  IRQ43
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim8_brk_handler();

/**
 *  TIM8 update interrupt handler.
 *  Address: 0x0000'00F0
 *  IRQ44
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim8_up_handler();

/**
 *  TIM8 trigger and commutation interrupt handler.
 *  Address: 0x0000'00F4
 *  IRQ45
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim8_trg_com_handler();

/**
 *  TIM8 capture compare interrupt handler.
 *  Address: 0x0000'00F8
 *  IRQ46
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim8_cc_handler();

/**
 *  ADC3 global interrupt handler.
 *  Address: 0x0000'00FC
 *  IRQ47
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void adc3_handler();

/**
 *  FSMC global interrupt handler.
 *  Address: 0x0000'0100
 *  IRQ48
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void fsmc_handler();

/**
 *  sdio global interrupt handler.
 *  Address: 0x0000'0104
 *  IRQ49
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void sdio_handler();

/**
 *  TIM5 global interrupt handler.
 *  Address: 0x0000'0108
 *  IRQ50
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim5_handler();

/**
 *  SPI3 global interrupt handler.
 *  Address: 0x0000'010C
 *  IRQ51
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void spi3_handler();

/**
 *  UART4 global interrupt handler.
 *  Address: 0x0000'0110
 *  IRQ52
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void uart4_handler();

/**
 *  UART5 global interrupt handler.
 *  Address: 0x0000'0114
 *  IRQ53
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void uart5_handler();

/**
 *  TIM6 global interrupt handler.
 *  Address: 0x0000'0118
 *  IRQ54
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim6_handler();

/**
 *  TIM7 global interrupt handler.
 *  Address: 0x0000'011C
 *  IRQ55
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void tim7_handler();

/**
 *  DMA2 Channel 1 global interrupt handler.
 *  Address: 0x0000'0120
 *  IRQ56
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void dma2_channel1_handler();

/**
 *  DMA2 Channel 2 global interrupt handler.
 *  Address: 0x0000'0124
 *  IRQ57
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void dma2_channel2_handler();

/**
 *  DMA2 Channel 3 global interrupt handler.
 *  Address: 0x0000'0128
 *  IRQ58
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void dma2_channel3_handler();

/**
 *  DMA2 Channel 4 & 5 global interrupt handler.
 *  Address: 0x0000'012C
 *  IRQ59
 */
[[gnu::interrupt("IRQ"), gnu::weak, gnu::alias("default_handler")]]
void dma2_channel4_5_handler();


} /* namespace stm32f10xxx */

} /* namespace hal */

} /* namespace bmpp */

#endif /* BMPP_HAL_STM32F10XXX_INTERRUPTS_HPP__ */
