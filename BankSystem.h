#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include<vector>

#include "bank/Bank.h"

class BankSystem
{
private:
    std::vector<Bank*> banks;

public:
    BankSystem();
    std::vector<Bank*> getBanks();
    int getNumberOfBanks();
    void addBank(Bank *bank);
    void removeBank(Bank *bank);
    void printBanks();
};

#endif