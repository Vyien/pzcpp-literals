#pragma once

#include <ostream>

// Strong unit types shared by the exercises of 02_udl.
// Each type wraps one value in a base unit; there is no implicit
// conversion from a plain number.
namespace units {

struct Distance {
    double meters;
    friend constexpr bool operator==(Distance, Distance) = default;
};

constexpr Distance operator+(Distance a, Distance b) { return Distance{a.meters + b.meters}; }

struct Angle {
    double radians;
    friend constexpr bool operator==(Angle, Angle) = default;
};

// GoogleTest uses these to print values in failure messages.
inline void PrintTo(Distance d, std::ostream* os) { *os << d.meters << " m"; }
inline void PrintTo(Angle a, std::ostream* os) { *os << a.radians << " rad"; }

}  // namespace units
