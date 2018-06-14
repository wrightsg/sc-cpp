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

    void down (int times)
    {
        for (int n = 0; n < times; n++) {
            _turtle.pen_down();
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
    EXPECT_CALL(turtle, pen_down()).Times(42);

    turtle_user user(turtle);

    user.down(42);
}

TEST(turtle, get_x)
{
    turtle_mock turtle;
    int x = 0;

    ON_CALL(turtle, pen_up()).WillByDefault(::testing::Invoke([&x]{
        x++;
    }));
    ON_CALL(turtle, get_x()).WillByDefault(::testing::Invoke([&x]{
        return x;
    }));

    turtle.pen_up();
    turtle.pen_up();

    ASSERT_EQ(2, turtle.get_x());
}