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

class AccountServiceShould : public ::testing::Test
{
public:
    AccountServiceShould ()
        : transaction_repository()
        , date_provider()
        , account_service(transaction_repository, date_provider)
    {
    }

protected:
    TransactionRepositoryMock transaction_repository;
    DateProviderMock date_provider;
    AccountService account_service;

    static const std::string DATE;
    static constexpr int AMOUNT = 42;
};

const std::string AccountServiceShould::DATE = "10/04/2014";

TEST_F(AccountServiceShould, add_a_transaction_with_a_positive_amount_when_depositing)
{
    EXPECT_CALL(transaction_repository, add_transaction(Transaction(DATE, AMOUNT)));
    EXPECT_CALL(date_provider, get_date()).Times(1).WillOnce(::testing::Return(DATE));
    account_service.deposit(AMOUNT);
}

TEST_F(AccountServiceShould, add_a_transaction_with_negative_amount_when_withdrawing)
{
    EXPECT_CALL(transaction_repository, add_transaction(Transaction(DATE, -AMOUNT)));
    EXPECT_CALL(date_provider, get_date()).Times(1).WillOnce(::testing::Return(DATE));
    account_service.withdraw(AMOUNT);
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