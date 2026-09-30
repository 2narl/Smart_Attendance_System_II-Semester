#include "AuthenticationBase.h"

#include <cctype>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;
using std::vector;

namespace
{
    bool finalizeFileRewrite(ifstream &inFile,
                             ofstream &outFile,
                             const char *originalFile,
                             const char *temporaryFile)
    {
        outFile.flush();
        const bool inputGood = !inFile.bad();
        inFile.close();
        outFile.close();

        if (!inputGood || !outFile)
        {
            std::remove(temporaryFile);
            return false;
        }

        return replaceFile(originalFile, temporaryFile);
    }
}

AuthenticationBase::AuthenticationBase()
{
    ensureDefaultAccounts();
}

void AuthenticationBase::encryptUserRecord(UserRecord &user)
{
    xorTransform(user.username, sizeof(user.username));
    xorTransform(user.password, sizeof(user.password));
}

void AuthenticationBase::decryptUserRecord(UserRecord &user)
{
    xorTransform(user.username, sizeof(user.username));
    xorTransform(user.password, sizeof(user.password));
}

bool AuthenticationBase::usernameExists(const string &username)
{
    UserRecord user;
    return findUser(username, user);
}

bool AuthenticationBase::findUser(const string &username, UserRecord &result)
{
    if (!hasValidRecordSize(CREDENTIAL_FILE, sizeof(UserRecord)))
    {
        cout << "Error: Credentials file is corrupted.\n";
        return false;
    }

    ifstream file(CREDENTIAL_FILE, ios::binary);
    if (!file.is_open())
        return false;

    UserRecord user;
    while (file.read(reinterpret_cast<char *>(&user), sizeof(UserRecord)))
    {
        decryptUserRecord(user);
        if (equalsIgnoreCase(user.username, username))
        {
            result = user;
            return true;
        }
    }

    return false;
}

bool AuthenticationBase::findStudentByUsername(const string &username,
                                               StudentRecord &result)
{
    if (!hasValidRecordSize(STUDENT_FILE, sizeof(StudentRecord)))
    {
        cout << "Error: Student file is corrupted.\n";
        return false;
    }

    ifstream file(STUDENT_FILE, ios::binary);
    if (!file.is_open())
        return false;

    StudentRecord student;
    while (file.read(reinterpret_cast<char *>(&student), sizeof(StudentRecord)))
    {
        if (equalsIgnoreCase(student.username, username))
        {
            result = student;
            return true;
        }
    }

    return false;
}

bool AuthenticationBase::findStudentByRoll(const string &rollNumber,
                                           StudentRecord &result)
{
    if (!hasValidRecordSize(STUDENT_FILE, sizeof(StudentRecord)))
    {
        cout << "Error: Student file is corrupted.\n";
        return false;
    }

    ifstream file(STUDENT_FILE, ios::binary);
    if (!file.is_open())
        return false;

    StudentRecord student;
    while (file.read(reinterpret_cast<char *>(&student), sizeof(StudentRecord)))
    {
        if (equalsIgnoreCase(student.rollNumber, rollNumber))
        {
            result = student;
            return true;
        }
    }

    return false;
}

bool AuthenticationBase::findStudentByName(const string &name,
                                           StudentRecord &result)
{
    if (!hasValidRecordSize(STUDENT_FILE, sizeof(StudentRecord)))
        return false;

    ifstream file(STUDENT_FILE, ios::binary);
    if (!file.is_open())
        return false;

    StudentRecord student;
    while (file.read(reinterpret_cast<char *>(&student), sizeof(StudentRecord)))
    {
        if (equalsIgnoreCase(student.name, name))
        {
            result = student;
            return true;
        }
    }

    return false;
}

bool AuthenticationBase::findTeacherByUsername(const string &username,
                                               TeacherRecord &result)
{
    if (!hasValidRecordSize(TEACHER_FILE, sizeof(TeacherRecord)))
    {
        cout << "Error: Teacher file is corrupted.\n";
        return false;
    }

    ifstream file(TEACHER_FILE, ios::binary);
    if (!file.is_open())
        return false;

    TeacherRecord teacher;
    while (file.read(reinterpret_cast<char *>(&teacher), sizeof(TeacherRecord)))
    {
        if (equalsIgnoreCase(teacher.username, username))
        {
            result = teacher;
            return true;
        }
    }

    return false;
}

bool AuthenticationBase::findTeacherById(const string &teacherId,
                                         TeacherRecord &result)
{
    if (!hasValidRecordSize(TEACHER_FILE, sizeof(TeacherRecord)))
        return false;

    ifstream file(TEACHER_FILE, ios::binary);
    if (!file.is_open())
        return false;

    TeacherRecord teacher;
    while (file.read(reinterpret_cast<char *>(&teacher), sizeof(TeacherRecord)))
    {
        if (equalsIgnoreCase(teacher.teacherId, teacherId))
        {
            result = teacher;
            return true;
        }
    }

    return false;
}

bool AuthenticationBase::findStaffByUsername(const string &username,
                                             StaffRecord &result)
{
    if (!hasValidRecordSize(STAFF_FILE, sizeof(StaffRecord)))
        return false;

    ifstream file(STAFF_FILE, ios::binary);
    if (!file.is_open())
        return false;

    StaffRecord staff;
    while (file.read(reinterpret_cast<char *>(&staff), sizeof(StaffRecord)))
    {
        if (equalsIgnoreCase(staff.username, username))
        {
            result = staff;
            return true;
        }
    }

    return false;
}

bool AuthenticationBase::rollNumberExists(const string &rollNumber)
{
    StudentRecord student;
    return findStudentByRoll(rollNumber, student);
}

bool AuthenticationBase::teacherIdExists(const string &teacherId)
{
    TeacherRecord teacher;
    return findTeacherById(teacherId, teacher);
}

bool AuthenticationBase::addUser(const string &username,
                                 const string &password,
                                 const string &role)
{
    if (!fitsField(username, sizeof(UserRecord::username)) ||
        !fitsField(password, sizeof(UserRecord::password)) ||
        !fitsField(role, sizeof(UserRecord::role)))
    {
        cout << "Error: User input is empty or too long.\n";
        return false;
    }

    if (usernameExists(username))
    {
        cout << "\nError: Username already exists.\n";
        return false;
    }

    ofstream file(CREDENTIAL_FILE, ios::binary | ios::app);
    if (!file.is_open())
    {
        cout << "Error: Cannot open credential file.\n";
        return false;
    }

    UserRecord user{};
    copyToField(user.username, username, sizeof(user.username));
    copyToField(user.password, password, sizeof(user.password));
    copyToField(user.role, role, sizeof(user.role));
    encryptUserRecord(user);

    file.write(reinterpret_cast<char *>(&user), sizeof(UserRecord));
    return static_cast<bool>(file);
}

