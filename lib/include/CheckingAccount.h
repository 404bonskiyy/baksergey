#pragma once
#include "BankAccount.h"

// Поточний рахунок: дозволений овердрафт
class CheckingAccount : public BankAccount {
public:
    CheckingAccount(const std::string& number, const std::string& owner,
                    double balance, double overdraftLimit);

    bool withdraw(double amount) override;
    void info() const override;

    double getOverdraftLimit() const;

private:
    double overdraftLimit_;
};
