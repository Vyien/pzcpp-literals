#pragma once

#include <cstdint>
#include <ostream>

namespace gfx {

// An RGB color, one byte per channel.
struct Color {
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
    friend constexpr bool operator==(Color, Color) = default;
};

// GoogleTest uses this to print colors in failure messages.
inline void PrintTo(Color c, std::ostream* os) {
    *os << "Color{" << int{c.r} << ", " << int{c.g} << ", " << int{c.b} << "}";
}

}  // namespace gfx