bool AuthenticationBase::addStudentRecord(const string &username,
                                          const string &name,
                                          const string &dateOfBirth,
                                          const string &rollNumber,
                                          const string &semester,
                                          const string &subject,
                                          const string &program,
                                          const string &section)
{
    if (!fitsField(username, sizeof(StudentRecord::username)) ||
        !fitsField(name, sizeof(StudentRecord::name)) ||
        !fitsField(dateOfBirth, sizeof(StudentRecord::dateOfBirth)) ||
        !isValidBirthDate(dateOfBirth) ||
        !fitsField(rollNumber, sizeof(StudentRecord::rollNumber)) ||
        !fitsField(semester, sizeof(StudentRecord::semester)) ||
        !fitsField(subject, sizeof(StudentRecord::subject)) ||
        !fitsField(program, sizeof(StudentRecord::program)) ||
        !fitsField(section, sizeof(StudentRecord::section)))
    {
        cout << "\nInvalid student academic details.\n";
        return false;
    }

    StudentRecord existingStudent;
    if (findStudentByUsername(username, existingStudent))
        return false;

    if (rollNumberExists(rollNumber))
    {
        cout << "\nError: Roll Number already exists.\n";
        return false;
    }

    ofstream file(STUDENT_FILE, ios::binary | ios::app);
    if (!file.is_open())
    {
        cout << "Error: Cannot open student file.\n";
        return false;
    }

    StudentRecord student{};
    copyToField(student.username, username, sizeof(student.username));
    copyToField(student.name, name, sizeof(student.name));
    copyToField(student.dateOfBirth, dateOfBirth, sizeof(student.dateOfBirth));
    copyToField(student.rollNumber, rollNumber, sizeof(student.rollNumber));
    copyToField(student.semester, semester, sizeof(student.semester));
    copyToField(student.subject, subject, sizeof(student.subject));
    copyToField(student.program, program, sizeof(student.program));
    copyToField(student.section, section, sizeof(student.section));

    file.write(reinterpret_cast<char *>(&student), sizeof(StudentRecord));
    return static_cast<bool>(file);
}

bool AuthenticationBase::addTeacherRecord(const string &username,
                                          const string &teacherId,
                                          const string &name,
                                          const string &dateOfBirth,
                                          const string &department,
                                          const string &qualification)
{
    if (!fitsField(username, sizeof(TeacherRecord::username)) ||
        !fitsField(teacherId, sizeof(TeacherRecord::teacherId)) ||
        teacherIdExists(teacherId) ||
        !fitsField(name, sizeof(TeacherRecord::name)) ||
        !fitsField(dateOfBirth, sizeof(TeacherRecord::dateOfBirth)) ||
        !isValidBirthDate(dateOfBirth) ||
        !fitsField(department, sizeof(TeacherRecord::department)) ||
        !fitsField(qualification, sizeof(TeacherRecord::qualification)))
    {
        cout << "Error: Invalid teacher details.\n";
        return false;
    }

    TeacherRecord existingTeacher;
    if (findTeacherByUsername(username, existingTeacher))
        return false;

    ofstream file(TEACHER_FILE, ios::binary | ios::app);
    if (!file.is_open())
        return false;

    TeacherRecord teacher{};
    copyToField(teacher.username, username, sizeof(teacher.username));
    copyToField(teacher.teacherId, teacherId, sizeof(teacher.teacherId));
    copyToField(teacher.name, name, sizeof(teacher.name));
    copyToField(teacher.dateOfBirth, dateOfBirth, sizeof(teacher.dateOfBirth));
    copyToField(teacher.department, department, sizeof(teacher.department));
    copyToField(teacher.qualification, qualification, sizeof(teacher.qualification));

    file.write(reinterpret_cast<char *>(&teacher), sizeof(TeacherRecord));
    return static_cast<bool>(file);
}

bool AuthenticationBase::addStaffRecord(const string &username,
                                        const string &role,
                                        const string &name,
                                        const string &dateOfBirth,
                                        const string &department)
{
    if (!fitsField(username, sizeof(StaffRecord::username)) ||
        !fitsField(role, sizeof(StaffRecord::role)) ||
        !fitsField(name, sizeof(StaffRecord::name)) ||
        !fitsField(dateOfBirth, sizeof(StaffRecord::dateOfBirth)) ||
        !isValidBirthDate(dateOfBirth) ||
        !fitsField(department, sizeof(StaffRecord::department)))
        return false;

    StaffRecord existing;
    if (findStaffByUsername(username, existing))
        return false;

    ofstream file(STAFF_FILE, ios::binary | ios::app);
    if (!file.is_open())
        return false;

    StaffRecord staff{};
    copyToField(staff.username, username, sizeof(staff.username));
    copyToField(staff.role, role, sizeof(staff.role));
    copyToField(staff.name, name, sizeof(staff.name));
    copyToField(staff.dateOfBirth, dateOfBirth, sizeof(staff.dateOfBirth));
    copyToField(staff.department, department, sizeof(staff.department));

    file.write(reinterpret_cast<char *>(&staff), sizeof(StaffRecord));
    return static_cast<bool>(file);
}

bool AuthenticationBase::updateStudentRecord(const StudentRecord &updated)
{
    if (updated.name[0] == '\0' ||
        !isValidBirthDate(updated.dateOfBirth) ||
        updated.rollNumber[0] == '\0' ||
        updated.semester[0] == '\0' ||
        updated.subject[0] == '\0' ||
        updated.program[0] == '\0' ||
        updated.section[0] == '\0')
    {
        cout << "Error: Invalid student details.\n";
        return false;
    }

    if (!hasValidRecordSize(STUDENT_FILE, sizeof(StudentRecord)))
    {
        cout << "Error: Student file is corrupted.\n";
        return false;
    }

    ifstream inFile(STUDENT_FILE, ios::binary);
    ofstream outFile(TEMP_STUDENT_FILE, ios::binary);
    if (!inFile.is_open() || !outFile.is_open())
        return false;

    StudentRecord student;
    bool found = false;

    while (inFile.read(reinterpret_cast<char *>(&student), sizeof(StudentRecord)))
    {
        if (equalsIgnoreCase(student.username, updated.username))
        {
            outFile.write(reinterpret_cast<const char *>(&updated),
                          sizeof(StudentRecord));
            found = true;
        }
        else
        {
            outFile.write(reinterpret_cast<char *>(&student),
                          sizeof(StudentRecord));
        }
    }

    if (!found)
    {
        inFile.close();
        outFile.close();
        std::remove(TEMP_STUDENT_FILE);
        return false;
    }

    return finalizeFileRewrite(inFile, outFile, STUDENT_FILE, TEMP_STUDENT_FILE);
}

bool AuthenticationBase::updateTeacherRecord(const string &username,
                                             const string &name,
                                             const string &dateOfBirth,
                                             const string &department,
                                             const string &qualification)
{
    if (!fitsField(name, sizeof(TeacherRecord::name)) ||
        !fitsField(dateOfBirth, sizeof(TeacherRecord::dateOfBirth)) ||
        !isValidBirthDate(dateOfBirth) ||
        !fitsField(department, sizeof(TeacherRecord::department)) ||
        !fitsField(qualification, sizeof(TeacherRecord::qualification)))
        return false;

    ifstream inFile(TEACHER_FILE, ios::binary);
    ofstream outFile(TEMP_TEACHER_FILE, ios::binary);
    if (!inFile.is_open() || !outFile.is_open())
        return false;

    TeacherRecord teacher;
    bool found = false;

    while (inFile.read(reinterpret_cast<char *>(&teacher), sizeof(TeacherRecord)))
    {
        if (equalsIgnoreCase(teacher.username, username))
        {
            copyToField(teacher.name, name, sizeof(teacher.name));
            copyToField(teacher.dateOfBirth, dateOfBirth, sizeof(teacher.dateOfBirth));
            copyToField(teacher.department, department, sizeof(teacher.department));
            copyToField(teacher.qualification, qualification, sizeof(teacher.qualification));
            found = true;
        }

        outFile.write(reinterpret_cast<char *>(&teacher), sizeof(TeacherRecord));
    }

    if (!found)
    {
        inFile.close();
        outFile.close();
        std::remove(TEMP_TEACHER_FILE);
        return false;
    }

    return finalizeFileRewrite(inFile, outFile, TEACHER_FILE, TEMP_TEACHER_FILE);
}

