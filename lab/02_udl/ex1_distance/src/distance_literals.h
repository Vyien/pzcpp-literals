#pragma once

#include <stdexcept>

#include "units.h"

namespace units::literals {

// 5_m -> Distance{5.0}
inline Distance operator""_m(unsigned long long value) {
    (void)value;
    throw std::logic_error("TODO: implement operator\"\"_m");
}

// 2_km -> Distance{2000.0}
inline Distance operator""_km(unsigned long long value) {
    (void)value;
    throw std::logic_error("TODO: implement operator\"\"_km");
}

}  // namespace units::literals
