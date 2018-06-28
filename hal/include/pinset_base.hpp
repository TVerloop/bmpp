/* -*- mode: c++ -*- */
/**
 * @file    pinset_base.hpp
 * @author  T. Verloop <t93.verloop@gmail.com>
 * @version 0.1
 * @date    01-06-2018
 * @brief   General purpose I/O peripheral access interface.
 */

#ifndef BMPP_HAL_PINSET_BASE_HPP__
#define BMPP_HAL_PINSET_BASE_HPP__

/* System. */
#include <cstdint>          /* Fixed size integers.     */

/* Third-party. */


/* Local. */


namespace bmpp {

namespace hal {

/**
 *  Base class for pin type peripheral.
 *  @tparam Implmentation of the pinset this pin belongs to.
 */
template<class Pinset_impl>
class Pin_base {
public:

    /**
     *  Pin configurations.
     */
    enum class Config {
        input_floating,     /**< Input pin without pull-up/-down.   */
        input_analog,       /**< Analog input.                      */
        input_pull,         /**< Input with pull-up/-down           */
        output_pushpull,    /**< Output pin pull/push driven.       */
        output_opendrain    /**< Output pin opendrain driven.       */
    };

    /**
     *  Pin state.
     */
    enum class State {
        high = 1,   /**< Pin is in high state.  */
        low  = 0    /**< Pin is in low state.   */
    };

    /**
     *  Constructor.
     *  @param[in]  pinset  Pinset of which this pin belongs to.
     *  @param[in]  pin_nr  The pin number which this pin is in the set.
     *  @return None.
     */
    constexpr Pin_base(const Pinset_impl & pinset, const uint8_t& pin_nr);

    /**
     *  Configures pin for given configuration.
     *  @param[in]  config  Configuration to be set for this pin.
     *  @return None.
     */
    void config(const Config& config) const;

    /**
     *  sets the state of the pin.
     *  @param[in]  state   The state to set the pin in.
     *  @return None.
     **/
    void set(const State& state) const;

    /**
     *  returns the current state of the pin.
     *  @return The pin state.
     */
    State get() const;

private:

    const Pinset_impl& pinset;  /**< Reference to the Pinset.   */
    const uint8_t      pin_nr;  /**< Pin number in the set.     */

};

/**
 *  Base class for a pinset.
 *  @tparam Pinset_impl implementation of the pinset.
 */
template<class Pinset_impl>
class Pinset_base {
public:

    /**
     *  Pin type corresponding to this pinset.
     */
    using Pin = Pin_base<Pinset_impl>;

    /**
     *  Initializes the pinset.
     *  @return None.
     */
    void initialize() const;

    /**
     *  returns a pin object for a given pin number.
     *  @param[in]  pin Number of the pin to return.
     *  @return         Instance of the pin.
     */
    constexpr Pin get_pin(const uint8_t& pin) const;

    /**
     *  returns a pin object for a given pin number.
     *  @param[in]  pin Number of the pin to return.
     *  @return         Instance of the pin.
     */
    constexpr Pin operator[](const std::size_t& pin) const;

private:

    /**
     *  returns a reference to the derived class.
     *  @return         Reference to the derived class.
     */
    constexpr const Pinset_impl& derived() const;

};

/******************************************************************************/
/* Declarations.                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* Class Pin                                                                  */
/*----------------------------------------------------------------------------*/

template<class T>
constexpr Pin_base<T>::Pin_base(const T& pinset, const uint8_t& pin_nr) :
    pinset   {pinset},
    pin_nr   {pin_nr} {}

template<class T>
void Pin_base<T>::config(const Config& config) const {
    pinset.config_pin(pin_nr, config);
}

template<class T>
void Pin_base<T>::set(const State& state) const {
    pinset.set_pin_state(pin_nr, state);
}

template<class T>
typename Pin_base<T>::State Pin_base<T>::get() const {
    return pinset.get_pin_state(pin_nr);
}

/*----------------------------------------------------------------------------*/
/* Class Pinset                                                               */
/*----------------------------------------------------------------------------*/

template<class T>
void Pinset_base<T>::initialize() const {
    derived().initialize();
}

template<class T>
constexpr Pin_base<T> Pinset_base<T>::get_pin(const uint8_t& pin) const {
    return Pin(derived(), pin);
}

template<class T>
constexpr Pin_base<T> Pinset_base<T>::operator[](const std::size_t& pin) const {
    return Pin(derived(), pin);
}

template<class T>
constexpr const T& Pinset_base<T>::derived() const {
    return *static_cast<const T*>(this);
}


} /* namespace hal */

} /* namespace bmpp */

#endif /* BMPP_HAL_PINSET_BASE_HPP__ */
