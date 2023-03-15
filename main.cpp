#include <iostream>

#include "bank/Bank.h"
#include "client/Client.h"
#include "bank/BankSystem.h"
#include "client/Physical.h"
#include "client/Legal.h"

int main(int, char**) {

    Physical client("Vadim Shaforostov");
    Legal client2("Pasha Raspopov");
    Bank bank("Sberbank");
    Bank bank2("Gazprombank");
    BankSystem bankSystem;
    bankSystem.addBank(&bank);
    bankSystem.addBank(&bank2);
    bank.addClient(&client2);
    client.depositMoney(&bank, 300);
    client2.depositMoney(&bank2, 100);

//    client.transferMoney(&bank, &client2, 200);

    client2.makeTransferToAnotherBank(&bank2, &bank, &client, 90);
    bank2.printClients();
    bank.printClients();
//    Physical client3("Vadim Shaforostov");

//    bank.printClients();
//    bank2.printClients();
//    bank.printClient(&client2);
//    std::cout << "Количество банков: " << bankSystem.getNumberOfBanks() << "\n";
//    bankSystem.printBanks();
//    bankSystem.removeBank(&bank);
////    std::cout << "Количество банков: " << bankSystem.getNumberOfBanks() << "\n";
//    bank.addClient(&client);
//    bank.addClient(&client2);
////    std::cout << bank.getNumberOfClients() << "\n";
//    bank2.addClient(&client2);
//    client.depositMoney(&bank, 500);
//    client.withdrawMoney(&bank, 600);
//    bank.printClients();

//    Physical p1("One");
//    p1.depositMoney(&bank, 500);
//    Physical p2("Two");
//    bank.addClient(&p2);
//    std::cout << bank.getNumberOfClients() << "\n";
//    p1.transferMoney(&bank, &p2, 50);
//    bank.printClients();
//    std::cout << "Банк заскамил на: " << bank.getBankAccount() << "\n";
//    p2.transferMoney(&bank, &p1, 40);
//    std::cout << "Банк: " << bank.getBankAccount() << "\n";
//    p2.checkBalance(&bank);
//    p1.checkBalance(&bank);

//    Legal l1("Man");
//    l1.depositMoney(&bank, 500);
//    Physical p1("Woman");
//    bank2.addClient(&p1);
//    l1.makeTransferToAnotherBank(&bank, &bank2, &p1, 300);
//    l1.checkBalance(&bank);
//    bank.printClients();
//    bank2.printClients();
}
