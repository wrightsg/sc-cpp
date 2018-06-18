#include "gtest/gtest.h"

#include "stack.h"

TEST(MyStackShould, throw_an_exception_if_popped_when_empty)
{
    Stack<int> stack;

    ASSERT_THROW(stack.pop(), std::exception);
}

TEST(MyStackShould, pop_last_element_pushed)
{
    Stack<int> stack;

    stack.push(42);

    ASSERT_EQ(42, stack.pop());
}

TEST(MyStackShould, pop_elements_in_reverse_order_as_pushed)
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    ASSERT_EQ(3, stack.pop());
    ASSERT_EQ(2, stack.pop());
    ASSERT_EQ(1, stack.pop());
}

TEST(MyStackShould, be_empty_if_all_elements_popped)
{
    Stack <int> stack;

    stack.push(42);
    stack.pop();

    ASSERT_THROW(stack.pop(), std::exception);
}