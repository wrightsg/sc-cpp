#ifndef SC_CPP_PAYMENT_GATEWAY_H
#define SC_CPP_PAYMENT_GATEWAY_H

#include "payment_details.h"

class PaymentGateway
{
public:
    virtual void processPayment (const PaymentDetails& payment_details) = 0;
};

#endif //SC_CPP_PAYMENT_GATEWAY_H
