#ifndef SC_CPP_TRANSACTION_REPOSITORY_H
#define SC_CPP_TRANSACTION_REPOSITORY_H

class TransactionRepository
{
public:
    virtual void add_transaction (int amount) = 0;
};

#endif //SC_CPP_TRANSACTION_REPOSITORY_H
