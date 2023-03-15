
#include <iostream>
#include "Console.h"
#include "../bank/BankSystem.h"
#include "../client/Physical.h"
#include "../client/Legal.h"

using namespace std;

void Console::start() {
    BankSystem *bankSystem = new BankSystem;
    while (true) {
        cout << "Выберите действие (ввод соответствующей цифры без точки): \n "
                "1.Создать банк \n 2.Создать клиента \n 3.Просмотр банков \n 4.Работа с банком \n "
                "5.Работа с клиентом \n 6.Завершить \n";
        int action_code;
        cin >> action_code;
        if (action_code != 5) {

            if (action_code == 1) {
                cout << "Введите название банка: ";
                string bank_name;
                cin >> bank_name;
                Bank *bank(new Bank(bank_name));
                bankSystem->addBank(bank);
                continue;
            } else if (action_code == 2) {
                cout << "В какой банк Вы хотите добавить клиента? (Введите соответствующую цифру без точки) \n";
                bankSystem->printBanks();
                int bank_code;
                cin >> bank_code;
                Bank *bank = bankSystem->getBanks()[bank_code - 1];
                cout << "Кого Вы хотите создать: \n 1.Физическое лицо \n 2.Юридическое лицо \n";
                int client_code;
                cin >> client_code;
                cout << "Введите полное имя клиента: ";
                string client_name;
                std::getline(std::cin >> std::ws, client_name);
                Client *client = nullptr;
                if (client_code == 1) {
                    client = new Physical(client_name);
                }
                if (client_code == 2) {
                    client = new Legal(client_name);
                }
                bank->addClient(client);
                bank->printClients();
                continue;
            } else if (action_code == 3) {
                bankSystem->printBanks();
                continue;
            } else if (action_code == 4) {
                cout << "Выберите банк:\n";
                bankSystem->printBanks();
                int bank_code;
                cin >> bank_code;
                Bank *cur_bank = bankSystem->getBanks()[bank_code - 1];
                bankSystem->printBankByName(cur_bank->getName());
                cur_bank->printClients();
                cout << "1.Добавить клиента\n2.Удалить клиента \n";
                int code;
                cin >> code;
                if (code == 1) {
                    std::vector<Client *> v = bankSystem->getClients();
                    for (int i = 0; i < v.size(); ++i) {
                        std::cout << i + 1 << ". " << v[i]->getPersonalCode() << ": " << v[i]->getFullName()
                                  << std::endl;
                    }
                    int client_number;
                    cout << "Выберите клиента (номер): \n";
                    cin >> client_number;
                    cur_bank->addClient(v[client_number-1]);

                } else if (code == 2) {
                    int counter = 0;
                    std::vector<Client*> cl;
                    for (auto const &pair: cur_bank->getClientsAccounts()) {
                        std::cout << counter+1 << ". " << pair.first->getPersonalCode() << ": " << pair.first->getFullName()
                                  << std::endl;
                        cl.push_back(pair.first);
                        counter++;
                    }
                    int client_number;
                    cout << "Выберите клиента (номер): \n";
                    cin >> client_number;
                    cur_bank->removeClient(cl[client_number-1]);
                }
            } else if (action_code == 5) {
                cout << "Выберите банк, клиент которого Вам нужен: ";
                bankSystem->printBanks();
            }
        }
    }

}
