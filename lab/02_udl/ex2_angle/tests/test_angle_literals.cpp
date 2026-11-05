#include <numbers>

#include <gtest/gtest.h>

#include "angle_literals.h"

using namespace units::literals;

constexpr double pi = std::numbers::pi;
constexpr double tolerance = 1e-12;

TEST(DegreesLiteral, IntegerForm) {
    EXPECT_NEAR((180_deg).radians, pi, tolerance);
    EXPECT_NEAR((90_deg).radians, pi / 2, tolerance);
    EXPECT_NEAR((0_deg).radians, 0.0, tolerance);
}

TEST(RadiansLiteral, IntegerForm) {
    EXPECT_NEAR((1_rad).radians, 1.0, tolerance);
    EXPECT_NEAR((3_rad).radians, 3.0, tolerance);
}

TEST(DegreesLiteral, FloatingForm) {
    FAIL() << "TODO: uncomment the assertions below, then add the floating form of _deg";
    // EXPECT_NEAR((45.5_deg).radians, 0.794124809657420, tolerance);
    // EXPECT_NEAR((180.0_deg).radians, pi, tolerance);
    // EXPECT_NEAR((1e-1_deg).radians, pi / 1800, tolerance);
}

TEST(RadiansLiteral, FloatingForm) {
    FAIL() << "TODO: uncomment the assertions below, then add the floating form of _rad";
    // EXPECT_NEAR((0.5_rad).radians, 0.5, tolerance);
    // EXPECT_NEAR((3.14159_rad).radians, 3.14159, tolerance);
}
