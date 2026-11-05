#include <chrono>
#include <stdexcept>
#include <type_traits>

#include <gtest/gtest.h>

#include "duration_literal.h"

using config::parse_duration;
using namespace std::literals;
using namespace config::literals;

TEST(ParseDuration, ReadsSingleUnit) {
    EXPECT_EQ(parse_duration("45s").count(), 45);
    EXPECT_EQ(parse_duration("90m").count(), 5400);
    EXPECT_EQ(parse_duration("10h").count(), 36000);
    EXPECT_EQ(parse_duration("0s").count(), 0);
}

TEST(ParseDuration, ReadsSeveralUnits) {
    EXPECT_EQ(parse_duration("1h30m").count(), 5400);
    EXPECT_EQ(parse_duration("2h5s").count(), 7205);
    EXPECT_EQ(parse_duration("1h1m1s").count(), 3661);
    EXPECT_EQ(parse_duration("12m345s").count(), 1065);
}

TEST(ParseDuration, RejectsEmptyText) {
    EXPECT_THROW(parse_duration(""), std::invalid_argument);
}

TEST(ParseDuration, RejectsUnitWithoutNumber) {
    EXPECT_THROW(parse_duration("h"), std::invalid_argument);
    EXPECT_THROW(parse_duration("1hm"), std::invalid_argument);
}

TEST(ParseDuration, RejectsNumberWithoutUnit) {
    EXPECT_THROW(parse_duration("10"), std::invalid_argument);
    EXPECT_THROW(parse_duration("1h30"), std::invalid_argument);
}

TEST(ParseDuration, RejectsUnknownUnit) {
    EXPECT_THROW(parse_duration("1x"), std::invalid_argument);
    EXPECT_THROW(parse_duration("5H"), std::invalid_argument);
    EXPECT_THROW(parse_duration("1h 30m"), std::invalid_argument);
}

TEST(DurationLiteral, MatchesParser) {
    static_assert(std::is_same_v<decltype("1s"_dur), std::chrono::seconds>);
    EXPECT_EQ(("1h30m"_dur).count(), 5400);
    EXPECT_EQ(("45s"_dur).count(), 45);
}

TEST(DurationLiteral, WorksAtCompileTime) {
    FAIL() << "TODO: when the other tests pass, delete this line and uncomment the static_assert";
    // static_assert("1h30m"_dur == 90min);
}
