#include <iostream>
#include <algorithm>
#include "Bank.h"
#include "../client/Client.h"
#include "../client/Legal.h"

#include<cstdlib>

Bank::Bank(std::string b_name) {
    this->name = std::move(b_name);
    this->bank_account = 0;
    this->bank_percent = 10;
}

Bank::Bank(std::string b_name, float b_bank_percent) {
    this->name = std::move(b_name);
    this->bank_percent = b_bank_percent;
}

Bank::Bank(std::string b_name, float b_bank_account, float b_bank_percent) {
    this->name = std::move(b_name);
    this->bank_account = b_bank_account;
    this->bank_percent = b_bank_percent;
}

float Bank::getBankAccount() const {
    return this->bank_account;
}

float Bank::getBankPercent() const {
    return this->bank_percent;
}

std::string Bank::getName() {
    return this->name;
}

void Bank::depositScore(Client *client, float sum) {
    if (clients_accounts.find(client) == clients_accounts.end())
    {
        std::cout << "Такого клиента нет!\n";
        return;
    }
    this->clients_accounts[client] += sum;
}

void Bank::withdrawScore(Client *client, float sum) {
    if (clients_accounts.find(client) == clients_accounts.end())
    {
        std::cout << "Такого клиента нет!\n";
        return;
    }
    float dif = this->clients_accounts[client] - sum;
    if (dif < 0) {
        std::cout << "Вы не можете снять " << sum << "! Ваш баланс: " << this->clients_accounts[client] << "\n";
        return;
    }
    this->clients_accounts[client] -= sum;
}

void Bank::transferMoneyInsideBank(Client *giver, Client *receiver, float sum) {
    float giver_sum = this->clients_accounts[giver];
    std::cout << "Вы собираетесь перевести: " << sum << ", банк взимает: "
              << this->bank_percent / 100 * sum << ". Итого Вы заплатите: " << sum + this->bank_percent / 100 * sum
              << "\n";
    if (giver_sum < sum + this->bank_percent / 100 * sum) {
        std::cout << "У вас недостаточно средств!" << "\n";
        return;
    }
    if (this->clients_accounts.find(receiver) == this->clients_accounts.end()) {
        std::cout << "Такого клиента нет!" << "\n";
        return;
    }
    this->clients_accounts[giver] -= sum + this->bank_percent / 100 * sum;
    this->bank_account += this->bank_percent / 100 * sum;
    this->clients_accounts[receiver] += sum;
}

void Bank::makeDepositTransferForLegalEntity(Bank *bank_to, Legal *legal_client, Client *receiver, float sum) {
    float giver_sum = this->clients_accounts[legal_client];
    std::cout << "Вы собираетесь перевести: " << sum << ", банк взимает: "
              << this->bank_percent / 100 * sum << ". Итого Вы заплатите: "
              << sum + this->bank_percent / 100 * sum << "\n";
    if (giver_sum < sum + this->bank_percent / 100 * sum) {
        std::cout << "У вас недостаточно средств!" << "\n";
        return;
    }
    if (bank_to->clients_accounts.find(receiver) == bank_to->clients_accounts.end()) {
        std::cout << "Такого клиента нет!" << "\n";
        return;
    }
    this->clients_accounts[legal_client] -= sum + this->bank_percent / 100 * sum;
    this->bank_account += this->bank_percent / 100 * sum;
    bank_to->clients_accounts[receiver] += sum;

}

std::map<Client *, float> Bank::getClientsAccounts() {
    return this->clients_accounts;
}


int Bank::getNumberOfClients() {
    return this->clients_accounts.size();
}

void Bank::addClient(Client *client) {
    for (auto const &pair: clients_accounts)
    {
        if (pair.first->getFullName() == client->getFullName() && pair.first->getPersonalCode() == client->getPersonalCode())
        {
            std::cout << "Такой клиент уже есть в банке!\n";
            return;
        }
    }
    clients_accounts[client] = 0;
}


void Bank::removeClient(Client *client) {
    clients_accounts.erase(client);
}

void Bank::printClients() {
    std::cout << this->name << "(" << this->clients_accounts.size() << " clients), bank percent - "
              << this->bank_percent << "%, bank account = " << this->bank_account << std::endl;
    for (auto const &pair: this->clients_accounts) {
        if (clientIsLegal(pair.first))
        {
            std::cout << pair.first->getPersonalCode() << ": " << "<legal> " << pair.first->getFullName()
                      << " (balance = " << pair.second << ")\n";
        } else {
            std::cout << pair.first->getPersonalCode() << ": " << "<physical> " << pair.first->getFullName()
                      << " (balance = " << pair.second << ")\n";
        }

    }
}

void Bank::printClient(Client *client) {
    for (auto const &pair: this->clients_accounts) {
        if (pair.first == client)
            std::cout << pair.first->getPersonalCode() << ": " << pair.first->getFullName()
                      << " (balance = " << pair.second << ")\n";
    }
}

//std::vector<Legal*> Bank::getLegals() {
//    std::vector<Legal*> legals;
//    for (auto const &pair: this->clients_accounts) {
//            std::cout << typeid(pair.first).name() << "\n";
//            if (dynamic_cast<Legal*>(pair.first))
//            {
//
//            }
//            legals.push_back(dynamic_cast<Legal*>(pair.first));
//    }
//    return legals;
//}

bool Bank::clientIsLegal(Client *client) {
    if (dynamic_cast<Legal*>(client))
    {
        return true;
    }
    return false;
}



