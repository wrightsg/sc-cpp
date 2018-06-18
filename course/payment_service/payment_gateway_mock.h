#ifndef SC_CPP_PAYMENT_GATEWAY_MOCK_H
#define SC_CPP_PAYMENT_GATEWAY_MOCK_H

#include "gmock/gmock.h"

#include "payment_gateway.h"

class PaymentGatewayMock : public PaymentGateway
{
public:
    MOCK_METHOD1(processPayment, void(const PaymentDetails&));
};

#endif //SC_CPP_PAYMENT_GATEWAY_MOCK_H
