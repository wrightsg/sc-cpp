#ifndef SC_CPP_PAYMENT_DETAILS_H
#define SC_CPP_PAYMENT_DETAILS_H

class PaymentDetails
{
public:
    PaymentDetails (int id)
        : _id(id)
    {
    }

    bool operator== (const PaymentDetails& other) const
    {
        return _id == other._id;
    }

private:
    int _id;
};

#endif //SC_CPP_PAYMENT_DETAILS_H
