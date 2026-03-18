#pragma once
#include "Employee.h"

class Admin : public Employee {
public:
    Admin() : Employee() {}
    Admin(int id, string name, string pass, double salary)
        : Employee(id, name, pass, salary) {
    }

    // 1. الدالة المسببة للأخطاء الحمر في الصورة (addEmployee)
    void addEmployee(Employee& e) {
        allEmployees.push_back(e);
    }

    // 2. دالة التعديل (عشان case 4 تشتغل)
    void editEmployee(Employee* e, string name, string password, double salary) {
        e->setName(name);
        e->setpass(password);
        e->setSalary(salary);
    }

    // 3. دالة البحث (عشان case 3 تشتغل)
    Employee* searchEmployee(int id) {
        for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
            if (eIt->getId() == id) return &(*eIt);
        }
        return nullptr;
    }

    // 4. دالة العرض
    void listEmployees() {
        for (auto& e : allEmployees) {
            e.displayInfo();
            cout << "--------------------\n";
        }
    }
};

static vector<Admin> allAdmins;
