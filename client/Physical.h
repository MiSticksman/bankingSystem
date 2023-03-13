#ifndef PHYSICAL_H
#define PHYSICAL_H


#include <utility>

#include "Client.h"

class Physical : public Client{

public:
    Physical(std::string p_full_name) : Client(std::move(p_full_name)) {}
};


#endif
