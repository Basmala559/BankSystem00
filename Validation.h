#pragma once
#include <iostream>
#include <string> 
#include <cctype>  
using namespace std;

class Validation {
public:
    static bool ValidateName(string name) {
        if (name.size() < 3 || name.size() > 20) return false;
        for (char c : name) { if (!isalpha(c)) return false; }
        return true;
    }
    static bool validatePass(string pass) {
        if (pass.length() < 8 || pass.length() > 20) return false;
        for (char c : pass) { if (c == ' ') return false; }
        return true;
    }
    static bool validateBalance(double balance) { return balance >= 1500; }
    static bool validateSalary(double Salary) { return Salary >= 5000; }
};
