#include <chrono>

#include <gtest/gtest.h>

#include "speed.h"

using units::Distance;
using namespace std::literals;
using namespace units::literals;

constexpr double tolerance = 1e-9;

TEST(KmhLiteral, IntegerForm) {
    EXPECT_NEAR((36_kmh).meters_per_second, 10.0, tolerance);
    EXPECT_NEAR((0_kmh).meters_per_second, 0.0, tolerance);
}

TEST(KmhLiteral, FloatingForm) {
    EXPECT_NEAR((3.6_kmh).meters_per_second, 1.0, tolerance);
    EXPECT_NEAR((72.5_kmh).meters_per_second, 20.138888888889, tolerance);
}

TEST(DistanceOverTime, Seconds) {
    EXPECT_NEAR((Distance{100} / 8s).meters_per_second, 12.5, tolerance);
}

TEST(DistanceOverTime, Hours) {
    EXPECT_NEAR((Distance{100'000} / 2h).meters_per_second, 13.888888888889, tolerance);
}

TEST(DistanceOverTime, Milliseconds) {
    EXPECT_NEAR((Distance{3} / 1500ms).meters_per_second, 2.0, tolerance);
}

TEST(DistanceOverTime, FloatingPointDuration) {
    EXPECT_NEAR((Distance{3000} / 2.5min).meters_per_second, 20.0, tolerance);
}

TEST(SpeedLiterals, MatchDistanceOverTime) {
    EXPECT_NEAR((Distance{100'000} / 2h).meters_per_second, (50_kmh).meters_per_second, tolerance);
    EXPECT_NEAR((Distance{1500} / 90s).meters_per_second, (60_kmh).meters_per_second, tolerance);
}
