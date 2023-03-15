#include <iostream>
#include <algorithm>
#include "BankSystem.h"

BankSystem::BankSystem() = default;

std::vector<Bank *> BankSystem::getBanks() {
    return this->banks;
}

int BankSystem::getNumberOfBanks() {
    return this->banks.size();
}

void BankSystem::addBank(Bank *bank) {
    for (auto &i: BankSystem::banks) {
        if (i->getName() == bank->getName()) {
            std::cout << "Это имя банка уже используется, выберите другое! \n";
            return;
        }
    }
    this->banks.push_back(bank);
}

Bank *BankSystem::getBankByName(const std::string &bank_name) {
    for (auto &bank: banks) {
        if (bank->getName() == bank_name) {
            return bank;
        }
    }
    return NULL;
}

void BankSystem::printBankByName(const std::string &bank_name) {
    Bank *bank = this->getBankByName(bank_name);
    std::cout << bank->getName() << ", баланс: " << bank->getBankAccount() << "\n";
}

void BankSystem::removeBank(Bank *bank) {
    auto it = this->banks.begin();
    while (it != this->banks.end()) {
        if (*it == bank) {
            it = this->banks.erase(it);
        } else {
            it++;
        }
    }
}

void BankSystem::printBanks() {
    int counter = 0;
    for (auto i: this->banks) {
        std::cout << counter + 1 << "." << i->getName() << ", баланс: " << i->getBankAccount() << "\n";
        i->printClients();
        counter++;
    }
}

std::vector<Client *> BankSystem::getClients() {
    this->fillClients();
    return this->clients;
}

void BankSystem::fillClients() {
    for (auto & bank : banks) {
        std::map<Client*, float> m = bank->getClientsAccounts();
        for (auto const &pair: m)
        {
            if(!(std::find(clients.begin(), clients.end(), pair.first) != clients.end())) {
                this->clients.push_back(pair.first);
            }
        }
    }

}
