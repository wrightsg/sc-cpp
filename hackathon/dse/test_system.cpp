#include "gtest/gtest.h"

#include "entity_mock.h"
#include "system.h"

class test_param_resource : public ::testing::TestWithParam<resource> {};

TEST_P(test_param_resource, get_resource_total)
{
    entity_mock e1;
    EXPECT_CALL(e1, get_resource(GetParam())).Times(1).WillOnce(::testing::Return(3));
    entity_mock e2;
    EXPECT_CALL(e2, get_resource(GetParam())).Times(1).WillOnce(::testing::Return(7));

    ASSERT_EQ(10, get_resource_total({&e1, &e2}, GetParam()));
}

INSTANTIATE_TEST_CASE_P(all_resources, test_param_resource, ::testing::Values(resource::LUT, resource::BRAM, resource::DSP));
