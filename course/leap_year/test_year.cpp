#include "gtest/gtest.h"

#include "year.h"

TEST(YearShould, not_be_leap_year_if_cannot_be_divided_by_4)
{
    ASSERT_FALSE(Year::isLeapYear(1));
}

TEST(YearShould, be_leap_year_if_can_be_divided_by_4)
{
    ASSERT_TRUE(Year::isLeapYear(8));
}

TEST(YearShould, not_be_leap_year_if_can_be_divided_by_100_and_not_by_400)
{
    ASSERT_FALSE(Year::isLeapYear(1000));
}

TEST(YearShould, be_leap_year_if_can_be_divided_by_100_and_by_400)
{
    ASSERT_TRUE(Year::isLeapYear(1600));
}