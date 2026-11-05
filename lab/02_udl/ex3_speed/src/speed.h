#pragma once

#include <chrono>
#include <stdexcept>

#include "units.h"

namespace units {

// Distance{100} / 8s -> Speed{12.5}; accepts any std::chrono duration
template <class Rep, class Period>
Speed operator/(Distance distance, std::chrono::duration<Rep, Period> time) {
    (void)distance;
    (void)time;
    throw std::logic_error("TODO: implement operator/(Distance, duration)");
}

namespace literals {

// 36_kmh -> Speed{10.0}
inline Speed operator""_kmh(unsigned long long value) {
    (void)value;
    throw std::logic_error("TODO: implement operator\"\"_kmh (integer form)");
}

// 72.5_kmh -> Speed{20.13...}
inline Speed operator""_kmh(long double value) {
    (void)value;
    throw std::logic_error("TODO: implement operator\"\"_kmh (floating form)");
}

}  // namespace literals

}  // namespace units
