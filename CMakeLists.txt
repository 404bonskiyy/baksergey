cmake_minimum_required(VERSION 3.10)
project(BankProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE bank_lib)
