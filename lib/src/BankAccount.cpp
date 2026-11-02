#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(const std::string& number, const std::string& owner,
                         double balance)
    : number_(number), owner_(owner), balance_(balance) {}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance_ += amount;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance_) {
        return false;
    }
    balance_ -= amount;
    return true;
}

void BankAccount::info() const {
    std::cout << "Рахунок " << number_ << ", власник: " << owner_
              << ", баланс: " << balance_ << " грн\n";
}

const std::string& BankAccount::getNumber() const { return number_; }
const std::string& BankAccount::getOwner() const { return owner_; }
double BankAccount::getBalance() const { return balance_; }
