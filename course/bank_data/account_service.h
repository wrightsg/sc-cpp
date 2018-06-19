#ifndef SC_CPP_ACCOUNT_SERVICE_H
#define SC_CPP_ACCOUNT_SERVICE_H

#include "date_provider.h"
#include "transaction_repository.h"

class AccountService
{
public:
    AccountService (TransactionRepository& transaction_repository, DateProvider& date_provider)
        : _transaction_repository(transaction_repository)
        , _date_provider(date_provider)
    {
    }

    void deposit (int amount)
    {
        _transaction_repository.add_transaction(Transaction(_date_provider.get_date(), amount));
    }

    void withdraw (int amount)
    {
        _transaction_repository.add_transaction(Transaction(_date_provider.get_date(), -amount));
    }

    void printStatement ()
    {
    }

private:
    TransactionRepository& _transaction_repository;
    DateProvider& _date_provider;
};

#endif //SC_CPP_ACCOUNT_SERVICE_H
