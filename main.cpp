#include <iostream>

#include "bank/Bank.h"
#include "client/Client.h"
#include "bank/BankSystem.h"
#include "client/Physical.h"
#include "client/Legal.h"
#include "GUI/Console.h"

int main(int, char**) {

//    Physical client("Vadim Shaforostov");
//    Legal client2("Pasha Raspopov");
//    Bank bank("Sberbank");
//    Bank bank2("Gazprombank");
//    BankSystem bankSystem;
//    bankSystem.addBank(&bank);
//    bankSystem.addBank(&bank2);
//    bank.addClient(&client);
//    bank2.addClient(&client2);
//    std::vector<Client*> v = bankSystem.getClients();
//    for (auto &i : v) {
//        std::cout << i->getPersonalCode() << ": "<< i->getFullName() << std::endl;
//    }



    Console console;
    console.start();
}