bool AuthenticationBase::updateUserCredentials(const string &username,
                                               const string &newPassword,
                                               const string &newRole)
{
    if (!fitsField(newPassword, sizeof(UserRecord::password)) ||
        !fitsField(newRole, sizeof(UserRecord::role)))
        return false;

    if (!hasValidRecordSize(CREDENTIAL_FILE, sizeof(UserRecord)))
        return false;

    ifstream inFile(CREDENTIAL_FILE, ios::binary);
    ofstream outFile(TEMP_CREDENTIAL_FILE, ios::binary);
    if (!inFile.is_open() || !outFile.is_open())
        return false;

    UserRecord user;
    bool found = false;

    while (inFile.read(reinterpret_cast<char *>(&user), sizeof(UserRecord)))
    {
        decryptUserRecord(user);

        if (equalsIgnoreCase(user.username, username))
        {
            copyToField(user.password, newPassword, sizeof(user.password));
            copyToField(user.role, newRole, sizeof(user.role));
            found = true;
        }

        encryptUserRecord(user);
        outFile.write(reinterpret_cast<char *>(&user), sizeof(UserRecord));
    }

    if (!found)
    {
        inFile.close();
        outFile.close();
        std::remove(TEMP_CREDENTIAL_FILE);
        return false;
    }

    return finalizeFileRewrite(inFile, outFile, CREDENTIAL_FILE, TEMP_CREDENTIAL_FILE);
}

bool AuthenticationBase::deleteUser(const string &username)
{
    if (!hasValidRecordSize(CREDENTIAL_FILE, sizeof(UserRecord)))
    {
        cout << "Error: Credentials file is corrupted.\n";
        return false;
    }

    ifstream inFile(CREDENTIAL_FILE, ios::binary);
    if (!inFile.is_open())
        return false;

    ofstream outFile(TEMP_CREDENTIAL_FILE, ios::binary);
    if (!outFile.is_open())
        return false;

    UserRecord user;
    bool found = false;

    while (inFile.read(reinterpret_cast<char *>(&user), sizeof(UserRecord)))
    {
        decryptUserRecord(user);

        if (equalsIgnoreCase(user.username, username))
        {
            found = true;
            continue;
        }

        encryptUserRecord(user);
        outFile.write(reinterpret_cast<char *>(&user), sizeof(UserRecord));
    }

    if (!found)
    {
        inFile.close();
        outFile.close();
        std::remove(TEMP_CREDENTIAL_FILE);
        return false;
    }

    return finalizeFileRewrite(inFile, outFile, CREDENTIAL_FILE, TEMP_CREDENTIAL_FILE);
}

bool AuthenticationBase::deleteStudentRecord(const string &username)
{
    if (!hasValidRecordSize(STUDENT_FILE, sizeof(StudentRecord)))
    {
        cout << "Error: Student file is corrupted.\n";
        return false;
    }

    ifstream inFile(STUDENT_FILE, ios::binary);
    if (!inFile.is_open())
        return true;

    ofstream outFile(TEMP_STUDENT_FILE, ios::binary);
    if (!outFile.is_open())
        return false;

    StudentRecord student;
    bool found = false;

    while (inFile.read(reinterpret_cast<char *>(&student), sizeof(StudentRecord)))
    {
        if (equalsIgnoreCase(student.username, username))
        {
            found = true;
            continue;
        }

        outFile.write(reinterpret_cast<char *>(&student), sizeof(StudentRecord));
    }

    if (!found)
    {
        inFile.close();
        outFile.close();
        std::remove(TEMP_STUDENT_FILE);
        return false;
    }

    return finalizeFileRewrite(inFile, outFile, STUDENT_FILE, TEMP_STUDENT_FILE);
}

bool AuthenticationBase::deleteTeacherRecord(const string &username)
{
    if (!hasValidRecordSize(TEACHER_FILE, sizeof(TeacherRecord)))
        return false;

    ifstream inFile(TEACHER_FILE, ios::binary);
    if (!inFile.is_open())
        return true;

    ofstream outFile(TEMP_TEACHER_FILE, ios::binary);
    if (!outFile.is_open())
        return false;

    TeacherRecord teacher;
    while (inFile.read(reinterpret_cast<char *>(&teacher), sizeof(TeacherRecord)))
    {
        if (!equalsIgnoreCase(teacher.username, username))
        {
            outFile.write(reinterpret_cast<char *>(&teacher), sizeof(TeacherRecord));
        }
    }

    return finalizeFileRewrite(inFile, outFile, TEACHER_FILE, TEMP_TEACHER_FILE);
}

bool AuthenticationBase::deleteAttendanceRecords(const string &username)
{
    if (!hasValidRecordSize(ATTENDANCE_FILE, sizeof(AttendanceRecord)))
    {
        cout << "Error: Attendance file is corrupted.\n";
        return false;
    }

    ifstream inFile(ATTENDANCE_FILE, ios::binary);
    if (!inFile.is_open())
        return true;

    ofstream outFile(TEMP_ATTENDANCE_FILE, ios::binary);
    if (!outFile.is_open())
        return false;

    AttendanceRecord record;
    while (inFile.read(reinterpret_cast<char *>(&record), sizeof(AttendanceRecord)))
    {
        if (!equalsIgnoreCase(record.username, username))
        {
            outFile.write(reinterpret_cast<char *>(&record),
                          sizeof(AttendanceRecord));
        }
    }

    return finalizeFileRewrite(inFile, outFile, ATTENDANCE_FILE, TEMP_ATTENDANCE_FILE);
}

bool AuthenticationBase::deleteStudentAndRelatedData(const string &username)
{
    return deleteAttendanceRecords(username) &&
           deleteStudentRecord(username) &&
           deleteUser(username);
}

bool AuthenticationBase::deleteTeacherAndRelatedData(const string &username)
{
    return deleteAttendanceRecords(username) &&
           deleteTeacherRecord(username) &&
           deleteUser(username);
}

bool AuthenticationBase::verifyCredentials(const string &username,
                                           const string &password,
                                           const string &role)
{
    if (!hasValidRecordSize(CREDENTIAL_FILE, sizeof(UserRecord)))
    {
        cout << "Error: Credentials file is corrupted.\n";
        return false;
    }

    UserRecord user;
    if (!findUser(username, user))
        return false;

    if (std::strcmp(user.password, password.c_str()) != 0)
        return false;

    if (std::strcmp(user.role, role.c_str()) != 0)
        return false;

    currentUsername = user.username;
    currentRole = user.role;
    return true;
}

