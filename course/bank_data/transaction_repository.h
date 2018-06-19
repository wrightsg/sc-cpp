#ifndef SC_CPP_TRANSACTION_REPOSITORY_H
#define SC_CPP_TRANSACTION_REPOSITORY_H

#include "transaction.h"

class TransactionRepository
{
public:
    virtual ~TransactionRepository () = default;
    virtual void add_transaction (const Transaction& transaction) = 0;
};

#endif //SC_CPP_TRANSACTION_REPOSITORY_H
