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
   
    void depositMoney(Bank*, float);
    void withdrawMoney(Bank*, float);
};

#endif