bool AuthenticationBase::saveAttendance(const string &username,
                                        const string &role,
                                        const string &rollNumber,
                                        const string &semester,
                                        const string &subject,
                                        const string &date,
                                        const string &status,
                                        const string &markedBy)
{
    if (!fitsField(username, sizeof(AttendanceRecord::username)) ||
        !fitsField(role, sizeof(AttendanceRecord::role)) ||
        !fitsField(rollNumber, sizeof(AttendanceRecord::rollNumber)) ||
        !fitsField(semester, sizeof(AttendanceRecord::semester)) ||
        !fitsField(subject, sizeof(AttendanceRecord::subject)) ||
        !fitsField(date, sizeof(AttendanceRecord::date)) ||
        !fitsField(status, sizeof(AttendanceRecord::status)) ||
        !fitsField(markedBy, sizeof(AttendanceRecord::markedBy)))
    {
        cout << "Error: Attendance input is empty or too long.\n";
        return false;
    }

    ofstream file(ATTENDANCE_FILE, ios::binary | ios::app);
    if (!file.is_open())
    {
        cout << "Error: Cannot open attendance file.\n";
        return false;
    }

    AttendanceRecord record{};
    copyToField(record.username, username, sizeof(record.username));
    copyToField(record.role, role, sizeof(record.role));
    copyToField(record.rollNumber, rollNumber, sizeof(record.rollNumber));
    copyToField(record.semester, semester, sizeof(record.semester));
    copyToField(record.subject, subject, sizeof(record.subject));
    copyToField(record.date, date, sizeof(record.date));
    copyToField(record.status, status, sizeof(record.status));
    copyToField(record.markedBy, markedBy, sizeof(record.markedBy));

    file.write(reinterpret_cast<char *>(&record), sizeof(AttendanceRecord));
    return static_cast<bool>(file);
}

bool AuthenticationBase::attendanceExists(const string &username,
                                          const string &date,
                                          const string &subject)
{
    if (!hasValidRecordSize(ATTENDANCE_FILE, sizeof(AttendanceRecord)))
    {
        cout << "Error: Attendance file is corrupted.\n";
        return false;
    }

    ifstream file(ATTENDANCE_FILE, ios::binary);
    if (!file.is_open())
        return false;

    AttendanceRecord record;
    while (file.read(reinterpret_cast<char *>(&record), sizeof(AttendanceRecord)))
    {
        if (equalsIgnoreCase(record.username, username) &&
            std::strcmp(record.date, date.c_str()) == 0 &&
            equalsIgnoreCase(record.subject, subject))
        {
            return true;
        }
    }

    return false;
}

bool AuthenticationBase::updateAttendanceRecord(const string &username,
                                                const string &date,
                                                const string &subject,
                                                const string &status,
                                                const string &markedBy)
{
    if (!hasValidRecordSize(ATTENDANCE_FILE, sizeof(AttendanceRecord)))
    {
        cout << "Error: Attendance file is corrupted.\n";
        return false;
    }

    ifstream inFile(ATTENDANCE_FILE, ios::binary);
    if (!inFile.is_open())
        return false;

    ofstream outFile(TEMP_ATTENDANCE_FILE, ios::binary);
    if (!outFile.is_open())
        return false;

    AttendanceRecord record;
    bool found = false;

    while (inFile.read(reinterpret_cast<char *>(&record), sizeof(AttendanceRecord)))
    {
        if (equalsIgnoreCase(record.username, username) &&
            std::strcmp(record.date, date.c_str()) == 0 &&
            equalsIgnoreCase(record.subject, subject))
        {
            copyToField(record.status, status, sizeof(record.status));
            copyToField(record.markedBy, markedBy, sizeof(record.markedBy));
            found = true;
        }

        outFile.write(reinterpret_cast<char *>(&record), sizeof(AttendanceRecord));
    }

    if (!found)
    {
        inFile.close();
        outFile.close();
        std::remove(TEMP_ATTENDANCE_FILE);
        return false;
    }

    return finalizeFileRewrite(inFile, outFile, ATTENDANCE_FILE, TEMP_ATTENDANCE_FILE);
}

bool AuthenticationBase::markAttendance(const string &username,
                                        const string &role,
                                        const string &markedBy,
                                        const string &date,
                                        const string &status,
                                        const string &subject)
{
    string attendanceRole;
    if (equalsIgnoreCase(role, "Student"))
        attendanceRole = "Student";
    else if (equalsIgnoreCase(role, "Teacher"))
        attendanceRole = "Teacher";
    else
    {
        cout << "Error: This role cannot mark attendance.\n";
        return false;
    }

    string rollNumber = "N/A";
    string semester = "N/A";
    string attendanceSubject = subject;

    StudentRecord student;
    if (attendanceRole == "Student" && findStudentByUsername(username, student))
    {
        rollNumber = student.rollNumber;
        semester = student.semester;

        if (attendanceSubject.empty())
            attendanceSubject = student.subject;
    }
    else if (attendanceRole == "Teacher")
    {
        TeacherRecord teacher;
        if (!findTeacherByUsername(username, teacher))
        {
            cout << "Error: Teacher profile was not found.\n";
            return false;
        }
        rollNumber = teacher.teacherId;
    }

    if (attendanceSubject.empty())
        attendanceSubject = "General";

    if (attendanceExists(username, date, attendanceSubject))
    {
        cout << "\nAttendance already exists for:\n";
        cout << "Date    : " << date << endl;
        cout << "Subject : " << attendanceSubject << endl;
        return false;
    }

    return saveAttendance(username,
                          attendanceRole,
                          rollNumber,
                          semester,
                          attendanceSubject,
                          date,
                          status,
                          markedBy);
}

void AuthenticationBase::readAttendance(const string &username,
                                        const string &semesterFilter,
                                        const string &subjectFilter)
{
    if (!hasValidRecordSize(ATTENDANCE_FILE, sizeof(AttendanceRecord)))
    {
        cout << "\nError: Attendance file is corrupted.\n";
        return;
    }

    ifstream file(ATTENDANCE_FILE, ios::binary);
    if (!file.is_open())
    {
        cout << "\nNo attendance file found.\n";
        return;
    }

    AttendanceRecord record;
    bool found = false;
    int totalRecords = 0;
    int presentRecords = 0;

    cout << "\n==============================================\n";
    cout << "             ATTENDANCE HISTORY\n";
    cout << "==============================================\n";

    while (file.read(reinterpret_cast<char *>(&record), sizeof(AttendanceRecord)))
    {
        if (equalsIgnoreCase(record.username, username) &&
            (semesterFilter.empty() ||
             std::strcmp(record.semester, semesterFilter.c_str()) == 0) &&
            (subjectFilter.empty() ||
             equalsIgnoreCase(record.subject, subjectFilter)))
        {
            found = true;
            ++totalRecords;

            if (std::strcmp(record.status, "Present") == 0)
                ++presentRecords;

            cout << "Date      : " << record.date << endl;
            cout << "Roll No.  : " << record.rollNumber << endl;
            cout << "Semester  : " << record.semester << endl;
            cout << "Subject   : " << record.subject << endl;
            cout << "Role      : " << record.role << endl;
            cout << "Status    : " << record.status << endl;
            cout << "Marked By : " << record.markedBy << endl;
            cout << "----------------------------------------------\n";
        }
    }

    if (!found)
    {
        cout << "No attendance records found.\n";
        return;
    }

    const double percentage = totalRecords == 0
                                  ? 0.0
                                  : (100.0 * presentRecords) / totalRecords;

    cout << "Total Records: " << totalRecords << endl;
    cout << "Present      : " << presentRecords << endl;
    cout << "Attendance % : " << percentage << "%\n";
}

