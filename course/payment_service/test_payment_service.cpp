#include "gtest/gtest.h"

#include "payment_gateway_mock.h"
#include "user_validation_mock.h"

#include "payment_service.h"

TEST(PaymentServiceShould, throw_exception_when_user_is_invalid)
{
    User user(42);
    PaymentDetails payment_details(4);

    UserValidationMock user_validation;
    EXPECT_CALL(user_validation, validateUser(user)).Times(1).WillOnce(::testing::Return(false));

    PaymentGatewayMock payment_gateway;
    EXPECT_CALL(payment_gateway, processPayment(payment_details)).Times(0);

    PaymentService payment_service(user_validation, payment_gateway);

    ASSERT_THROW(payment_service.processPayment(user, payment_details), std::exception);
}

TEST(PaymentServiceShould, send_payment_details_to_gateway_when_user_is_valid)
{
    User user(42);
    PaymentDetails payment_details(4);

    UserValidationMock user_validation;
    EXPECT_CALL(user_validation, validateUser(user)).Times(1).WillOnce(::testing::Return(true));

    PaymentGatewayMock payment_gateway;
    EXPECT_CALL(payment_gateway, processPayment(payment_details)).Times(1);

    PaymentService payment_service(user_validation, payment_gateway);

    ASSERT_NO_THROW(payment_service.processPayment(user, payment_details));
}