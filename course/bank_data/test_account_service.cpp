#include "gtest/gtest.h"

#include "account_service.h"
#include "console_mock.h"
#include "date_provider_mock.h"
#include "transaction_repository_mock.h"

TEST(PrintStatementFeature, should_print_deposits_and_withdrawals_to_console_in_reverse_order)
{
    TransactionRepositoryMock transaction_repository;
    DateProviderMock date_provider;
    AccountService account_service(transaction_repository, date_provider);

    account_service.deposit(1000);
    account_service.withdraw(100);
    account_service.deposit(500);
    account_service.printStatement();

    std::ostringstream statement;
    statement << "DATE | AMOUNT | BALANCE" << "\n"
              << "10/04/2014 | 500.00 | 1400.00" << "\n"
              << "02/04/2014 | -100.00 | 900.00" << "\n"
              << "01/04/2014 | 1000.00 | 1000.00";

    // Note that the console interface influences the internal design of the account service,
    // e.g. Console::print() could also be Console::printLine()
    ConsoleMock console;
    EXPECT_CALL(console, print(statement.str())).Times(1);
}

TEST(AccountServiceShould, add_same_number_of_positive_transactions_as_deposits_to_transaction_repository)
{
    TransactionRepositoryMock transaction_repository;
    {
        ::testing::InSequence sequence;
        EXPECT_CALL(transaction_repository, add_transaction(Transaction("10/04/2014", 42)));
        EXPECT_CALL(transaction_repository, add_transaction(Transaction("02/04/2014", 1000)));
    }

    DateProviderMock date_provider;
    EXPECT_CALL(date_provider, get_date())
            .Times(2)
            .WillOnce(::testing::Return("10/04/2014"))
            .WillOnce(::testing::Return("02/04/2014"));
    AccountService account_service(transaction_repository, date_provider);

    account_service.deposit(42);
    account_service.deposit(1000);
}

TEST(AccountServiceShould, add_same_number_of_negative_transactions_as_withdrawals_to_transaction_repository)
{
    TransactionRepositoryMock transaction_repository;
    {
        ::testing::InSequence sequence;
        EXPECT_CALL(transaction_repository, add_transaction(Transaction("10/04/2014", -1337))).Times(1);
        EXPECT_CALL(transaction_repository, add_transaction(Transaction("02/04/2014", -10))).Times(1);
    }

    DateProviderMock date_provider;
    EXPECT_CALL(date_provider, get_date())
            .Times(2)
            .WillOnce(::testing::Return("10/04/2014"))
            .WillOnce(::testing::Return("02/04/2014"));
    AccountService account_service(transaction_repository, date_provider);

    account_service.withdraw(1337);
    account_service.withdraw(10);
}

TEST(TransactionShould, be_equal_to_transaction_with_same_date_and_id)
{
    ASSERT_TRUE(Transaction("1/1/1970", 10) == Transaction("1/1/1970", 10));
}

TEST(TransactionShould, not_be_equal_to_transaction_with_different_date)
{
    ASSERT_FALSE(Transaction("1/1/1970", 10) == Transaction("1/1/1999", 10));
}

TEST(TransactionShould, not_be_equal_to_transaction_with_different_id)
{
    ASSERT_FALSE(Transaction("1/1/1970", 10) == Transaction("1/1/1970", 100));
}