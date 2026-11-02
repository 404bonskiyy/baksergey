#pragma once
#include "BankAccount.h"

// Накопичувальний рахунок: нараховує відсотки, обмежує зняття
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(const std::string& number, const std::string& owner,
                   double balance, double interestRate, double minBalance);

    bool withdraw(double amount) override;
    void info() const override;

    void addInterest();
    double getInterestRate() const;

private:
    double interestRate_;  // у відсотках річних
    double minBalance_;    // мінімальний залишок
};
