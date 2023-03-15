#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include<vector>

#include "Bank.h"

class BankSystem
{
private:
    std::vector<Bank*> banks;
    std::vector<Client*> clients;
    void fillClients();

public:
    BankSystem();
    std::vector<Bank*> getBanks();
    std::vector<Client*> getClients();
    int getNumberOfBanks();
    Bank* getBankByName(const std::string& bank_name);
    void printBankByName(const std::string& bank_name);
    void addBank(Bank *bank);
    void removeBank(Bank *bank);
    void printBanks();
};

#endif