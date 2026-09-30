#ifndef AUTHENTICATION_BASE_H
#define AUTHENTICATION_BASE_H

#include "Common.h"

#include <string>
using namespace std;

class AuthenticationBase
{
protected:
    string currentUsername;
    string currentRole;

    void encryptUserRecord(UserRecord &user);
    void decryptUserRecord(UserRecord &user);

    bool usernameExists(const string &username);
    bool findUser(const string &username, UserRecord &result);
    bool findStudentByUsername(const string &username, StudentRecord &result);
    bool findStudentByRoll(const string &rollNumber, StudentRecord &result);
    bool findStudentByName(const string &name, StudentRecord &result);
    bool findTeacherByUsername(const string &username, TeacherRecord &result);
    bool findTeacherById(const string &teacherId, TeacherRecord &result);
    bool findStaffByUsername(const string &username, StaffRecord &result);
    bool rollNumberExists(const string &rollNumber);
    bool teacherIdExists(const string &teacherId);

    bool addUser(const string &username,
                 const string &password,
                 const string &role);
    bool addStudentRecord(const string &username,
                          const string &name,
                          const string &dateOfBirth,
                          const string &rollNumber,
                          const string &semester,
                          const string &subject,
                          const string &program,
                          const string &section);
    bool addTeacherRecord(const string &username,
                          const string &teacherId,
                          const string &name,
                          const string &dateOfBirth,
                          const string &department,
                          const string &qualification);
    bool addStaffRecord(const string &username,
                        const string &role,
                        const string &name,
                        const string &dateOfBirth,
                        const string &department);

    bool updateStudentRecord(const StudentRecord &updated);
    bool updateTeacherRecord(const string &username,
                             const string &name,
                             const string &dateOfBirth,
                             const string &department,
                             const string &qualification);
    bool updateUserCredentials(const string &username,
                               const string &newPassword,
                               const string &newRole);

    bool deleteUser(const string &username);
    bool deleteStudentRecord(const string &username);
    bool deleteTeacherRecord(const string &username);
    bool deleteAttendanceRecords(const string &username);
    bool deleteStudentAndRelatedData(const string &username);
    bool deleteTeacherAndRelatedData(const string &username);

    bool verifyCredentials(const string &username,
                           const string &password,
                           const string &role);

    bool saveAttendance(const string &username,
                        const string &role,
                        const string &rollNumber,
                        const string &semester,
                        const string &subject,
                        const string &date,
                        const string &status,
                        const string &markedBy);
    bool attendanceExists(const string &username,
                          const string &date,
                          const string &subject);
    bool updateAttendanceRecord(const string &username,
                                const string &date,
                                const string &subject,
                                const string &status,
                                const string &markedBy);
    bool markAttendance(const string &username,
                        const string &role,
                        const string &markedBy,
                        const string &date,
                        const string &status,
                        const string &subject);

    void readAttendance(const string &username,
                        const string &semesterFilter = "",
                        const string &subjectFilter = "");
    void viewAllStudentAttendanceByDate();
    void listAllStudents();

    void displayStudentDetails(const StudentRecord &student);
    void displayTeacherRecord(const TeacherRecord &teacher);
    void viewPersonalDetails();
    void viewTeacherDetails();
    void viewTeacherDetailsFor(const string &username);
    void viewTeacherAttendance();
    void updateTeacherDetails();
    void viewUserDetails();
    void updateUserDetails();

    std::string getProfileName(const string &username, const string &role);

    void addAccount(const string &roleRestriction);
    void studentManagement(const string &title);
    void teacherManagement(bool confirmBeforeDelete);
    void addStudent();
    void searchStudent();
    void updateStudent();
    void deleteStudent();
    void viewStudentAttendance();
    void viewAttendance();
    void manualAttendanceOverride();

    bool migrateLegacyStudentFile();
    bool migrateLegacyTeacherFile();
    bool ensureDefaultAccounts();
    void removeLegacyDefaultAccounts();
    void removeAccountsWithMissingProfiles();

public:
    AuthenticationBase();
    virtual ~AuthenticationBase() = default;
};

#endif
