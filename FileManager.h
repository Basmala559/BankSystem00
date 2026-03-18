#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FilesManager : public DataSourceInterface {
public:
    void addClient(Client obj) override { FilesHelper::saveClient(obj); }
    void addEmployee(Employee obj) override { FilesHelper::saveEmployee(obj); }
    void addAdmin(Admin obj) override { FilesHelper::saveAdmin(obj); }

    void getAllClients() override { FilesHelper::getClients(); }
    void getAllEmployees() override { FilesHelper::getEmployees(); }
    void getAllAdmins() override { FilesHelper::getAdmins(); }

    void removeAllClients() override {
        FilesHelper::clearFile(C_FILE_Path, C_last_Id_path, 0);
    }
    void removeAllEmployees() override {
        FilesHelper::clearFile(E_FILE_Path, E_last_Id_path, 100);
    }
    void removeAllAdmins() override {
        FilesHelper::clearFile(A_File_path, A_Last_Id_path, 1000);
    }
};
