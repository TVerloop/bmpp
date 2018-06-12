#include "stack.hpp"

namespace bmpp {

namespace hal {

namespace cortex_m3 {

uint32_t * get_msp() {
    uint32_t * ptr;
    asm volatile ("MRS %0, msp\n" : "=r" (ptr));
    return ptr;
}

uint32_t * get_psp() {
    uint32_t * ptr;
    asm volatile ("MRS %0, psp\n" : "=r" (ptr));
    return ptr;
}

}

}

}
