#include "gtest/gtest.h"

#include "entity.h"

TEST(entity, default_construct)
{
    entity e;
}

class test_param_resource : public ::testing::TestWithParam<resource> {};

TEST_P(test_param_resource, get_resource_from_default_constructed)
{
    entity e;
    EXPECT_THROW(e.get_resource(GetParam()), std::exception);
}

INSTANTIATE_TEST_CASE_P(all_resources, test_param_resource, ::testing::Values(resource::LUT, resource::BRAM, resource::DSP));