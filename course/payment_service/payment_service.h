#ifndef SC_CPP_PAYMENT_SERVICE_H
#define SC_CPP_PAYMENT_SERVICE_H

#include "payment_details.h"
#include "payment_gateway.h"
#include "user.h"
#include "user_validation.h"

class PaymentService
{
public:
    PaymentService (UserValidation& user_validation, PaymentGateway& payment_gateway)
        : _user_validation(user_validation)
        , _payment_gateway(payment_gateway)
    {
    }

    void processPayment (const User& user, const PaymentDetails& payment_details)
    {
        if (!_user_validation.validateUser(user)) {
            throw std::exception();
        }
        _payment_gateway.processPayment(payment_details);
    }

private:
    UserValidation& _user_validation;
    PaymentGateway& _payment_gateway;
};

#endif //SC_CPP_PAYMENT_SERVICE_H
