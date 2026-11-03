#pragma once

#include <numbers>

#include "units.h"

namespace units::literals {

// 180_deg -> Angle{pi}
constexpr Angle operator""_deg(unsigned long long value) {
    return Angle{static_cast<double>(value) * std::numbers::pi / 180};
}

// 2_rad -> Angle{2.0}
constexpr Angle operator""_rad(unsigned long long value) {
    return Angle{static_cast<double>(value)};
}

// TODO: add the floating forms, so that 45.5_deg and 0.5_rad compile

}  // namespace units::literals
