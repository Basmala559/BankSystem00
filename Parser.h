#pragma once
#include <sstream>
#include <vector>
#include "Admin.h"

class Parser {
public:
    static vector<string> split(string line) {
        vector<string> parts;
        stringstream ss(line);
        string part;
        while (getline(ss, part, '|')) parts.push_back(part);
        return parts;
    }
    static Client parseToClient(string line) {
        vector<string> p = split(line);
        return Client(stoi(p[0]), p[1], p[2], stod(p[3]));
    }
    static Employee parseToEmployee(string line) {
        vector<string> p = split(line);
        return Employee(stoi(p[0]), p[1], p[2], stod(p[3]));
    }
    static Admin parseToAdmin(string line) {
        vector<string> p = split(line);
        return Admin(stoi(p[0]), p[1], p[2], stod(p[3]));
    }
};
