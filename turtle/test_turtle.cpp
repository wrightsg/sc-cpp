#include "gtest/gtest.h"

#include "turtle_mock.h"

class turtle_user
{
public:
    explicit turtle_user (turtle_interface& turtle)
        : _turtle(turtle)
    {
    }

    void up (int times)
    {
        for (int n = 0; n < times; n++) {
            _turtle.pen_up();
        }
    }

private:
    turtle_interface& _turtle;
};

TEST(turtle, pen_up)
{
    turtle_mock turtle;
    EXPECT_CALL(turtle, pen_up()).Times(::testing::AtLeast(1));

    turtle_user user(turtle);

    user.up(2);
}

TEST(turtle, pen_down)
{
    turtle_mock turtle;
    EXPECT_CALL(turtle, pen_down()).Times(::testing::AtLeast(1));

    turtle_user user(turtle);

    user.up(1);
}