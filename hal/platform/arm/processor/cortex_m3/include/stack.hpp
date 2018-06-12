/* -*- mode:C++ -*- */
/**
 * @file mem_access.hpp
 * @author T. Verloop <t93.verloop@gmail.com>
 * @version 0.1
 * @date 01-06-2018
 * @brief utilities for accessing io Memory.
 */

/* System. */
#include <cstdint>
#include <type_traits>
#include <iterator>

/* Third-party. */


/* Local. */

#ifndef BMPP_HAL_CORTEX_M3_HPP__
#define BMPP_HAL_CORTEX_M3_HPP__

extern "C" {

extern const uint32_t __main_stack_start;
extern const uint32_t __main_stack_end;

extern const uint32_t __process_stack_start;
extern const uint32_t __process_stack_end;

}

namespace bmpp {

namespace hal {

namespace cortex_m3 {

uint32_t * get_msp();

uint32_t * get_psp();

template<typename T>
class Array_wrapper {
public:

    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator  = value_type*;
    using const_iterator = const value_type*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    constexpr Array_wrapper(const iterator begin, const iterator end);

/******************************************************************************/
/* Element access.                                                            */
/******************************************************************************/

    constexpr reference at(size_type pos) const;
    constexpr reference operator[](size_type pos) const;
    constexpr reference front() const;
    constexpr reference back() const;
    constexpr pointer data() const;

/******************************************************************************/
/* Iterators.                                                                 */
/******************************************************************************/

    constexpr iterator begin() const;
    constexpr iterator cbegin() const;

    constexpr iterator end() const;
    constexpr iterator cend() const;

    constexpr iterator rbegin() const;
    constexpr iterator crbegin() const;

    constexpr iterator rend() const;
    constexpr iterator crend() const;

/******************************************************************************/
/* Capacity.                                                                  */
/******************************************************************************/

    constexpr bool empty() const;
    constexpr size_type size() const;
    constexpr size_type max_size() const;

private:
    iterator const begin_;
    iterator const end_;

};


template<typename T>
constexpr Array_wrapper<T>::Array_wrapper(const iterator begin, const iterator end) :
    begin_(begin),
    end_(end) {

}

template<typename T>
constexpr typename Array_wrapper<T>::reference Array_wrapper<T>::at(size_type pos) const {
    return *begin_[pos];
}

template<typename T>
constexpr typename Array_wrapper<T>::reference Array_wrapper<T>::operator[](size_type pos) const {
    return *begin_[pos];
}

template<typename T>
constexpr typename Array_wrapper<T>::reference Array_wrapper<T>::front() const {
    return *begin_;
}

template<typename T>
constexpr typename Array_wrapper<T>::reference Array_wrapper<T>::back() const {
    return *(end_ - 1);
}

template<typename T>
constexpr typename Array_wrapper<T>::pointer Array_wrapper<T>::data() const {
    return begin_;
}

template<typename T>
constexpr typename Array_wrapper<T>::iterator Array_wrapper<T>::begin() const{
    return begin_;
}

template<typename T>
constexpr typename Array_wrapper<T>::iterator Array_wrapper<T>::cbegin() const {
    return begin_;
}

template<typename T>
constexpr typename Array_wrapper<T>::iterator Array_wrapper<T>::end() const {
    return end_;
}

template<typename T>
constexpr typename Array_wrapper<T>::iterator Array_wrapper<T>::cend() const {
    return end_;
}

template<typename T>
constexpr typename Array_wrapper<T>::iterator Array_wrapper<T>::rbegin() const {
    return reverse_iterator(end_);
}

template<typename T>
constexpr typename Array_wrapper<T>::iterator Array_wrapper<T>::crbegin() const {
    return reverse_iterator(end_);
}

template<typename T>
constexpr typename Array_wrapper<T>::iterator Array_wrapper<T>::rend() const {
    return reverse_iterator(begin_);
}

template<typename T>
constexpr typename Array_wrapper<T>::iterator Array_wrapper<T>::crend() const {
    return reverse_iterator(begin_);
}

template<typename T>
constexpr bool Array_wrapper<T>::empty() const {
    return (end_ - begin_);
}

template<typename T>
constexpr typename Array_wrapper<T>::size_type Array_wrapper<T>::size() const {
    return (end_ - begin_);
}

template<typename T>
constexpr typename Array_wrapper<T>::size_type Array_wrapper<T>::max_size() const {
    return size();
}

constexpr Array_wrapper<const uint32_t> main_stack(&__main_stack_start, &__main_stack_end);
constexpr Array_wrapper<const uint32_t> process_stack(&__main_stack_start, &__main_stack_end);

} /* cortex_m3 */

} /* hal */

} /* bmpp */

#endif /* BMPP_HAL_CORTEX_M3_HPP__ */
