/* -*- mode:C++ -*- */
/**
 * @file mem_access.hpp
 * @author T. Verloop <t93.verloop@gmail.com>
 * @version 0.1
 * @date 01-06-2018
 * @brief utilities for accessing io Memory.
 */

#ifndef BMPP_HAL_MEM_ACCESS_HPP__
#define BMPP_HAL_MEM_ACCESS_HPP__

/* System. */
#include <type_traits>      /* Compiletype type computation. */
#include <cstdint>          /* Fixed size integers. */

/* Third-party. */

/* Local. */


namespace bmpp {

namespace hal {

/**
 *  Describes the read/write acces policy.
 */
enum class Access_policy {
    read_only,                  /**< Read only access.      */
    write_only,                 /**< Write only access.     */
    read_write                  /**< Read and write access  */
};

/**
 * Writes a binary value masked by a given field and position.
 * @param[in] lhs       Left hand value.
 * @param[in] field     Bitfield used as mask.
 * @param[in] rhs       Right hand value.
 * @param[in] pos       Position used to shift field and rhs in place.
 * @return              Value of Lefthand value with righthand bitpatern overwritten.
 */
inline uint32_t masked_write(const uint32_t lhs, const uint32_t& field, const uint32_t rhs, const uint32_t& pos) {
    return ((lhs & ~(field << pos)) | ((rhs & field) << pos));
}

/**
 *  wrapper class for staticaly mapped Memory access.
 *  @tparam  Policy  Access policy.
 */
template<Access_policy Policy>
class Memory_register {
public:
    
    /**
     *  Constructor from 32bits integer.
     *  @param[in] address   Integer representative of the Memory address.
     */
    constexpr Memory_register(uint32_t address);

    /**
     *  Constructor from 32bits integer with aditional offset.
     *  @param[in] base_addess   Integer base address in which the Memory resides.
     *  @param[in] offset        Offset from the base address in which the Memory resides.
     */
    constexpr Memory_register(uint32_t base_address, uint32_t offset);

/*****************************************************************************/
/* Assignment operators                                                      */
/*****************************************************************************/
  
    /** 
     *  @{
     *  Assignment operator.
     *  @tparam      T   Type of righthand value.
     *  @param[in]   rhs righthand value.
     *  @return          Reference to lefthand value.
     */
    template<typename T>
    inline const Memory_register& operator=(const T& rhs) const;
    inline const Memory_register& operator=(const Memory_register& rhs) const;
    /** 
     *  @}
     */

