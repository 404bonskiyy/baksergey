#pragma once
#include <string>

class BankAccount {
public:
    BankAccount(const std::string& number, const std::string& owner,
                double balance = 0.0);
    virtual ~BankAccount() = default;

    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    virtual void info() const;

    const std::string& getNumber() const;
    const std::string& getOwner() const;
    double getBalance() const;

protected:
    std::string number_;
    std::string owner_;
    double balance_;
};
