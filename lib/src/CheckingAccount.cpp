#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(const std::string& number,
                                 const std::string& owner, double balance,
                                 double overdraftLimit)
    : BankAccount(number, owner, balance), overdraftLimit_(overdraftLimit) {}

bool CheckingAccount::withdraw(double amount) {
    if (amount <= 0 || balance_ - amount < -overdraftLimit_) {
        return false;
    }
    balance_ -= amount;
    return true;
}

void CheckingAccount::info() const {
    std::cout << "Поточний рахунок " << number_ << ", власник: " << owner_
              << ", баланс: " << balance_
              << " грн, овердрафт: " << overdraftLimit_ << " грн\n";
}

double CheckingAccount::getOverdraftLimit() const { return overdraftLimit_; }
