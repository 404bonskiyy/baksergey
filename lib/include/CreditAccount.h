#pragma once
#include "CheckingAccount.h"

// Кредитний рахунок: поточний рахунок з комісією за зняття
class CreditAccount : public CheckingAccount {
public:
    CreditAccount(const std::string& number, const std::string& owner,
                  double balance, double creditLimit, double feePercent);

    bool withdraw(double amount) override;
    void info() const override;

    double getFeePercent() const;

private:
    double feePercent_;
};
