#pragma once
#include <iostream>
#include <string>
#include "Client.h"
#include "Validation.h"
#include "FileManager.h"

using namespace std;

class ClientManager {
public:
    // عرض القائمة الخاصة بالعميل
    static void printClientMenu() {
        system("cls");
        cout << "==== Client Menu ====" << endl;
        cout << "(1) Display my info" << endl;
        cout << "(2) Check balance" << endl;
        cout << "(3) Update Password" << endl;
        cout << "(4) Withdraw" << endl;
        cout << "(5) Deposit" << endl;
        cout << "(6) Transfer amount" << endl;
        cout << "(7) Logout" << endl;
        cout << "=====================" << endl;
    }

    // عملية تسجيل الدخول للعميل
    static Client* login(int id, string password) {
        // البحث في الفيكتور allClients اللي انت عرفته في Client.h
        for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
            if (cIt->getId() == id && cIt->getpass() == password) {
                return &(*cIt); // إرجاع عنوان العميل اللي لقى بياناته صح
            }
        }
        return nullptr; // لو ملقاش العميل
    }

    // تحديث كلمة السر مع التحقق منها
    static void updatePassword(Person* person) {
        string newPass;
        do {
            cout << "Enter new password (8-20 chars, no spaces): ";
            cin >> newPass;
        } while (!Validation::validatePass(newPass)); // استخدام الـ Validation class بتاعك

        person->setpass(newPass);
        cout << "\nPassword updated successfully!" << endl;
    }

    // التحكم في اختيارات العميل
    static bool clientOptions(Client* client) {
        printClientMenu();
        int choice;
        double amount;
        cout << "Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            client->displayInfo();
            break;
        case 2:
            cout << "Current Balance: " << client->getBalance() << endl;
            break;
        case 3:
            updatePassword(client);
            // ملاحظة: هنا يفضل استدعاء save function لتحديث الملف
            break;
        case 4:
            cout << "Enter amount to withdraw: "; cin >> amount;
            client->withdraw(amount);
            break;
        case 5:
            cout << "Enter amount to deposit: "; cin >> amount;
            client->deposit(amount);
            break;
        case 6:
        {
            int recipientId;
            cout << "Enter recipient ID: "; cin >> recipientId;
            // منطق البحث عن المستلم للتحويل
            bool found = false;
            for (auto& recipient : allClients) {
                if (recipient.getId() == recipientId) {
                    cout << "Enter amount to transfer: "; cin >> amount;
                    client->transferTo(amount, recipient);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Recipient not found!" << endl;
        }
        break;
        case 7:
            return false; // الخروج من اللوب (Logout)
        default:
            cout << "Invalid choice! Please try again." << endl;
        }

        system("pause");
        return true; // الاستمرار في اللوب
    }
};
