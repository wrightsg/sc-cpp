#include "gtest/gtest.h"

#include "entity.h"

TEST(entity, default_construct)
{
    entity e;
}

TEST(entity, get_resource_from_default_constructed)
{
    entity e;
    EXPECT_THROW(e.get_resource(resource::LUT), std::exception);
    EXPECT_THROW(e.get_resource(resource::BRAM), std::exception);
    EXPECT_THROW(e.get_resource(resource::DSP), std::exception);
}