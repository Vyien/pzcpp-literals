#pragma once

#include <cstddef>
#include <stdexcept>
#include <string_view>

#include "color.h"

namespace gfx {

// "#ff8800" -> Color{255, 136, 0}; digits may be lower or upper case.
// Anything else throws std::invalid_argument.
inline Color parse_hex_color(std::string_view text) {
    (void)text;
    throw std::logic_error("TODO: implement parse_hex_color");
}

namespace literals {

// "#ff8800"_rgb -> Color{255, 136, 0}; a malformed literal must not compile.
inline Color operator""_rgb(const char* text, std::size_t length) {
    (void)text;
    (void)length;
    throw std::logic_error("TODO: implement operator\"\"_rgb");
}

}  // namespace literals

}  // namespace gfx
