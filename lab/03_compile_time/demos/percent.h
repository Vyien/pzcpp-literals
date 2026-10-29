#pragma once

#include <stdexcept>

namespace demo {

struct Percent {
    unsigned value;
};

// Usable both at compile time and at run time; throws for values above 100.
constexpr Percent make_percent(unsigned long long v) {
    if (v > 100) {
        throw std::invalid_argument("percent out of range");
    }
    return Percent{static_cast<unsigned>(v)};
}

namespace literals {

// consteval: every call must be evaluated by the compiler,
// so a literal with a bad value is a compile error.
consteval Percent operator""_pct(unsigned long long v) { return make_percent(v); }

}  // namespace literals

}  // namespace demo
