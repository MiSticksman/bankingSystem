#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>

class Bank;

class Client
{
private:
    std::string full_name;
    int personal_code;
    static inline std::vector<int> codes;

public:
    Client(std::string c_full_name);
public:
    std::string getFullName();
    int getPersonalCode();
    void setFullName(std::string);
    void depositMoney(Bank* bank, float sum);
    void withdrawMoney(Bank* bank, float sum);
    void transferMoney(Bank* bank, Client *receiver, float sum);
    void checkBalance(Bank *bank);
};

#endif
