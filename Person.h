#pragma once
#include "Validation.h"

class Person {
protected:
    int id;
    string name, password;
public:
    Person() { id = 0; }
    Person(int id, string name, string pass) {
        this->id = id;
        setName(name);
        setpass(pass);
    }
    void setId(int id) { this->id = id; }
    void setName(string name) { if (Validation::ValidateName(name)) this->name = name; }
    void setpass(string pass) { if (Validation::validatePass(pass)) password = pass; }
    int getId() { return id; }
    string getName() { return name; }
    string getpass() { return password; }
    virtual void displayInfo() {
        cout << "Id: " << id << "\nName: " << name << "\nPassword: " << password << endl;
    }
};
