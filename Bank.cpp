#include <iostream>

#include "Bank.h"
#include "Client.h"

Bank::Bank(std::string b_name)
{
    this->name = std::move(b_name);
    this->bank_account = 0;
    this->bank_percent = 10;
}

Bank::Bank(std::string b_name, float b_bank_account)
{
    this->name = std::move(b_name);
    this->bank_account = b_bank_account;
    this->bank_percent = 10;
}
Bank::Bank(std::string b_name, float b_bank_account, float b_bank_percent)
{
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

void Bank::depositScoreByFullName(Client *client, float sum)
{
    std::string client_name = client->getFullName();
    this->clients_accounts[client_name] += sum;
}

void Bank::withdrawScoreByFullName(Client *client, float sum)
{
    std::string client_name = client->getFullName();
    float dif = this->clients_accounts[client_name] - sum;
    if (dif < 0)
    {
        std::cout << "Вы не можете снять " << sum <<"! Ваш баланс: " << this->clients_accounts[client_name] << "\n";
        return;
    }
    this->clients_accounts[client_name] -= sum;
}

void Bank::makeDepositTransferForLegalEntity(Legal *legal_client, Bank *bank_from, Bank *bank_to, float sum)
{
    std::string legal_client_name = legal_client->getFullName();
    float score_from = bank_from->clients_accounts[legal_client_name];


}

void Bank::makeWithdrawTransferForLegalEntity(Legal *legal_client, Bank *bank_from, Bank *bank_to, float sum)
{
    std::string legal_client_name = legal_client->getFullName();
    float score_from = bank_from->clients_accounts[legal_client_name];
}

std::map<std::string, float> Bank::getClientsAccounts() {
    return this->clients_accounts;
}

int Bank::getNumberOfClients() {
    return this->clients_accounts.size();
}

void Bank::addClient(Client *client) {
    clients_accounts[client->getFullName()] = 0;
}

void Bank::removeClient(Client *client) {
    clients_accounts.erase(client->getFullName());
}

void Bank::printClients() {
    std::cout << this->name << std::endl;
    for (auto const &pair: this->clients_accounts) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}


