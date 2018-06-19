#ifndef SC_CPP_TRANSACTION_REPOSITORY_MOCK_H
#define SC_CPP_TRANSACTION_REPOSITORY_MOCK_H

#include "gmock/gmock.h"

#include "transaction_repository.h"

class TransactionRepositoryMock : public TransactionRepository
{
public:
    MOCK_METHOD1(add_transaction, void(int));
};

#endif //SC_CPP_TRANSACTION_REPOSITORY_MOCK_H
