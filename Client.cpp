#include "Client.h"
#include "Bank.h"

Client::Client(std::string c_full_name)
        : full_name{std::move(c_full_name)}
{ }

std::string Client::getFullName()
{
    return this->full_name;
}


void Client::setFullName(std::string new_full_name)
{
    this->full_name = std::move(new_full_name);
}
void Client::depositMoney(Bank *bank, float sum_of_money)
{
    bank->depositScoreByFullName(this, sum_of_money);
}

void Client::withdrawMoney(Bank *bank, float sum_of_money)
{
    bank->withdrawScoreByFullName(this, sum_of_money);
}