void AuthenticationBase::viewAllStudentAttendanceByDate()
{
    string date;
    cout << "\nEnter date (YYYY-MM-DD): ";
    cin >> date;

    if (!isValidDateInput(date, false))
    {
        cout << "\nInvalid date format.\n";
        return;
    }

    if (!hasValidRecordSize(ATTENDANCE_FILE, sizeof(AttendanceRecord)))
    {
        cout << "\nError: Attendance file is corrupted.\n";
        return;
    }

    ifstream file(ATTENDANCE_FILE, ios::binary);
    if (!file.is_open())
    {
        cout << "\nNo attendance file found.\n";
        return;
    }

    AttendanceRecord record;
    bool found = false;

    cout << "\n==============================================\n";
    cout << "       ALL STUDENT ATTENDANCE\n";
    cout << "       DATE: " << date << endl;
    cout << "==============================================\n";

    while (file.read(reinterpret_cast<char *>(&record), sizeof(AttendanceRecord)))
    {
        if (equalsIgnoreCase(record.role, "Student") &&
            std::strcmp(record.date, date.c_str()) == 0)
        {
            found = true;
            cout << "Username  : " << record.username << endl;
            cout << "Roll No.  : " << record.rollNumber << endl;
            cout << "Semester  : " << record.semester << endl;
            cout << "Subject   : " << record.subject << endl;
            cout << "Status    : " << record.status << endl;
            cout << "Marked By : " << record.markedBy << endl;
            cout << "----------------------------------------------\n";
        }
    }

    if (!found)
        cout << "No student attendance records found for this date.\n";
}

void AuthenticationBase::listAllStudents()
{
    if (!hasValidRecordSize(STUDENT_FILE, sizeof(StudentRecord)))
    {
        cout << "\nError: Student file is corrupted.\n";
        return;
    }

    ifstream file(STUDENT_FILE, ios::binary);
    if (!file.is_open())
    {
        cout << "\nNo student records found.\n";
        return;
    }

    StudentRecord student;
    int count = 0;

    cout << "\n========== ALL STUDENTS ==========\n";

    while (file.read(reinterpret_cast<char *>(&student), sizeof(StudentRecord)))
    {
        cout << "\n"
             << ++count << ". "
             << student.name << " ("
             << student.username << ")\n";
        cout << "Roll No.     : " << student.rollNumber << endl;
        cout << "Date of Birth: " << student.dateOfBirth << endl;
        cout << "Semester     : " << student.semester << endl;
        cout << "Program      : " << student.program << endl;
        cout << "Section      : " << student.section << endl;
    }

    if (count == 0)
        cout << "No student records found.\n";
}

void AuthenticationBase::displayStudentDetails(const StudentRecord &student)
{
    cout << "\n====================================\n";
    cout << "         STUDENT DETAILS\n";
    cout << "====================================\n";
    cout << "Username      : " << student.username << endl;
    cout << "Name          : " << student.name << endl;
    cout << "Date of Birth : " << student.dateOfBirth << endl;
    cout << "Roll No.      : " << student.rollNumber << endl;
    cout << "Semester      : " << student.semester << endl;
    cout << "Subject       : " << student.subject << endl;
    cout << "Program       : " << student.program << endl;
    cout << "Section       : " << student.section << endl;
    cout << "====================================\n";
}

void AuthenticationBase::displayTeacherRecord(const TeacherRecord &teacher)
{
    cout << "\n====================================\n";
    cout << "         TEACHER DETAILS\n";
    cout << "====================================\n";
    cout << "Username      : " << teacher.username << endl;
    cout << "Teacher ID    : " << teacher.teacherId << endl;
    cout << "Name          : " << teacher.name << endl;
    cout << "Date of Birth : " << teacher.dateOfBirth << endl;
    cout << "Department    : " << teacher.department << endl;
    cout << "Qualification : " << teacher.qualification << endl;
    cout << "Role          : Teacher\n";
    cout << "====================================\n";
}

void AuthenticationBase::viewPersonalDetails()
{
    UserRecord user;
    if (!findUser(currentUsername, user))
    {
        cout << "\nUnable to load your account details.\n";
        return;
    }

    StudentRecord student;
    if (equalsIgnoreCase(user.role, "Student") &&
        findStudentByUsername(currentUsername, student))
    {
        displayStudentDetails(student);
        return;
    }

    TeacherRecord teacher;
    if (equalsIgnoreCase(user.role, "Teacher") &&
        findTeacherByUsername(currentUsername, teacher))
    {
        displayTeacherRecord(teacher);
        return;
    }

    StaffRecord staff;
    if (findStaffByUsername(currentUsername, staff))
    {
        cout << "\n====================================\n";
        cout << "         PERSONAL DETAILS\n";
        cout << "====================================\n";
        cout << "Username      : " << staff.username << endl;
        cout << "Name          : " << staff.name << endl;
        cout << "Date of Birth : " << staff.dateOfBirth << endl;
        cout << "Department    : " << staff.department << endl;
        cout << "Role          : " << staff.role << endl;
        cout << "====================================\n";
        return;
    }

    cout << "\n====================================\n";
    cout << "         PERSONAL DETAILS\n";
    cout << "====================================\n";
    cout << "Username : " << user.username << endl;
    cout << "Role     : " << user.role << endl;
    cout << "====================================\n";
}

void AuthenticationBase::viewTeacherDetails()
{
    string username;
    cout << "\nEnter teacher username: ";
    cin >> username;
    viewTeacherDetailsFor(username);
}

void AuthenticationBase::viewTeacherDetailsFor(const string &username)
{
    TeacherRecord teacher;
    if (!findTeacherByUsername(username, teacher))
    {
        cout << "\nTeacher details not found.\n";
        return;
    }

    displayTeacherRecord(teacher);
}

void AuthenticationBase::viewTeacherAttendance()
{
    string username;
    cout << "\nEnter teacher username: ";
    cin >> username;

    UserRecord user;
    if (!findUser(username, user) || !equalsIgnoreCase(user.role, "Teacher"))
    {
        cout << "\nTeacher account not found.\n";
        return;
    }

    viewTeacherDetailsFor(username);
    readAttendance(username);
}

void AuthenticationBase::updateTeacherDetails()
{
    string username;
    string name;
    string dateOfBirth;
    string department;
    string qualification;

    cout << "\nEnter teacher username: ";
    cin >> username;
    viewTeacherDetailsFor(username);

    discardLine();
    cout << "New name: ";
    std::getline(cin, name);
    cout << "New date of birth: ";
    std::getline(cin, dateOfBirth);
    cout << "New department: ";
    std::getline(cin, department);
    cout << "New qualification: ";
    std::getline(cin, qualification);

    if (updateTeacherRecord(username, name, dateOfBirth, department, qualification))
        cout << "\nTeacher details updated successfully.\n";
    else
        cout << "\nTeacher update failed.\n";
}

void AuthenticationBase::viewUserDetails()
{
    string username;
    cout << "\nEnter username: ";
    cin >> username;

    UserRecord user;
    if (!findUser(username, user))
    {
        cout << "\nUser not found.\n";
        return;
    }

    StaffRecord staff;
    if ((equalsIgnoreCase(user.role, "Admin") ||
         equalsIgnoreCase(user.role, "SubAdmin")) &&
        findStaffByUsername(username, staff))
    {
        cout << "\n====================================\n";
        cout << "         PERSONAL DETAILS\n";
        cout << "====================================\n";
        cout << "Username      : " << staff.username << endl;
        cout << "Name          : " << staff.name << endl;
        cout << "Date of Birth : " << staff.dateOfBirth << endl;
        cout << "Department    : " << staff.department << endl;
        cout << "Role          : " << staff.role << endl;
        cout << "====================================\n";
        return;
    }

    cout << "\n========== USER DETAILS ==========\n";
    cout << "Username: " << user.username << endl;
    cout << "Role    : " << user.role << endl;
}

