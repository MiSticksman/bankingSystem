#include <iostream>

#include "Bank.h"
#include "Client.h"
#include "BankSystem.h"
#include "Physical.h"
#include "Legal.h"

int main(int, char**) {

    Physical client("Vadim Shaforostov");
    Legal client2("Pasha Raspopov");
    Bank bank("Sberbank");
    Bank bank2("Gazprombank");
    BankSystem bankSystem;
    bankSystem.addBank(&bank);
    bankSystem.addBank(&bank2);
    std::cout << "Количество банков: " << bankSystem.getNumberOfBanks() << "\n";
    bankSystem.printBanks();
    bankSystem.removeBank(&bank);
//    std::cout << "Количество банков: " << bankSystem.getNumberOfBanks() << "\n";
    bank.addClient(&client);
    bank.addClient(&client2);
//    std::cout << bank.getNumberOfClients() << "\n";
    bank2.addClient(&client2);
    client.depositMoney(&bank, 500);
    client.withdrawMoney(&bank, 600);
    bank.printClients();
}
