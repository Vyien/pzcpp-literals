#include <stdexcept>

#include <gtest/gtest.h>

#include "color_literal.h"

using gfx::Color;
using gfx::parse_hex_color;
using namespace gfx::literals;

TEST(ParseHexColor, ReadsLowerCaseDigits) {
    EXPECT_EQ(parse_hex_color("#ff8800"), (Color{255, 136, 0}));
    EXPECT_EQ(parse_hex_color("#000000"), (Color{0, 0, 0}));
    EXPECT_EQ(parse_hex_color("#0a1b2c"), (Color{10, 27, 44}));
}

TEST(ParseHexColor, ReadsUpperCaseDigits) {
    EXPECT_EQ(parse_hex_color("#FF8800"), (Color{255, 136, 0}));
    EXPECT_EQ(parse_hex_color("#C0FFEE"), (Color{192, 255, 238}));
}

TEST(ParseHexColor, ReadsEveryDigitRange) {
    EXPECT_EQ(parse_hex_color("#09afAF"), (Color{9, 175, 175}));
}

TEST(ParseHexColor, RejectsMissingHash) {
    EXPECT_THROW(parse_hex_color("ff88000"), std::invalid_argument);
}

TEST(ParseHexColor, RejectsWrongLength) {
    EXPECT_THROW(parse_hex_color("#fff"), std::invalid_argument);
    EXPECT_THROW(parse_hex_color("#ff88001"), std::invalid_argument);
    EXPECT_THROW(parse_hex_color("#"), std::invalid_argument);
}

TEST(ParseHexColor, RejectsNonHexDigits) {
    EXPECT_THROW(parse_hex_color("#ff88zz"), std::invalid_argument);
    EXPECT_THROW(parse_hex_color("#ff88g0"), std::invalid_argument);
    EXPECT_THROW(parse_hex_color("#ff88G0"), std::invalid_argument);
    EXPECT_THROW(parse_hex_color("#ff88/0"), std::invalid_argument);
    EXPECT_THROW(parse_hex_color("#ff88:0"), std::invalid_argument);
    EXPECT_THROW(parse_hex_color("#ff88@0"), std::invalid_argument);
    EXPECT_THROW(parse_hex_color("#ff88`0"), std::invalid_argument);
}

TEST(ColorLiteral, MatchesParser) {
    EXPECT_EQ("#ff8800"_rgb, (Color{255, 136, 0}));
    EXPECT_EQ("#C0FFEE"_rgb, (Color{192, 255, 238}));
}

TEST(ColorLiteral, WorksAtCompileTime) {
    FAIL() << "TODO: when the other tests pass, delete this line and uncomment the static_assert";
    // static_assert("#ff8800"_rgb == Color{255, 136, 0});
}
