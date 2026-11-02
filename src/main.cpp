#include <iostream>
#include <memory>
#include <vector>

#include "BankAccount.h"
#include "CheckingAccount.h"
#include "CreditAccount.h"
#include "SavingsAccount.h"

int main() {
    // Базовий рахунок
    BankAccount acc("UA0001", "Іван Петренко", 1000.0);
    acc.info();
    acc.deposit(500);
    std::cout << "Після поповнення: " << acc.getBalance() << " грн\n";
    if (!acc.withdraw(5000)) {
        std::cout << "Недостатньо коштів\n";
    }

    // Накопичувальний рахунок
    SavingsAccount savings("UA0002", "Марія Коваль", 10000.0, 5.0, 1000.0);
    savings.info();
    savings.addInterest();
    std::cout << "Після нарахування відсотків: " << savings.getBalance()
              << " грн\n";
    if (!savings.withdraw(10000)) {
        std::cout << "Зняття відхилено: порушено мінімальний залишок\n";
    }

    // Поточний рахунок з овердрафтом
    CheckingAccount checking("UA0003", "Олег Шевченко", 200.0, 500.0);
    checking.info();
    if (checking.withdraw(600)) {
        std::cout << "Знято 600 грн, баланс: " << checking.getBalance()
                  << " грн\n";
    }

    // Кредитний рахунок
    CreditAccount credit("UA0004", "Анна Мельник", 0.0, 3000.0, 2.0);
    credit.info();
    if (credit.withdraw(1000)) {
        std::cout << "Знято 1000 грн (з комісією), баланс: "
                  << credit.getBalance() << " грн\n";
    }

    // Поліморфізм через вказівник на базовий клас
    std::cout << "\n--- Поліморфізм ---\n";
    std::vector<std::unique_ptr<BankAccount>> accounts;
    accounts.push_back(
        std::make_unique<BankAccount>("UA1001", "Клієнт 1", 800.0));
    accounts.push_back(std::make_unique<SavingsAccount>(
        "UA1002", "Клієнт 2", 5000.0, 4.5, 500.0));
    accounts.push_back(
        std::make_unique<CheckingAccount>("UA1003", "Клієнт 3", 100.0, 300.0));
    accounts.push_back(std::make_unique<CreditAccount>(
        "UA1004", "Клієнт 4", 0.0, 2000.0, 1.5));

    for (auto& a : accounts) {
        a->info();
        bool ok = a->withdraw(400);
        std::cout << "  Зняття 400 грн: " << (ok ? "успішно" : "відмова")
                  << ", баланс: " << a->getBalance() << " грн\n";
    }

    return 0;
}
