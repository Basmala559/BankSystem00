#pragma once
#pragma once
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"


    class Screens {
    public:
        static void welcome() {
            cout << "--- Welcome to Our Bank System ---" << endl;
            system("pause");
        }

        static void loginScreen(int type) {
            int id; string pass;
            cout << "ID: "; cin >> id;
            cout << "Password: "; cin >> pass;

            if (type == 1) {
                Client* c = ClientManager::login(id, pass);
                if (c) while (ClientManager::clientOptions(c));
                else cout << "Invalid Login!" << endl;
            }
            else if (type == 2) {
                Employee* e = EmployeeManager::login(id, pass);
                if (e) while (EmployeeManager::employeeOptions(e));
                else cout << "Invalid Login!" << endl;
            }
            else if (type == 3) {
                Admin* a = AdminManager::login(id, pass);
                if (a) while (AdminManager::adminOptions(a));
                else cout << "Invalid Login!" << endl;
            }
        }

        static void runApp() {
            welcome();
            int choice;
            while (true) {
                system("cls");
                cout << "1- Client\n2- Employee\n3- Admin\n4- Exit\nChoice: ";
                cin >> choice;
                if (choice == 4) break;
                loginScreen(choice);
            }
        }
    };
