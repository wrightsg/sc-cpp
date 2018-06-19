#ifndef SC_CPP_ACCOUNT_SERVICE_H
#define SC_CPP_ACCOUNT_SERVICE_H

#include "transaction_repository.h"

class AccountService
{
public:
    AccountService (TransactionRepository& transaction_repository)
        : _transaction_repository(transaction_repository)
    {
    }

    void deposit (int amount)
    {
        _transaction_repository.add_transaction(amount);
    }

    void withdraw (int amount)
    {
        _transaction_repository.add_transaction(-amount);
    }

    void printStatement ()
    {
    }

private:
    TransactionRepository& _transaction_repository;
};

#endif //SC_CPP_ACCOUNT_SERVICE_H
