#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(const std::string& number,
                               const std::string& owner, double balance,
                               double interestRate, double minBalance)
    : BankAccount(number, owner, balance),
      interestRate_(interestRate),
      minBalance_(minBalance) {}

bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0 || balance_ - amount < minBalance_) {
        return false;
    }
    balance_ -= amount;
    return true;
}

void SavingsAccount::info() const {
    std::cout << "Накопичувальний рахунок " << number_
              << ", власник: " << owner_ << ", баланс: " << balance_
              << " грн, ставка: " << interestRate_
              << "%, мін. залишок: " << minBalance_ << " грн\n";
}

void SavingsAccount::addInterest() {
    balance_ += balance_ * interestRate_ / 100.0;
}

double SavingsAccount::getInterestRate() const { return interestRate_; }
