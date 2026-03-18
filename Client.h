#pragma once
#include "Person.h"
#include <vector>

class Client : public Person {
    double balance;
public:
    Client() : Person() { balance = 0; }
    Client(int id, string name, string pass, double balance) : Person(id, name, pass) {
        setBalance(balance);
    }

    void setBalance(double balance) {
        if (Validation::validateBalance(balance)) this->balance = balance;
    }

    double getBalance() { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\nOperation Successful!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "\nOperation Successful!" << endl;
        }
        else cout << "\nInsufficient Balance!" << endl;
    }

    // الدالة اللي كانت ناقصة ومسببة Error في ClientManager
    void transferTo(double amount, Client& recipient) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            recipient.balance += amount;
            cout << "\nTransfer Successful!" << endl;
        }
        else cout << "\nTransfer Failed!" << endl;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Balance: " << balance << endl;
    }
};

static vector<Client> allClients;
static vector<Client>::iterator cIt;
