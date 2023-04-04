// sizes.hpp

#ifndef SIZES_HPP
#define SIZES_HPP

#include <cstddef>

template <typename T, std::size_t N>
std::size_t size(T(&)[N]) {
    return N;
}

#endif