#pragma once

#include <chrono>
#include <cstddef>
#include <stdexcept>
#include <string_view>

namespace config {

// "1h30m" -> 5400s: one or more <digits><unit> tokens, unit h, m or s.
// Anything else throws std::invalid_argument.
inline std::chrono::seconds parse_duration(std::string_view text) {
    (void)text;
    throw std::logic_error("TODO: implement parse_duration");
}

namespace literals {

// "1h30m"_dur -> 5400s; a malformed literal must not compile.
inline std::chrono::seconds operator""_dur(const char* text, std::size_t length) {
    (void)text;
    (void)length;
    throw std::logic_error("TODO: implement operator\"\"_dur");
}

}  // namespace literals

}  // namespace config
