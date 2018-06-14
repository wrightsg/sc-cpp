#include "gtest/gtest.h"

TEST(hello_world, success)
{
    ASSERT_TRUE(true);
}

TEST(hello_world, failure)
{
    ASSERT_TRUE(false);
}
