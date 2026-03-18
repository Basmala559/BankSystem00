#pragma once
#include "Person.h"
#include "Client.h"

class Employee : public Person {
protected:
    double salary;
public:
    Employee() : Person() { salary = 0; }
    Employee(int id, string name, string pass, double salary) : Person(id, name, pass) {
        setSalary(salary);
    }
    void setSalary(double salary) { if (Validation::validateSalary(salary)) this->salary = salary; }
    double getSalary() { return salary; }

    void addClient(Client& client) { allClients.push_back(client); }
    Client* searchClient(int id) {
        for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
            if (cIt->getId() == id) return &(*cIt);
        }
        return nullptr;
    }
    void listClients() {
        for (auto& c : allClients) { c.displayInfo(); cout << "----------\n"; }
    }
    void displayInfo() { Person::displayInfo(); cout << "Salary: " << salary << endl; }
};

static vector<Employee> allEmployees;
static vector<Employee>::iterator eIt;
