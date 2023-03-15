#include <iostream>
#include<vector>
#include <algorithm>
#include "Client.h"
#include "../bank/Bank.h"

Client::Client(std::string c_full_name)
        : full_name{std::move(c_full_name)} {
    while (true) {
        int code = 1000 + rand() % 9000;
        if (!(std::find(Client::codes.begin(), Client::codes.end(), code) != Client::codes.end())) {
            codes.push_back(code);
            this->personal_code = code;
            break;
        }
    }
}

std::string Client::getFullName() {
    return this->full_name;
}

int Client::getPersonalCode() {
    return this->personal_code;
}


void Client::setFullName(std::string new_full_name) {
    this->full_name = std::move(new_full_name);
}

void Client::depositMoney(Bank *bank, float sum_of_money) {
    bank->depositScore(this, sum_of_money);
}

void Client::withdrawMoney(Bank *bank, float sum_of_money) {
    bank->withdrawScore(this, sum_of_money);
}

void Client::transferMoney(Bank *bank, Client *receiver, float sum) {
    bank->transferMoneyInsideBank(this, receiver, sum);
}

void Client::checkBalance(Bank *bank) {
    std::cout << "На Вашем счете: " << bank->getClientsAccounts()[this] << "\n";
}

std::vector<int> Client::getCodes() {
    return Client::codes;
}


