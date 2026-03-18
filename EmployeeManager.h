#pragma once
#include "Employee.h"
#include "ClientManager.h"

class EmployeeManager {
public:
    static void printEmployeeMenu() {
        system("cls");
        cout << "==== Employee Menu ====" << endl;
        cout << "(1) Add New Client\n(2) List All Clients\n(3) Search for Client\n(4) Display My Info\n(5) Update Password\n(6) Logout\nChoice: ";
    }

    static Employee* login(int id, string password) {
        for (int i = 0; i < allEmployees.size(); i++) {
            if (allEmployees[i].getId() == id && allEmployees[i].getpass() == password) {
                return &allEmployees[i];
            }
        }
        return nullptr;
    }

    static bool employeeOptions(Employee* employee) {
        printEmployeeMenu();
        int choice, id;
        cin >> choice;

        switch (choice) {
        case 1: {
            string n, p; double b;
            int nextId = FilesHelper::getLast(C_last_Id_path) + 1;
            cout << "Name: "; cin >> n; cout << "Pass: "; cin >> p; cout << "Balance: "; cin >> b;
            Client c(nextId, n, p, b);
            employee->addClient(c);
            FilesHelper::saveClient(c);
            break;
        }
        case 2: employee->listClients(); break;
        case 4: employee->displayInfo(); break;
        case 5: ClientManager::updatePassword(employee); break;
        case 6: return false;
        }
        system("pause");
        return true;
    }
};
