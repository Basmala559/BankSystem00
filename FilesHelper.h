#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "Parser.h"

using namespace std;

// المسارات بناءً على كودك
#define C_FILE_Path "data/Clients.txt"
#define E_FILE_Path "data/Employees.txt"
#define A_File_path "data/Admins.txt"
#define C_last_Id_path "data/LastClient'sID.txt"
#define E_last_Id_path "data/LastEmployee'sID.txt"
#define A_Last_Id_path "data/LastAdmin'sID.txt"

class FilesHelper {
public:
    static void saveLast(string fileName, int id) {
        ofstream file(fileName, ios::out);
        file << id;
        file.close();
    }

    static int getLast(string fileName) {
        ifstream file(fileName);
        int id = 0;
        if (file >> id) return id;
        return 0;
    }

    // الدالة اللي كانت ناقصة ومسببة Error
    static void clearFile(string fileName, string lastIdFile, int startID) {
        ofstream file(fileName, ios::out | ios::trunc);
        file.close();
        saveLast(lastIdFile, startID);
    }

    static void saveClient(Client c) {
        ofstream file(C_FILE_Path, ios::app);
        file << c.getId() << "|" << c.getName() << "|" << c.getpass() << "|" << c.getBalance() << endl;
        file.close();
        saveLast(C_last_Id_path, c.getId());
    }

    static void saveEmployee(Employee e) {
        ofstream file(E_FILE_Path, ios::app);
        file << e.getId() << "|" << e.getName() << "|" << e.getpass() << "|" << e.getSalary() << endl;
        file.close();
        saveLast(E_last_Id_path, e.getId());
    }

    static void saveAdmin(Admin a) {
        ofstream file(A_File_path, ios::app);
        file << a.getId() << "|" << a.getName() << "|" << a.getpass() << "|" << a.getSalary() << endl;
        file.close();
        saveLast(A_Last_Id_path, a.getId());
    }

    static void getClients() {
        allClients.clear();
        ifstream file(C_FILE_Path);
        string line;
        while (getline(file, line)) {
            if (!line.empty()) allClients.push_back(Parser::parseToClient(line));
        }
        file.close();
    }

    static void getEmployees() {
        allEmployees.clear();
        ifstream file(E_FILE_Path);
        string line;
        while (getline(file, line)) {
            if (!line.empty()) allEmployees.push_back(Parser::parseToEmployee(line));
        }
        file.close();
    }

    static void getAdmins() {
        allAdmins.clear();
        ifstream file(A_File_path);
        string line;
        while (getline(file, line)) {
            if (!line.empty()) allAdmins.push_back(Parser::parseToAdmin(line));
        }
        file.close();
    }
};
