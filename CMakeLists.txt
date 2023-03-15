cmake_minimum_required(VERSION 3.0.0)
project(bankSystem VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(bankSystem main.cpp bank/Bank.cpp client/Client.cpp bank/BankSystem.h bank/BankSystem.cpp client/Physical.cpp client/Physical.h client/Legal.cpp client/Legal.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
