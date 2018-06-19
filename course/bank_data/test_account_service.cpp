#include "gtest/gtest.h"

#include "account_service.h"
#include "console_mock.h"

TEST(PrintStatementFeature, should_print_deposits_and_withdrawals_to_console)
{
    AccountService account_service;

    account_service.deposit(1000);
    account_service.withdraw(100);
    account_service.deposit(500);
    account_service.printStatement();

    std::ostringstream statement;
    statement << "DATE | AMOUNT | BALANCE" << "\n"
              << "10/04/2014 | 500.00 | 1400.00" << "\n"
              << "02/04/2014 | -100.00 | 900.00" << "\n"
              << "01/04/2014 | 1000.00 | 1000.00";

    ConsoleMock console;
    EXPECT_CALL(console, print(statement.str())).Times(1);
}