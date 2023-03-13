#include <iostream>

#include "BankSystem.h"

BankSystem::BankSystem() = default;

std::vector<Bank*> BankSystem::getBanks() {
    return this->banks;
}

int BankSystem::getNumberOfBanks() {
    return this->banks.size();
}

void BankSystem::addBank(Bank *bank) {
    this->banks.push_back(bank);
}

void BankSystem::removeBank(Bank *bank) {
    auto it = this->banks.begin();
    while ( it != this->banks.end())
    {
        if (*it == bank)
        {
            it = this->banks.erase(it);
        }
        else
        {
            it++;
        }
    }
}
void BankSystem::printBanks() {
    for (auto i: this->banks)
        std::cout << i->getName() << "\n";
}