void AuthenticationBase::updateUserDetails()
{
    string username;
    string password;
    string role;

    cout << "\nEnter username: ";
    cin >> username;

    UserRecord user;
    if (!findUser(username, user))
    {
        cout << "\nUser not found.\n";
        return;
    }

    if (!equalsIgnoreCase(user.role, "Admin") &&
        !equalsIgnoreCase(user.role, "SubAdmin"))
    {
        cout << "\nOnly Admin/SubAdmin accounts can be updated here.\n";
        return;
    }

    cout << "New password: ";
    cin >> password;
    cout << "New role (Admin/SubAdmin): ";
    cin >> role;

    if (role != "Admin" && role != "SubAdmin")
    {
        cout << "\nOnly Admin or SubAdmin roles can be updated here.\n";
        return;
    }

    if (updateUserCredentials(username, password, role))
        cout << "\nUser updated successfully.\n";
    else
        cout << "\nUser update failed.\n";
}

string AuthenticationBase::getProfileName(const string &username,
                                          const string &role)
{
    StudentRecord student;
    if (role == "Student" &&
        findStudentByUsername(username, student) &&
        student.name[0] != '\0')
        return student.name;

    TeacherRecord teacher;
    if (role == "Teacher" &&
        findTeacherByUsername(username, teacher) &&
        teacher.name[0] != '\0')
        return teacher.name;

    StaffRecord staff;
    if ((role == "Admin" || role == "SubAdmin") &&
        findStaffByUsername(username, staff) &&
        staff.name[0] != '\0')
        return staff.name;

    return username;
}

void AuthenticationBase::addAccount(const string &roleRestriction)
{
    string username;
    string password;
    string role;

    cout << "\n========== ADD USER ==========\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (roleRestriction.empty())
    {
        cout << "Role (Admin/SubAdmin/Teacher/Student): ";
        cin >> role;
    }
    else if (roleRestriction == "Admin/SubAdmin")
    {
        cout << "Role (Admin/SubAdmin): ";
        cin >> role;
    }
    else if (roleRestriction == "Student/Teacher")
    {
        cout << "Role (Student/Teacher): ";
        cin >> role;
    }
    else
    {
        role = roleRestriction;
    }

    if (roleRestriction == "Admin/SubAdmin" &&
        role != "Admin" && role != "SubAdmin")
    {
        cout << "\nInvalid role.\n";
        return;
    }

    if (roleRestriction == "Student/Teacher" &&
        role != "Student" && role != "Teacher")
    {
        cout << "\nOnly Student or Teacher accounts can be created.\n";
        return;
    }

    if (role != "Admin" && role != "SubAdmin" &&
        role != "Teacher" && role != "Student")
    {
        cout << "\nInvalid role.\n";
        return;
    }

    if (usernameExists(username))
    {
        cout << "\nUsername already exists.\n";
        return;
    }

    if (!addUser(username, password, role))
    {
        cout << "\nFailed to create account.\n";
        return;
    }

    if (role == "Student")
    {
        string name;
        string dateOfBirth;
        string roll;
        string semester;
        string subject;
        string program;
        string section;

        cout << "\n========== STUDENT ACADEMIC DETAILS ==========\n";
        discardLine();
        cout << "Student Name: ";
        std::getline(cin, name);
        cout << "Date of Birth (YYYY-MM-DD): ";
        std::getline(cin, dateOfBirth);
        cout << "Roll Number / Student ID: ";
        cin >> roll;

        if (rollNumberExists(roll))
        {
            cout << "\nRoll number already exists.\n";
            deleteUser(username);
            return;
        }

        cout << "Semester: ";
        cin >> semester;
        discardLine();
        cout << "Subject/Course: ";
        std::getline(cin, subject);
        cout << "Program: ";
        std::getline(cin, program);
        cout << "Section: ";
        cin >> section;

        if (addStudentRecord(username, name, dateOfBirth, roll, semester,
                             subject, program, section))
        {
            cout << "\nStudent account created successfully.\n";
        }
        else
        {
            cout << "\nAcademic record creation failed.\n";
            deleteUser(username);
        }
        return;
    }

    if (role == "Teacher")
    {
        string teacherId;
        string name;
        string dateOfBirth;
        string department;
        string qualification;

        cout << "\n========== TEACHER DETAILS ==========\n";
        discardLine();
        cout << "Teacher Name: ";
        std::getline(cin, name);
        cout << "Teacher ID Number: ";
        cin >> teacherId;
        cout << "Date of Birth (YYYY-MM-DD): ";
        cin >> dateOfBirth;
        discardLine();
        cout << "Department: ";
        std::getline(cin, department);
        cout << "Qualification: ";
        std::getline(cin, qualification);

        if (!addTeacherRecord(username, teacherId, name, dateOfBirth,
                              department, qualification))
        {
            deleteUser(username);
            cout << "\nTeacher profile creation failed.\n";
            return;
        }

        cout << "\nTeacher account created successfully.\n";
        return;
    }

    string name;
    string dateOfBirth;
    string department;

    cout << "\n========== STAFF DETAILS ==========\n";
    discardLine();
    cout << "Full Name: ";
    std::getline(cin, name);
    cout << "Date of Birth (YYYY-MM-DD): ";
    std::getline(cin, dateOfBirth);
    cout << "Department: ";
    std::getline(cin, department);

    if (!addStaffRecord(username, role, name, dateOfBirth, department))
    {
        deleteUser(username);
        cout << "\nStaff profile creation failed.\n";
        return;
    }

    cout << "\n"
         << role << " account created successfully.\n";
}

void AuthenticationBase::studentManagement(const string &title)
{
    int choice = 0;

    do
    {
        clearScreen();
        cout << "====================================\n";
        cout << "        " << title << "\n";
        cout << "====================================\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. View Student Details\n";
        cout << "6. View Student Attendance\n";
        cout << "7. View All Student Attendance By Date\n";
        cout << "8. List All Students\n";
        cout << "9. Back\n";
        cout << "\nEnter choice: ";

        if (!readMenuChoice(choice))
            continue;

        switch (choice)
        {
        case 1:
            addStudent();
            waitForEnter();
            break;
        case 2:
        case 5:
            searchStudent();
            waitForEnter();
            break;
        case 3:
            updateStudent();
            waitForEnter();
            break;
        case 4:
            deleteStudent();
            waitForEnter();
            break;
        case 6:
            viewStudentAttendance();
            waitForEnter();
            break;
        case 7:
            viewAllStudentAttendanceByDate();
            waitForEnter();
            break;
        case 8:
            listAllStudents();
            waitForEnter();
            break;
        case 9:
            break;
        default:
            cout << "\nInvalid choice.\n";
            waitForEnter();
        }
    } while (choice != 9);
}

