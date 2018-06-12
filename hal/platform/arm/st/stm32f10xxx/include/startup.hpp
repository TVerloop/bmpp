#ifndef BMPP_HAL_STM32F10XXX_STARTUP_HPP__
#define BMPP_HAL_STM32F10XXX_STARTUP_HPP__

extern "C" {

[[gnu::interrupt("IRQ")]]
void reset_handler();

}

#endif /* BMPP_HAL_STM32F10XXX_STARTUP_HPP__ */
