#ifndef LEGAL_H
#define LEGAL_H


#include <utility>

#include "Client.h"

class Legal : public Client{

public:
    Legal(std::string p_full_name) : Client(std::move(p_full_name)) {}

public:
    void makeDepositTransfer(Bank *bank_from, Bank *bank_to, float sum);
};


#endif
