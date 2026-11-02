add_library(bank_lib
    src/BankAccount.cpp
    src/SavingsAccount.cpp
    src/CheckingAccount.cpp
    src/CreditAccount.cpp
)

target_include_directories(bank_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
