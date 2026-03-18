#include <iostream>
#include "FileManager.h"
#include "Screens.h"

using namespace std;

int main() {
    FilesManager fm;
    // تحميل البيانات من الملفات
    fm.getAllClients();
    fm.getAllEmployees();
    fm.getAllAdmins();

    // تأمين الدخول لأول مرة لو الملفات فاضية
    if (allAdmins.empty()) {
        Admin admin(1, "admin", "12345678", 10000);
        allAdmins.push_back(admin);
        fm.addAdmin(admin);
    }

    // تشغيل التطبيق
    Screens::runApp();

    return 0;
}