    /**
     *  @{
     *  Add and assign operator.
     *  @tparam      T   Type of righthand value.
     *  @param[in]   rhs Righthand value.
     *  @return          Reference to lefthand value.
     */
    template<typename T>
    inline const Memory_register& operator+=(const T& rhs) const;
    inline const Memory_register& operator+=(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Substract and assign operator.
     *  @tparam      T   Type of righthand value.
     *  @param[in]   rhs Righthand value.
     *  @return          Reference to lefthand value.
     */
    template<typename T>
    inline const Memory_register& operator-=(const T& rhs) const;
    inline const Memory_register& operator-=(const Memory_register& rhs) const;
    /**
     * @}
     */

    /**
     *  @{
     *  Multiply and assign operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Reference to lefthand value.
     */
    template<typename T>
    inline const Memory_register& operator*=(const T& rhs) const;
    inline const Memory_register& operator*=(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Devide and assign operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Reference to lefthand value.
     */
    template<typename T>
    inline const Memory_register& operator/=(const T& rhs) const;
    inline const Memory_register& operator/=(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Modulo and assign operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Reference to lefthand value.
     */
    template<typename T>
    inline const Memory_register& operator%=(const T& rhs) const;
    inline const Memory_register& operator%=(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Bitwise AND and assign operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Reference to lefthand value.
     */
    template<typename T>
    inline const Memory_register& operator&=(const T& rhs) const;
    inline const Memory_register& operator&=(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Bitwise OR and assign operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Reference to lefthand value.
     */
    template<typename T>
    inline const Memory_register& operator|=(const T& rhs) const;
    inline const Memory_register& operator|=(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Bitwise XOR and assign operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Reference to lefthand value.
     */
    template<typename T>
    inline const Memory_register& operator^=(const T& rhs) const;
    inline const Memory_register& operator^=(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Leftshift and assign operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Reference to lefthand value.
     */
    template<typename T>
    inline const Memory_register& operator<<=(const T& rhs) const;
    inline const Memory_register& operator<<=(const Memory_register & rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Rightshift and assign operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Reference to lefthand value.
     */
    template<typename T>
    inline const Memory_register& operator>>=(const T& rhs) const;
    inline const Memory_register& operator>>=(const Memory_register & rhs) const;
    /**
     *  @}
     */

/*****************************************************************************/
/* In-/De-crement operators                                                  */
/*****************************************************************************/

    /**
     *  Pre-Increment operator.
     *  @return         Reference to lefthand value.
     */
    inline const Memory_register& operator++() const;

    /**
     *  Pre-Decrement operator.
     *  @return         Reference to lefthand value.
     */
    inline const Memory_register& operator--() const;

    /**
     *  Post-Increment operator.
     *  @return        Lefthand value before increment.
     */
    inline uint32_t operator++(int) const;

    /**
     *  Post-Decrement operator.
     *  @return        Righthand value before increment.
     */
    inline uint32_t operator--(int) const;

/*****************************************************************************/
/* Arithmetic operators                                                      */
/*****************************************************************************/

    /**
     *  @{
     *  Addition operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         lefthand value increased by righthand value.
     */
    template<typename T>
    inline uint32_t operator+(const T& rhs) const;
    inline uint32_t operator+(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Substraction operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         lefthand value decreased by righthand value.
     */
    template<typename T>
    inline uint32_t operator-(const T& rhs) const;
    inline uint32_t operator-(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Multiplication operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         lefthand value multiplied by righthand value.
     */
    template<typename T>
    inline uint32_t operator*(const T& rhs) const;
    inline uint32_t operator*(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Devision operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         lefthand value devided by righthand value.
     */
    template<typename T>
    inline uint32_t operator/(const T& rhs) const;
    inline uint32_t operator/(const Memory_register& rhs) const;
    /**
     *  @}
     */
    
    /**
     *  @{
     *  Modulo operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Remainder of lefthand value devided by righthand value.
     */
    template<typename T>
    inline uint32_t operator%(const T& rhs) const;
    inline uint32_t operator%(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  Bitwise NOT operator.
     *  @return         Bitwise inverted value.
     */
    inline uint32_t operator~() const;

    /**
     *  @{
     *  Bitwise AND operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Lefthand value bitwise AND'ed by righthand value.
     */
    template<typename T>
    inline uint32_t operator&(const T& rhs) const;
    inline uint32_t operator&(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Bitwise OR operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Lefthand value bitwise OR'ed by righthand value.
     */
    template<typename T>
    inline uint32_t operator|(const T& rhs) const;
    inline uint32_t operator|(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Bitwise XOR operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Lefthand value bitwise XOR'ed by righthand value.
     */
    template<typename T>
    inline uint32_t operator^(const T& rhs) const;
    inline uint32_t operator^(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Bitwise left shift operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Lefthand value bitwise left shifted by righthand value.
     */
    template<typename T>
    inline uint32_t operator<<(const T& rhs) const;
    inline uint32_t operator<<(const Memory_register& rhs) const;
    /**
     *  @}
     */
    
    /**
     *  @{
     *  Bitwise right shift operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Lefthand value bitwise right shifted by righthand value.
     */
    template<typename T>
    inline uint32_t operator>>(const T& rhs) const;
    inline uint32_t operator>>(const Memory_register& rhs) const;
    /**
     *  @}
     */

/*****************************************************************************/
/* Logical operators                                                         */
/*****************************************************************************/

    /**
     *  Negation operator.
     *  @return         Logicaly inverted value.
     */
    inline bool operator!() const;

    /**
     *  @{
     *  Logical AND operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Boolean value of lefthand value AND righthand value.
     */
    template<typename T>
    inline bool operator&&(const T& rhs) const;
    inline bool operator&&(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Logical Includive OR operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Boolean value of lefthand value AND righthand value.
     */
    template<typename T>
    inline bool operator||(const T& rhs) const;
    inline bool operator||(const Memory_register& rhs) const;
    /**
     *  @}
     */

/*****************************************************************************/
/* Comparison operators                                                      */
/*****************************************************************************/

    /**
     *  @{
     *  Equality operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Boolean value of lefthand value equal to righthand value.
     */
    template<typename T>
    inline bool operator==(const T& rhs) const;
    inline bool operator==(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Not equality operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Boolean value of lefthand value NOT equal to righthand value.
     */
    template<typename T>
    inline bool operator!=(const T& rhs) const;
    inline bool operator!=(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Less than operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Boolean value of lefthand value less than righthand value.
     */
    template<typename T>
    inline bool operator<(const T& rhs) const;
    inline bool operator<(const Memory_register& rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Greater than operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Boolean value of lefthand value greater than righthand value.
     */
    template<typename T>
    inline bool operator>(const T& rhs) const;
    inline bool operator>(const Memory_register & rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Less than or uqual operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Boolean value of lefthand value greater than righthand value.
     */
    template<typename T>
    inline bool operator<=(const T& rhs) const;
    inline bool operator<=(const Memory_register & rhs) const;
    /**
     *  @}
     */

    /**
     *  @{
     *  Greater than or uqual operator.
     *  @tparam     T   Type of righthand value.
     *  @param[in]  rhs Righthand value.
     *  @return         Boolean value of lefthand value greater than righthand value.
     */
    template<typename T>
    inline bool operator>=(const T& rhs) const;
    inline bool operator>=(const Memory_register & rhs) const;
    /**
     *  @}
     */

/*****************************************************************************/
/* Member access operators                                                   */
/*****************************************************************************/

    /**
     *  Address-of operator.
     *  @return         Pointer to memory register.
     */
    inline volatile uint32_t * operator&() const {
        return get_pointer();
    }

/*****************************************************************************/
/* Conversion operators                                                      */
/*****************************************************************************/

    /**
     *  Implicit conversion to volatile 32bit unsigned reference operator.
     *  @return         Pointer to memory register.
     */
    inline operator volatile uint32_t&() const {
        return get_reference();
    }
private:

    uint32_t address;   /**< Memory address which the object wraps. */

    /**
     *  Create pointer of the integer Memory address.
     *  @return Pointer to IO Memory.
     */
    inline volatile uint32_t* get_pointer() const;

    /**
     *  Creates a reference of the integer Memory address.
     *  @return reference to IO Memory.
     */
    inline volatile uint32_t& get_reference() const;
};

/******************************************************************************/
/* Definitions.                                                               */
/******************************************************************************/

template<Access_policy Policy>
constexpr Memory_register<Policy>::Memory_register(uint32_t address)
    : address { address } {

}

template<Access_policy Policy>
constexpr Memory_register<Policy>::Memory_register(uint32_t base_address, uint32_t offset)
    : address { base_address + offset } {

}


template<Access_policy Policy>
template<typename T>
const Memory_register<Policy>& Memory_register<Policy>::operator=(const T& rhs) const {
    get_reference() = rhs;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy> & Memory_register<Policy>::operator=(const Memory_register<Policy>& rhs) const {
    get_reference() = rhs.get_reference();
    return *this;
}

template<Access_policy Policy>
template<typename T>
inline const Memory_register<Policy>& Memory_register<Policy>::operator+=(const T& rhs) const {
    get_reference() += rhs;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator+=(const Memory_register<Policy>& rhs) const {
    get_reference() += rhs.get_reference();
    return *this;
}

template<Access_policy Policy>
template<typename T>
inline const Memory_register<Policy>& Memory_register<Policy>::operator-=(const T& rhs) const {
    get_reference() -= rhs;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator-=(const Memory_register<Policy>& rhs) const {
    get_reference() -= rhs.get_reference();
    return *this;
}

template<Access_policy Policy>
template<typename T>
inline const Memory_register<Policy>& Memory_register<Policy>::operator*=(const T& rhs) const {
    get_reference() *= rhs;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator*=(const Memory_register<Policy>& rhs) const {
    get_reference() *= rhs.get_reference();
    return *this;
}

template<Access_policy Policy>
template<typename T>
inline const Memory_register<Policy>& Memory_register<Policy>::operator/=(const T& rhs) const {
    get_reference() /= rhs;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator/=(const Memory_register<Policy>& rhs) const {
    get_reference() /= rhs.get_reference();
    return *this;
}

template<Access_policy Policy>
template<typename T>
inline const Memory_register<Policy>& Memory_register<Policy>::operator%=(const T& rhs) const {
    get_reference() %= rhs;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator%=(const Memory_register<Policy>& rhs) const {
    get_reference() %= rhs.get_reference();
    return *this;
}

template<Access_policy Policy>
template<typename T>
inline const Memory_register<Policy>& Memory_register<Policy>::operator&=(const T& rhs) const {
    get_reference() &= rhs;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator&=(const Memory_register<Policy>& rhs) const {
    get_reference() &= rhs.get_reference();
    return *this;
}

template<Access_policy Policy>
template<typename T>
inline const Memory_register<Policy>& Memory_register<Policy>::operator|=(const T& rhs) const {
    get_reference() |= rhs;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator|=(const Memory_register<Policy>& rhs) const {
    get_reference() |= rhs.get_reference();
    return *this;
}

template<Access_policy Policy>
template<typename T>
inline const Memory_register<Policy>& Memory_register<Policy>::operator^=(const T& rhs) const {
    get_reference() ^= rhs;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator^=(const Memory_register<Policy>& rhs) const {
    get_reference() ^= rhs.get_reference();
    return *this;
}

template<Access_policy Policy>
template<typename T>
inline const Memory_register<Policy>& Memory_register<Policy>::operator<<=(const T& rhs) const {
    get_reference() <<= rhs;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator<<=(const Memory_register<Policy>& rhs) const {
    get_reference() <<= rhs.get_reference();
    return *this;
}

template<Access_policy Policy>
template<typename T>
inline const Memory_register<Policy>& Memory_register<Policy>::operator>>=(const T& rhs) const {
    get_reference() >>= rhs;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator>>=(const Memory_register<Policy>& rhs) const {
    get_reference() >>= rhs.get_reference();
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator++() const {
    get_reference() += 1;
    return *this;
}

template<Access_policy Policy>
inline const Memory_register<Policy>& Memory_register<Policy>::operator--() const {
    get_reference() -= 1;
    return *this;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator++(int) const {
    uint32_t temp = get_reference();
    get_reference() += 1;
    return temp;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator--(int) const {
    uint32_t temp = get_reference();
    get_reference() -= 1;
    return temp;
}

template<Access_policy Policy>
template<typename T>
inline uint32_t Memory_register<Policy>::operator+(const T& rhs) const {
    return get_reference() + rhs;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator+(const Memory_register<Policy>& rhs) const {
    return get_reference() + rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline uint32_t Memory_register<Policy>::operator-(const T& rhs) const {
    return get_reference() - rhs;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator-(const Memory_register<Policy>& rhs) const {
    return get_reference() - rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline uint32_t Memory_register<Policy>::operator*(const T& rhs) const {
    return get_reference() * rhs;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator*(const Memory_register<Policy>& rhs) const {
    return get_reference() * rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline uint32_t Memory_register<Policy>::operator/(const T& rhs) const {
    return get_reference() / rhs;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator/(const Memory_register<Policy>& rhs) const {
    return get_reference() / rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline uint32_t Memory_register<Policy>::operator%(const T& rhs) const {
    return get_reference() % rhs;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator%(const Memory_register<Policy>& rhs) const {
    return get_reference() % rhs.get_reference();
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator~() const {
    return ~get_reference();
}

template<Access_policy Policy>
template<typename T>
inline uint32_t Memory_register<Policy>::operator&(const T& rhs) const {
    return get_reference() & rhs;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator&(const Memory_register<Policy>& rhs) const {
    return get_reference() & rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline uint32_t Memory_register<Policy>::operator|(const T& rhs) const {
    return get_reference() | rhs;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator|(const Memory_register<Policy>& rhs) const {
    return get_reference() | rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline uint32_t Memory_register<Policy>::operator^(const T& rhs) const {
    return get_reference() ^ rhs;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator^(const Memory_register<Policy>& rhs) const {
    return get_reference() ^ rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline uint32_t Memory_register<Policy>::operator<<(const T& rhs) const {
    return get_reference() << rhs;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator<<(const Memory_register<Policy>& rhs) const {
    return get_reference() << rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline uint32_t Memory_register<Policy>::operator>>(const T& rhs) const {
    return get_reference() >> rhs;
}

template<Access_policy Policy>
inline uint32_t Memory_register<Policy>::operator>>(const Memory_register<Policy>& rhs) const {
    return get_reference() >> rhs.get_reference();
}

template<Access_policy Policy>
inline bool Memory_register<Policy>::operator!() const {
    return !get_reference();
}

template<Access_policy Policy>
template<typename T>
inline bool Memory_register<Policy>::operator&&(const T& rhs) const {
    return get_reference() && rhs;
}

template<Access_policy Policy>
inline bool Memory_register<Policy>::operator&&(const Memory_register<Policy>& rhs) const {
    return get_reference() && rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline bool Memory_register<Policy>::operator||(const T& rhs) const {
    return get_reference() || rhs;
}

template<Access_policy Policy>
inline bool Memory_register<Policy>::operator||(const Memory_register<Policy>& rhs) const {
    return get_reference() || rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline bool Memory_register<Policy>::operator==(const T& rhs) const {
    return get_reference() == rhs;
}

template<Access_policy Policy>
inline bool Memory_register<Policy>::operator==(const Memory_register<Policy>& rhs) const {
    return get_reference() == rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline bool Memory_register<Policy>::operator!=(const T& rhs) const {
    return get_reference() != rhs;
}

template<Access_policy Policy>
inline bool Memory_register<Policy>::operator!=(const Memory_register<Policy>& rhs) const {
    return get_reference() != rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline bool Memory_register<Policy>::operator<(const T& rhs) const {
    return get_reference() < rhs;
}

template<Access_policy Policy>
inline bool Memory_register<Policy>::operator<(const Memory_register<Policy>& rhs) const {
    return get_reference() < rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline bool Memory_register<Policy>::operator>(const T& rhs) const {
    return get_reference() > rhs;
}

template<Access_policy Policy>
inline bool Memory_register<Policy>::operator>(const Memory_register<Policy>& rhs) const {
    return get_reference() > rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline bool Memory_register<Policy>::operator<=(const T& rhs) const {
    return get_reference() <= rhs;
}

template<Access_policy Policy>
inline bool Memory_register<Policy>::operator<=(const Memory_register<Policy>& rhs) const {
    return get_reference() <= rhs.get_reference();
}

template<Access_policy Policy>
template<typename T>
inline bool Memory_register<Policy>::operator>=(const T& rhs) const {
    return get_reference() >= rhs;
}

template<Access_policy Policy>
inline bool Memory_register<Policy>::operator>=(const Memory_register<Policy>& rhs) const {
    return get_reference() >= rhs.get_reference();
}

template<Access_policy Policy>
inline volatile uint32_t* Memory_register<Policy>::get_pointer() const {
    return reinterpret_cast<volatile uint32_t *>(address);
}

template<Access_policy Policy>
inline volatile uint32_t& Memory_register<Policy>::get_reference() const {
    return *get_pointer();
}

} /* namespace hal */

} /* namespace bmpp */


#endif /* BMPP_HAL_MEM_ACCESS_HPP__ */

/******************************************************************************/
/* EOF.                                                                       */
/******************************************************************************/
