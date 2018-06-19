#include "gtest/gtest.h"

#include "account_service.h"
#include "console_mock.h"
#include "transaction_repository_mock.h"

TEST(PrintStatementFeature, should_print_deposits_and_withdrawals_to_console_in_reverse_order)
{
    TransactionRepositoryMock transaction_repository;
    AccountService account_service(transaction_repository);

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

TEST(AccountServiceShould, add_same_number_of_positive_transaction_as_deposits_to_transaction_repository)
{
    TransactionRepositoryMock transaction_repository;

    AccountService account_service(transaction_repository);

    account_service.deposit(42);

    EXPECT_CALL(transaction_repository, add_transaction(42)).Times(1);
}