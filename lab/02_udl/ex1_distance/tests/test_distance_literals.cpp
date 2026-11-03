#include <gtest/gtest.h>

#include "distance_literals.h"

using units::Distance;
using namespace units::literals;

TEST(MetersLiteral, StoresMeters) {
    EXPECT_EQ((5_m).meters, 5.0);
    EXPECT_EQ((0_m).meters, 0.0);
    EXPECT_EQ((1'250_m).meters, 1250.0);
}

TEST(KilometersLiteral, ConvertsToMeters) {
    EXPECT_EQ((2_km).meters, 2000.0);
    EXPECT_EQ((1_km).meters, 1000.0);
}

TEST(DistanceLiterals, WorkTogether) {
    EXPECT_EQ(2_km, 2000_m);
    EXPECT_EQ(1_km + 500_m, 1500_m);
    EXPECT_EQ(3_km + 1_km, Distance{4000});
}
