cmake_minimum_required(VERSION 3.0.0)
project(bankSystem VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(bankSystem main.cpp Bank.cpp Client.cpp BankSystem.h BankSystem.cpp Physical.cpp Physical.h Legal.cpp Legal.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
