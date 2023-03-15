
#include <iostream>
#include "Console.h"
#include "../bank/BankSystem.h"
#include "../client/Physical.h"
#include "../client/Legal.h"

using namespace std;

void Console::start() {
    cout << "Сначала нужно создать банк и клиентов. При создании клиента его необходимо прикрепить к банку.\n"
            "Клиентов, которые уже созданы, можно прикрепить к другим банкам или удалить из имеющихся. "
            "После добавления клианта\nнеобходимо пополнить баланс его счета в разделе <Работа с клиентом>."
            "У каждого клиента есть уникальный код.\n Он нужен, чтобы не путать клиентов с одинаковыми именами.\n"
            "По умолчанию банк забирает себе за транзакции 10% от суммы перевода с клиента счета, который выполняет"
            "перевод.\n";
    BankSystem *bankSystem = new BankSystem;
    while (true) {
        cout << "Выберите действие (ввод соответствующей цифры без точки): \n "
                "1.Создать банк \n 2.Создать клиента \n 3.Информация о банках и клиентах \n 4.Работа с банком \n "
                "5.Работа с клиентом \n 6.Завершить \n";
        int action_code;
        cin >> action_code;
        if (action_code != 6) {

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
//                Client *client = nullptr;
                if (client_code == 1) {
                    Physical *client = new Physical(client_name);
                    bank->addClient(client);
                }
                if (client_code == 2) {
                    Legal *client = new Legal(client_name);
                    bank->addClient(client);

                }

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
                    cur_bank->addClient(v[client_number - 1]);

                } else if (code == 2) {
                    int counter = 0;
                    std::vector<Client *> cl;
                    for (auto const &pair: cur_bank->getClientsAccounts()) {
                        std::cout << counter + 1 << ". " << pair.first->getPersonalCode() << ": "
                                  << pair.first->getFullName()
                                  << std::endl;
                        cl.push_back(pair.first);
                        counter++;
                    }
                    int client_number;
                    cout << "Выберите клиента (номер): \n";
                    cin >> client_number;
                    cur_bank->removeClient(cl[client_number - 1]);
                }
            } else if (action_code == 5) {
                cout << "Выберите банк, клиент которого Вам нужен:\n";
                bankSystem->printBanks();
                int bank_code;
                cin >> bank_code;
                Bank *cur_bank = bankSystem->getBanks()[bank_code - 1];
                std::vector<Client *> clients;
                int counter = 0;
                for (auto const &pair: cur_bank->getClientsAccounts()) {
                    if (Bank::clientIsLegal(pair.first)) {
                        std::cout << counter + 1 << ". " << pair.first->getPersonalCode() << ": "
                                  << pair.first->getFullName() << " юридическое лицо"
                                  << std::endl;
                    } else {
                        std::cout << counter + 1 << ". " << pair.first->getPersonalCode() << ": "
                                  << pair.first->getFullName() << " физическое лицо"
                                  << std::endl;
                    }

                    clients.push_back(pair.first);
                    counter++;
                }
                cout << "Выберите клиента(номер):\n";
                int client_number;
                cin >> client_number;
                Client *cur_client = clients[client_number - 1];
//                if (Bank::clientIsLegal(cur_client)){cout << "LEGAL";} else {cout << "PHYSICAL";}
                cout << "Что Вы хотите сделать:\n"
                        "1.Проверить баланс\n"
                        "2.Пополнить счет\n"
                        "3.Снять деньги\n"
                        "4.Перевести деньги на другой счет(внутри банка)\n"
                        "5.Перевести деньги на счет в другой банк(только для юридических лиц)\n";
                int do_code;
                cin >> do_code;
                if (do_code == 1)
                {
                    cur_client->checkBalance(cur_bank);
                }
                else if (do_code == 2)
                {
                    cout << "Введите сумму пополнения:\n";
                    float sum;
                    cin >> sum;
                    cur_client->depositMoney(cur_bank, sum);
                }
                else if (do_code == 3)
                {
                    cout << "Введите сумму, которую хотите снять:\n";
                    float sum;
                    cin >> sum;
                    cur_client->withdrawMoney(cur_bank, sum);
                }
                else if (do_code == 4)
                {
                    cout << "Кому Вы хотите перевести(введите соответствующую цифру)\n";
                    counter = 0;
                    for (auto const &pair: cur_bank->getClientsAccounts()) {
                        if (Bank::clientIsLegal(pair.first)) {
                            std::cout << counter + 1 << ". " << pair.first->getPersonalCode() << ": "
                                      << pair.first->getFullName() << " юридическое лицо"
                                      << std::endl;
                        } else {
                            std::cout << counter + 1 << ". " << pair.first->getPersonalCode() << ": "
                                      << pair.first->getFullName() << " физическое лицо"
                                      << std::endl;
                        }
                        counter++;
                    }
                    int receiver_code;
                    cin >> receiver_code;
                    cout << "Введите сумму для перевода \n";
                    float sum;
                    cin >> sum;
                    cur_client->transferMoney(cur_bank, clients[receiver_code - 1], sum);
                }
                else if (do_code == 5)
                {
                    if (!Bank::clientIsLegal(cur_client)) {
                        cout << "Функция доступна только юридическим лицам!";
                        continue;
                    }
                    Legal *legal_client = dynamic_cast<Legal*>(cur_client);
                    cout << "В какой банк будет выполнен перевод(введите соответствующую цифру)\n";
                    bankSystem->printBanks();
                    int receiver_bank_code;
                    cin >> receiver_bank_code;
                    Bank *receiver_bank = bankSystem->getBanks()[receiver_bank_code - 1];
                    cout << "Кому Вы хотите перевести(введите соответствующую цифру)\n";
                    counter = 0;
                    std::vector<Client*> receivers;
                    for (auto const &pair: receiver_bank->getClientsAccounts()) {
                        std::cout << counter + 1 << ". " << pair.first->getPersonalCode() << ": "
                                  << pair.first->getFullName()
                                  << std::endl;
                        receivers.push_back(pair.first);
                        counter++;
                    }
                    int receiver_code;
                    cin >> receiver_code;
                    cout << "Введите сумму для перевода \n";
                    float sum;
                    cin >> sum;
                    legal_client->makeTransferToAnotherBank(cur_bank, receiver_bank, receivers[receiver_code - 1], sum);
                }
            }
        }
        else if (action_code == 6)
        {
            break;
        }
    }
}