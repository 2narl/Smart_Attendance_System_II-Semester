
#include "Panels.h"

#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
/*Default accounts: admin / admin123 and subadmin / sub123.*/

bool AdminPanel::login()
{
    string username;
    string password;

    cout << "\n========== ADMIN LOGIN ==========\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (verifyCredentials(username, password, "Admin"))
    {
        cout << "\nLogin successful!\n";
        cout << "Welcome Admin, " << getProfileName(username, "Admin") << "!\n";
        return true;
    }

    cout << "\nInvalid Admin credentials.\n";
    return false;
}

void AdminPanel::showPanel()
{
    int choice = 0;

    do
    {
        clearScreen();
        cout << "====================================\n";
        cout << "           ADMIN PANEL\n";
        cout << "====================================\n";
        cout << "Welcome, " << currentUsername << "!\n";
        cout << "1. User Management\n";
        cout << "2. Student Management\n";
        cout << "3. Teacher Management\n";
        cout << "4. View User Attendance\n";
        cout << "5. Manual Attendance Mark/Override\n";
        cout << "6. System Configuration\n";
        cout << "7. View My Personal Details\n";
        cout << "8. Logout\n";
        cout << "\nEnter choice: ";

        if (!readMenuChoice(choice))
            continue;

        switch (choice)
        {
        case 1:
            userManagement();
            break;
        case 2:
            studentManagement("STUDENT MANAGEMENT");
            break;
        case 3:
            teacherManagement(true);
            break;
        case 4:
            viewAttendance();
            waitForEnter();
            break;
        case 5:
            manualAttendanceOverride();
            waitForEnter();
            break;
        case 6:
            systemConfiguration();
            break;
        case 7:
            viewPersonalDetails();
            waitForEnter();
            break;
        case 8:
            cout << "\nAdmin logged out.\n";
            break;
        default:
            cout << "\nInvalid choice.\n";
            waitForEnter();
        }
    } while (choice != 8);
}

void AdminPanel::userManagement()
{
    int choice = 0;

    do
    {
        clearScreen();
        cout << "\n========== USER MANAGEMENT ==========\n";
        cout << "1. Add Admin/SubAdmin\n";
        cout << "2. View User Details\n";
        cout << "3. Search User\n";
        cout << "4. Update Admin/SubAdmin\n";
        cout << "5. Delete User\n";
        cout << "6. Back\n";
        cout << "\nEnter choice: ";

        if (!readMenuChoice(choice))
            continue;

        switch (choice)
        {
        case 1:
            addAccount("Admin/SubAdmin");
            waitForEnter();
            break;
        case 2:
        case 3:
            viewUserDetails();
            waitForEnter();
            break;
        case 4:
            updateUserDetails();
            waitForEnter();
            break;
        case 5:
        {
            string username;
            char confirmation = 'N';
            cout << "\nEnter username to delete: ";
            cin >> username;

            UserRecord user;
            if (!findUser(username, user))
            {
                cout << "\nUser not found.\n";
                waitForEnter();
                break;
            }

            if (equalsIgnoreCase(username, currentUsername))
            {
                cout << "\nYou cannot delete the account you are using.\n";
                waitForEnter();
                break;
            }

            cout << "\n========== USER DETAILS ==========\n";
            cout << "Username: " << user.username << endl;
            cout << "Role    : " << user.role << endl;
            cout << "Delete this user? (Y/N): ";
            cin >> confirmation;

            if (std::toupper(static_cast<unsigned char>(confirmation)) != 'Y')
            {
                cout << "\nDeletion cancelled.\n";
                waitForEnter();
                break;
            }

            bool deleted = false;
            if (equalsIgnoreCase(user.role, "Student"))
                deleted = deleteStudentAndRelatedData(username);
            else if (equalsIgnoreCase(user.role, "Teacher"))
                deleted = deleteTeacherAndRelatedData(username);
            else
                deleted = deleteUser(username);

            if (deleted)
                cout << "\nUser deleted successfully.\n";
            else
                cout << "\nUser deletion failed.\n";

            waitForEnter();
            break;
        }
        case 6:
            break;
        default:
            cout << "\nInvalid choice.\n";
            waitForEnter();
        }
    } while (choice != 6);
}

void AdminPanel::systemConfiguration()
{
    int choice = 0;

    do
    {
        clearScreen();
        cout << "\n========== SYSTEM CONFIGURATION ==========\n";
        cout << "1. System settings\n";
        cout << "2. Attendance settings\n";
        cout << "3. User management settings\n";
        cout << "4. Back\n";
        cout << "\nEnter choice: ";

        if (!readMenuChoice(choice))
            continue;

        switch (choice)
        {
        case 1:
            cout << "\n========== SYSTEM SETTINGS ==========\n";
            cout << "Current date: " << getCurrentDate() << endl;
            cout << "Date format : YYYY-MM-DD\n";
            waitForEnter();
            break;
        case 2:
            cout << "\n========== ATTENDANCE SETTINGS ==========\n";
            cout << "Allowed statuses: Present, Absent, Late\n";
            cout << "Date format     : YYYY-MM-DD\n";
            cout << "Duplicate entries for the same user, date and subject are blocked.\n";
            waitForEnter();
            break;
        case 3:
        {
            ifstream file(CREDENTIAL_FILE, ios::binary);
            int adminCount = 0;
            int subAdminCount = 0;
            int teacherCount = 0;
            int studentCount = 0;
            UserRecord user;

            if (file.is_open())
            {
                while (file.read(reinterpret_cast<char *>(&user), sizeof(UserRecord)))
                {
                    decryptUserRecord(user);

                    if (std::strcmp(user.role, "Admin") == 0)
                        ++adminCount;
                    else if (std::strcmp(user.role, "SubAdmin") == 0)
                        ++subAdminCount;
                    else if (std::strcmp(user.role, "Teacher") == 0)
                        ++teacherCount;
                    else if (std::strcmp(user.role, "Student") == 0)
                        ++studentCount;
                }
            }

            cout << "\n======= USER MANAGEMENT SETTINGS =======\n";
            cout << "Admin users     : " << adminCount << endl;
            cout << "Sub-Admin users : " << subAdminCount << endl;
            cout << "Teacher users   : " << teacherCount << endl;
            cout << "Student users   : " << studentCount << endl;
            waitForEnter();
            break;
        }
        case 4:
            break;
        default:
            cout << "\nInvalid choice.\n";
            waitForEnter();
        }
    } while (choice != 4);
}

