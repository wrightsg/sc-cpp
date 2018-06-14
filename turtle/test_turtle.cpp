#include "gtest/gtest.h"

#include "turtle_mock.h"

TEST(turtle, pen_up)
{
    turtle_mock mock;
    EXPECT_CALL(mock, pen_up()).Times(::testing::AtLeast(1));

    mock.pen_up();
}