#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Bank;

class Client
{
private:
    std::string full_name;

public:
    Client(std::string c_full_name);

    std::string getFullName();

    void setFullName(std::string);
   
    void depositMoney(Bank* bank, float sum);
    void withdrawMoney(Bank* bank, float sum);
    void transferMoney(Bank* bank, Client *receiver, float sum);
    void checkBalance(Bank *bank);
};

#endif