bool SubAdminPanel::login()
{
    string username;
    string password;

    cout << "\n======== SUB-ADMIN LOGIN ========\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (verifyCredentials(username, password, "SubAdmin"))
    {
        cout << "\nLogin successful!\n";
        cout << "Welcome Sub-Admin, "
             << getProfileName(username, "SubAdmin") << "!\n";
        return true;
    }

    cout << "\nInvalid Sub-Admin credentials.\n";
    return false;
}

void SubAdminPanel::showPanel()
{
    int choice = 0;

    do
    {
        clearScreen();
        cout << "====================================\n";
        cout << "         SUB-ADMIN PANEL\n";
        cout << "====================================\n";
        cout << "Welcome, " << currentUsername << "!\n";
        cout << "1. Add Student/Teacher\n";
        cout << "2. Student Management\n";
        cout << "3. Teacher Management\n";
        cout << "4. View Attendance\n";
        cout << "5. Manual Attendance Override\n";
        cout << "6. View My Personal Details\n";
        cout << "7. Logout\n";
        cout << "\nEnter choice: ";

        if (!readMenuChoice(choice))
            continue;

        switch (choice)
        {
        case 1:
            addAccount("Student/Teacher");
            waitForEnter();
            break;
        case 2:
            studentManagement("SUB-ADMIN STUDENT MANAGEMENT");
            break;
        case 3:
            teacherManagement(true);
            break;
        case 4:
            viewAttendance();
            waitForEnter();
            break;
        case 5:
            manualAttendanceOverride();
            waitForEnter();
            break;
        case 6:
            viewPersonalDetails();
            waitForEnter();
            break;
        case 7:
            cout << "\nSub-Admin logged out.\n";
            break;
        default:
            cout << "\nInvalid choice.\n";
            waitForEnter();
        }
    } while (choice != 7);
}

bool StudentTeacherPanel::login()
{
    string username;
    string password;
    string role;

    cout << "\n===== STUDENT / TEACHER LOGIN =====\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Role (S-Student/T-Teacher): ";
    cin >> role;

    if (role == "S" || role == "s")
        role = "Student";
    else if (role == "T" || role == "t")
        role = "Teacher";
    else
    {
        cout << "\nInvalid role. Enter S for Student or T for Teacher.\n";
        return false;
    }

    if (verifyCredentials(username, password, role))
    {
        cout << "\nLogin successful!\n";
        cout << "Welcome " << getProfileName(username, role) << "!\n";
        return true;
    }

    cout << "\nInvalid username, password or role.\n";
    return false;
}

void StudentTeacherPanel::showPanel()
{
    int choice = 0;

    do
    {
        clearScreen();
        cout << "====================================\n";
        cout << "       STUDENT / TEACHER PANEL\n";
        cout << "====================================\n";
        cout << "Welcome, "
             << getProfileName(currentUsername, currentRole) << "!\n";
        cout << "Logged in as: " << currentUsername << endl;
        cout << "Role: " << currentRole << endl;

        StudentRecord student;
        if (findStudentByUsername(currentUsername, student))
        {
            cout << "\nRoll Number : " << student.rollNumber << endl;
            cout << "Semester    : " << student.semester << endl;
            cout << "Subject     : " << student.subject << endl;
            cout << "Program     : " << student.program << endl;
            cout << "Section     : " << student.section << endl;
        }

        cout << "\n1. View My Attendance\n";
        cout << "2. Mark My Attendance\n";
        cout << "3. View My Personal Details\n";
        cout << "4. Logout\n";
        cout << "\nEnter choice: ";

        if (!readMenuChoice(choice))
            continue;

        switch (choice)
        {
        case 1:
            readAttendance(currentUsername);
            waitForEnter();
            break;
        case 2:
            if (markAttendance(currentUsername,
                               currentRole,
                               currentUsername,
                               getCurrentDate(),
                               "Present",
                               ""))
            {
                cout << "\nYour attendance has been marked.\n";
            }
            else
            {
                cout << "\nUnable to mark attendance.\n";
            }
            waitForEnter();
            break;
        case 3:
            viewPersonalDetails();
            waitForEnter();
            break;
        case 4:
            cout << "\nLogged out successfully.\n";
            break;
        default:
            cout << "\nInvalid choice.\n";
            waitForEnter();
        }
    } while (choice != 4);
}
