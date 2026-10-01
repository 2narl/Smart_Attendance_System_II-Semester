

#include "Panels.h"

#include <iostream>
using namespace std;
int main()
{

    AdminPanel admin;
    SubAdminPanel subAdmin;
    StudentTeacherPanel studentTeacher;

    int choice = 0;
    clearScreen();

    do
    {
        cout << "==========================================\n";
        cout << "       ATTENDANCE MANAGEMENT SYSTEM\n";
        cout << "==========================================\n";
        cout << "1. Admin Login\n";
        cout << "2. Sub-Admin Login\n";
        cout << "3. Student / Teacher Login\n";
        cout << "4. System Help\n";
        cout << "5. Exit\n";
        cout << "\nEnter your choice: ";

        if (!readMenuChoice(choice))
        {
            clearScreen();
            continue;
        }

        switch (choice)
        {
        case 1:
            clearScreen();
            if (admin.login())
                admin.showPanel();
            waitForEnter();
            clearScreen();
            break;
        case 2:
            clearScreen();
            if (subAdmin.login())
                subAdmin.showPanel();
            waitForEnter();
            clearScreen();
            break;
        case 3:
            clearScreen();
            if (studentTeacher.login())
                studentTeacher.showPanel();
            waitForEnter();
            clearScreen();
            break;
        case 4:
            clearScreen();
            cout << "=== System Information & Help ===\n";
            cout << "1. Self registration is disabled.\n";
            cout << "2. New students and teachers must collect login credentials from an administrator.\n";
            cout << "3. Admin and Sub-Admin can manually override attendance.\n";
            cout << "Please contact the system administrator for assistance.\n";
            waitForEnter();
            clearScreen();
            break;
        case 5:
            cout << "\nExiting the program...\n";
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
            waitForEnter();
            clearScreen();
        }
    } while (choice != 5);

    return 0;
}
