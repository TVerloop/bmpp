#include "flash.hpp"

namespace bmpp {

namespace hal {

namespace stm32f10xxx {

void Flash::set_latency(const uint8_t& latency) const {
    switch(latency) {
    case 0:
        acr = masked_write(acr, create_mask(3UL), 0UL, 0UL);
        break;
    case 1:
        acr = masked_write(acr, create_mask(3UL), 1UL, 0UL);
        break;
    case 2:
        acr = masked_write(acr, create_mask(3UL), 2UL, 0UL);
        break;
    }
}


} /* namespace stm32f10xxx */

} /* namespace hal */

} /* namespace bmpp */
