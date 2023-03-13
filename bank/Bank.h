#ifndef BANK_H
#define BANK_H

#include <map>
#include <vector>
#include <string>

class Client;
class Legal;
class Bank
{
private:
    std::string name;
    float bank_account; // счет банка
    float bank_percent; // процент, который взымает банк
    std::map<std::string, float> clients_accounts; // full_name, score
public:
    Bank(std::string b_name);
    Bank(std::string b_name, float b_bank_account);
    Bank(std::string b_name, float b_bank_account, float b_bank_percent);
public:
    std::string getName();
    float getBankAccount() const;
    float getBankPercent() const;
    std::map<std::string, float> getClientsAccounts();
    void depositScore(Client *client, float sum);
    void withdrawScore(Client *client, float sum);
    void transferMoneyInsideBank(Client *giver, Client *receiver, float sum);
    void makeDepositTransferForLegalEntity( Bank *bank_to, Legal *legal_client, Client *receiver, float sum);
    int getNumberOfClients();
    void addClient(Client *client);
    void removeClient(Client *client);
    void printClients();

};

#endif