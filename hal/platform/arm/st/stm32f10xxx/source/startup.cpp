#include <cstdint>

#include "startup.hpp"

extern uint8_t* __data_init_start;
extern uint8_t* __data_start;
extern uint8_t* __data_end;

extern uint8_t* __fastcode_init_start;
extern uint8_t* __fastcode_start;
extern uint8_t* __fastcode_end;

extern uint8_t* __bss_start;
extern uint8_t* __bss_end;

extern int main();

void reset_handler() {

    uint8_t* src = __data_init_start;
    uint8_t* dst = __data_start;
    uint8_t* end = __data_end;

    while(dst < end) {
        *dst = *src;
        dst++;
        src++;
    }

    src = __fastcode_init_start;
    dst = __fastcode_start;
    end = __fastcode_end;

    while(dst < end) {
        *dst = *src;
        dst++;
        src++;
    }

    for(dst = __bss_start; dst < __bss_end; dst++) {
        *dst = 0U;
    }

    main();

    while(true) {
        // Loop forever.
    }

}