void AuthenticationBase::teacherManagement(bool confirmBeforeDelete)
{
    int choice = 0;

    do
    {
        clearScreen();
        cout << "\n========== TEACHER MANAGEMENT ==========\n";
        cout << "1. Add Teacher\n";
        cout << "2. View Teacher Details\n";
        cout << "3. Search Teacher\n";
        cout << "4. View Teacher Attendance\n";
        cout << "5. Update Teacher Details\n";
        cout << "6. Delete Teacher\n";
        cout << "7. Back\n";
        cout << "\nEnter choice: ";

        if (!readMenuChoice(choice))
            continue;

        switch (choice)
        {
        case 1:
            addAccount("Teacher");
            waitForEnter();
            break;
        case 2:
        case 3:
            viewTeacherDetails();
            waitForEnter();
            break;
        case 4:
            viewTeacherAttendance();
            waitForEnter();
            break;
        case 5:
            updateTeacherDetails();
            waitForEnter();
            break;
        case 6:
        {
            string username;
            cout << "\nEnter teacher username to delete: ";
            cin >> username;

            UserRecord user;
            if (!findUser(username, user) ||
                !equalsIgnoreCase(user.role, "Teacher"))
            {
                cout << "\nTeacher account not found.\n";
                waitForEnter();
                break;
            }

            if (confirmBeforeDelete)
            {
                char confirmation = 'N';
                viewTeacherDetailsFor(username);
                cout << "Delete this teacher? (Y/N): ";
                cin >> confirmation;

                if (std::toupper(static_cast<unsigned char>(confirmation)) != 'Y')
                {
                    cout << "\nDeletion cancelled.\n";
                    waitForEnter();
                    break;
                }
            }

            if (deleteTeacherAndRelatedData(username))
                cout << "\nTeacher and attendance deleted successfully.\n";
            else
                cout << "\nTeacher deletion failed.\n";

            waitForEnter();
            break;
        }
        case 7:
            break;
        default:
            cout << "\nInvalid choice.\n";
            waitForEnter();
        }
    } while (choice != 7);
}

void AuthenticationBase::addStudent()
{
    addAccount("Student");
}

void AuthenticationBase::searchStudent()
{
    string key;
    cout << "\nEnter Username, Name or Roll Number: ";
    discardLine();
    std::getline(cin, key);

    StudentRecord student;
    if (findStudentByUsername(key, student) ||
        findStudentByRoll(key, student) ||
        findStudentByName(key, student))
    {
        displayStudentDetails(student);
    }
    else
    {
        cout << "\nStudent not found.\n";
    }
}

void AuthenticationBase::updateStudent()
{
    string username;
    cout << "\nEnter student username: ";
    cin >> username;

    StudentRecord student;
    if (!findStudentByUsername(username, student))
    {
        cout << "\nStudent not found.\n";
        return;
    }

    displayStudentDetails(student);
    cout << "\nEnter new details:\n";

    string newName;
    string newDateOfBirth;
    string newRoll;
    string newSemester;
    string newSubject;
    string newProgram;
    string newSection;

    discardLine();
    cout << "New Student Name: ";
    std::getline(cin, newName);
    cout << "New Date of Birth (YYYY-MM-DD): ";
    std::getline(cin, newDateOfBirth);
    cout << "New Roll Number: ";
    cin >> newRoll;

    if (!equalsIgnoreCase(student.rollNumber, newRoll) &&
        rollNumberExists(newRoll))
    {
        cout << "\nRoll number already exists.\n";
        return;
    }

    cout << "New Semester: ";
    cin >> newSemester;
    discardLine();
    cout << "New Subject/Course: ";
    std::getline(cin, newSubject);
    cout << "New Program: ";
    std::getline(cin, newProgram);
    cout << "New Section: ";
    cin >> newSection;

    copyToField(student.name, newName, sizeof(student.name));
    copyToField(student.dateOfBirth, newDateOfBirth, sizeof(student.dateOfBirth));
    copyToField(student.rollNumber, newRoll, sizeof(student.rollNumber));
    copyToField(student.semester, newSemester, sizeof(student.semester));
    copyToField(student.subject, newSubject, sizeof(student.subject));
    copyToField(student.program, newProgram, sizeof(student.program));
    copyToField(student.section, newSection, sizeof(student.section));

    if (updateStudentRecord(student))
        cout << "\nStudent information updated successfully.\n";
    else
        cout << "\nUpdate failed.\n";
}

void AuthenticationBase::deleteStudent()
{
    string username;
    cout << "\nEnter student username: ";
    cin >> username;

    StudentRecord student;
    if (!findStudentByUsername(username, student))
    {
        cout << "\nStudent not found.\n";
        return;
    }

    displayStudentDetails(student);

    char confirmation = 'N';
    cout << "\nDelete this student? (Y/N): ";
    cin >> confirmation;

    if (std::toupper(static_cast<unsigned char>(confirmation)) != 'Y')
    {
        cout << "\nDelete cancelled.\n";
        return;
    }

    if (deleteStudentAndRelatedData(username))
        cout << "\nStudent and attendance records deleted successfully.\n";
    else
        cout << "\nStudent deletion was incomplete. Check the data files.\n";
}

void AuthenticationBase::viewStudentAttendance()
{
    string username;
    cout << "\nEnter student username: ";
    cin >> username;

    StudentRecord student;
    if (!findStudentByUsername(username, student))
    {
        cout << "\nStudent not found.\n";
        return;
    }

    displayStudentDetails(student);
    readAttendance(username);
}

void AuthenticationBase::viewAttendance()
{
    string username;
    cout << "\nEnter username: ";
    cin >> username;

    UserRecord user;
    if (!findUser(username, user))
    {
        cout << "\nUser does not exist.\n";
        return;
    }

    readAttendance(username);
}

void AuthenticationBase::manualAttendanceOverride()
{
    string username;
    string date;
    string subject;
    string status;
    string providedId;

    cout << "\n========================================\n";
    cout << "     MANUAL ATTENDANCE / OVERRIDE\n";
    cout << "========================================\n";
    cout << "Target Username: ";
    cin >> username;

    UserRecord user;
    if (!findUser(username, user))
    {
        cout << "\nError: User does not exist.\n";
        return;
    }

    if (!equalsIgnoreCase(user.role, "Student") &&
        !equalsIgnoreCase(user.role, "Teacher"))
    {
        cout << "\nOnly Student or Teacher attendance can be marked.\n";
        return;
    }

    if (equalsIgnoreCase(user.role, "Student"))
    {
        StudentRecord student;
        if (!findStudentByUsername(username, student))
        {
            cout << "\nStudent profile not found.\n";
            return;
        }

        cout << "Student ID (Roll Number): ";
        cin >> providedId;
        if (!equalsIgnoreCase(student.rollNumber, providedId))
        {
            cout << "\nStudent ID does not match this username.\n";
            return;
        }

        subject = student.subject;
        if (subject.empty())
            subject = "General";
    }
    else
    {
        TeacherRecord teacher;
        if (!findTeacherByUsername(username, teacher))
        {
            cout << "\nTeacher profile not found.\n";
            return;
        }

        cout << "Teacher ID Number: ";
        cin >> providedId;
        if (!equalsIgnoreCase(teacher.teacherId, providedId))
        {
            cout << "\nTeacher ID does not match this username.\n";
            return;
        }

        subject = "General";
    }

    date = getCurrentDate();
    cout << "Attendance date: " << date << endl;

    cout << "Status (Present/Absent/Late): ";
    cin >> status;

    if (!isValidStatus(status))
    {
        cout << "\nInvalid attendance status.\n";
        return;
    }

    if (equalsIgnoreCase(status, "Present"))
        status = "Present";
    else if (equalsIgnoreCase(status, "Absent"))
        status = "Absent";
    else
        status = "Late";

    if (attendanceExists(username, date, subject))
    {
        if (updateAttendanceRecord(username, date, subject, status, currentUsername))
        {
            cout << "\nAttendance updated successfully.\n";
            cout << "Marked By: " << currentUsername << endl;
        }
        else
        {
            cout << "\nAttendance update failed.\n";
        }
        return;
    }

    if (markAttendance(username, user.role, currentUsername, date, status, subject))
    {
        cout << "\nAttendance marked successfully.\n";
        cout << "Marked By: " << currentUsername << endl;
    }
    else
    {
        cout << "\nFailed to save attendance.\n";
    }
}

