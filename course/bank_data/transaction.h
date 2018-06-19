#ifndef SC_CPP_TRANSACTION_H
#define SC_CPP_TRANSACTION_H

#include <string>

class Transaction
{
public:
    Transaction (const std::string& date, int amount)
        : _date(date)
        , _amount(amount)
    {
    }

    bool operator== (const Transaction& other) const
    {
        return _date == other._date && _amount == other._amount;
    }

private:
    std::string _date;
    int _amount;
};

#endif //SC_CPP_TRANSACTION_H
