#include <stdexcept>

#include <gtest/gtest.h>

#include "percent.h"

using namespace demo::literals;

TEST(PercentLiteral, CreatesValidValues) {
    EXPECT_EQ((0_pct).value, 0u);
    EXPECT_EQ((23_pct).value, 23u);
    EXPECT_EQ((100_pct).value, 100u);
}

// A bad literal does not compile, so the error path is tested
// through the constexpr function, called at run time.
TEST(MakePercent, RejectsValuesAbove100) {
    EXPECT_THROW(demo::make_percent(101), std::invalid_argument);
    EXPECT_THROW(demo::make_percent(150), std::invalid_argument);
}
