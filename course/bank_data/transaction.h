#ifndef SC_CPP_TRANSACTION_H
#define SC_CPP_TRANSACTION_H

class Transaction
{
public:
    Transaction (const std::string& date, int amount)
    {
    }

    bool operator== (const Transaction& other) const
    {
        return true;
    }
};

#endif //SC_CPP_TRANSACTION_H
