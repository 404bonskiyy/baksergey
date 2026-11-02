#include "CreditAccount.h"
#include <iostream>

CreditAccount::CreditAccount(const std::string& number,
                             const std::string& owner, double balance,
                             double creditLimit, double feePercent)
    : CheckingAccount(number, owner, balance, creditLimit),
      feePercent_(feePercent) {}

bool CreditAccount::withdraw(double amount) {
    if (amount <= 0) {
        return false;
    }
    double total = amount + amount * feePercent_ / 100.0;
    return CheckingAccount::withdraw(total);
}

void CreditAccount::info() const {
    std::cout << "Кредитний рахунок " << number_ << ", власник: " << owner_
              << ", баланс: " << balance_
              << " грн, кредитний ліміт: " << getOverdraftLimit()
              << " грн, комісія: " << feePercent_ << "%\n";
}

double CreditAccount::getFeePercent() const { return feePercent_; }