bool AuthenticationBase::migrateLegacyStudentFile()
{
    ifstream checkFile(STUDENT_FILE, ios::binary | ios::ate);
    if (!checkFile.is_open())
        return true;

    const std::streamoff size = checkFile.tellg();
    checkFile.close();

    if (size == 0 ||
        size % static_cast<std::streamoff>(sizeof(StudentRecord)) == 0)
        return true;

    if (size % static_cast<std::streamoff>(sizeof(LegacyStudentRecord)) != 0)
        return false;

    ifstream inFile(STUDENT_FILE, ios::binary);
    ofstream outFile(TEMP_STUDENT_FILE, ios::binary);
    if (!inFile.is_open() || !outFile.is_open())
        return false;

    LegacyStudentRecord legacyStudent;
    while (inFile.read(reinterpret_cast<char *>(&legacyStudent),
                       sizeof(LegacyStudentRecord)))
    {
        StudentRecord student{};
        copyToField(student.username, legacyStudent.username, sizeof(student.username));
        copyToField(student.name, legacyStudent.username, sizeof(student.name));
        copyToField(student.dateOfBirth, "2000-01-01", sizeof(student.dateOfBirth));
        copyToField(student.rollNumber, legacyStudent.rollNumber, sizeof(student.rollNumber));
        copyToField(student.semester, legacyStudent.semester, sizeof(student.semester));
        copyToField(student.subject, legacyStudent.subject, sizeof(student.subject));
        copyToField(student.program, legacyStudent.program, sizeof(student.program));
        copyToField(student.section, legacyStudent.section, sizeof(student.section));
        outFile.write(reinterpret_cast<char *>(&student), sizeof(StudentRecord));
    }

    return finalizeFileRewrite(inFile, outFile, STUDENT_FILE, TEMP_STUDENT_FILE);
}

bool AuthenticationBase::migrateLegacyTeacherFile()
{
    ifstream checkFile(TEACHER_FILE, ios::binary | ios::ate);
    if (!checkFile.is_open())
        return true;

    const std::streamoff size = checkFile.tellg();
    checkFile.close();

    if (size == 0 ||
        size % static_cast<std::streamoff>(sizeof(TeacherRecord)) == 0)
        return true;

    if (size % static_cast<std::streamoff>(sizeof(LegacyTeacherRecord)) != 0)
        return false;

    ifstream inFile(TEACHER_FILE, ios::binary);
    ofstream outFile(TEMP_TEACHER_FILE, ios::binary);
    if (!inFile.is_open() || !outFile.is_open())
        return false;

    LegacyTeacherRecord legacyTeacher;
    size_t teacherNumber = 1;
    while (inFile.read(reinterpret_cast<char *>(&legacyTeacher),
                       sizeof(LegacyTeacherRecord)))
    {
        TeacherRecord teacher{};
        copyToField(teacher.username, legacyTeacher.username, sizeof(teacher.username));
        copyToField(teacher.teacherId,
                    "T" + std::to_string(teacherNumber++),
                    sizeof(teacher.teacherId));
        copyToField(teacher.name, legacyTeacher.name, sizeof(teacher.name));
        copyToField(teacher.dateOfBirth, legacyTeacher.dateOfBirth,
                    sizeof(teacher.dateOfBirth));
        copyToField(teacher.department, legacyTeacher.department,
                    sizeof(teacher.department));
        copyToField(teacher.qualification, legacyTeacher.qualification,
                    sizeof(teacher.qualification));
        outFile.write(reinterpret_cast<char *>(&teacher), sizeof(TeacherRecord));
    }

    return finalizeFileRewrite(inFile, outFile, TEACHER_FILE, TEMP_TEACHER_FILE);
}

void AuthenticationBase::removeLegacyDefaultAccounts()
{
    deleteAttendanceRecords("student1");
    deleteAttendanceRecords("teacher1");
    deleteStudentRecord("student1");
    deleteTeacherRecord("teacher1");
    deleteUser("student1");
    deleteUser("teacher1");
}

void AuthenticationBase::removeAccountsWithMissingProfiles()
{
    if (!hasValidRecordSize(CREDENTIAL_FILE, sizeof(UserRecord)))
        return;

    ifstream file(CREDENTIAL_FILE, ios::binary);
    if (!file.is_open())
        return;

    vector<string> incompleteUsers;
    UserRecord user;

    while (file.read(reinterpret_cast<char *>(&user), sizeof(UserRecord)))
    {
        decryptUserRecord(user);

        if (equalsIgnoreCase(user.role, "Student"))
        {
            StudentRecord student;
            if (!findStudentByUsername(user.username, student))
                incompleteUsers.push_back(user.username);
        }
        else if (equalsIgnoreCase(user.role, "Teacher"))
        {
            TeacherRecord teacher;
            if (!findTeacherByUsername(user.username, teacher))
                incompleteUsers.push_back(user.username);
        }
    }

    for (const string &username : incompleteUsers)
    {
        deleteAttendanceRecords(username);
        deleteStudentRecord(username);
        deleteTeacherRecord(username);
        deleteUser(username);
    }
}

bool AuthenticationBase::ensureDefaultAccounts()
{
    static bool alreadyInitialized = false;
    if (alreadyInitialized)
        return true;

    if (!migrateLegacyStudentFile())
    {
        cout << "Error: Student file could not be migrated.\n";
        return false;
    }

    if (!migrateLegacyTeacherFile())
    {
        cout << "Error: Teacher file could not be migrated.\n";
        return false;
    }

    removeLegacyDefaultAccounts();
    removeAccountsWithMissingProfiles();

    if (!hasValidRecordSize(CREDENTIAL_FILE, sizeof(UserRecord)))
    {
        cout << "Error: Credentials file is corrupted.\n";
        return false;
    }

    UserRecord administrator;
    if (!findUser("admin", administrator))
    {
        if (!addUser("admin", "admin123", "Admin"))
            return false;
    }

    StaffRecord adminStaff;
    if (!findStaffByUsername("admin", adminStaff))
    {
        addStaffRecord("admin",
                       "Admin",
                       "System Administrator",
                       "1990-01-01",
                       "Administration");
    }

    UserRecord subAdministrator;
    if (!findUser("subadmin", subAdministrator))
    {
        if (!addUser("subadmin", "sub123", "SubAdmin"))
            return false;
    }

    StaffRecord subAdminStaff;
    if (!findStaffByUsername("subadmin", subAdminStaff))
    {
        addStaffRecord("subadmin",
                       "SubAdmin",
                       "Assistant Administrator",
                       "1992-01-01",
                       "Administration");
    }

    alreadyInitialized = true;
    return true;
}
