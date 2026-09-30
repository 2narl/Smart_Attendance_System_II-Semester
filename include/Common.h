// Attendance Management System - shared constants, records, and helpers
// BIT second-semester project

#ifndef COMMON_H
#define COMMON_H

#include <cstddef>
#include <string>
using namespace std;

const char CREDENTIAL_FILE[] = "credentials.dat";
const char STUDENT_FILE[] = "students.dat";
const char TEACHER_FILE[] = "teachers.dat";
const char STAFF_FILE[] = "staff.dat";
const char ATTENDANCE_FILE[] = "attendance.dat";

const char TEMP_CREDENTIAL_FILE[] = "credentials_temp.dat";
const char TEMP_STUDENT_FILE[] = "students_temp.dat";
const char TEMP_TEACHER_FILE[] = "teachers_temp.dat";
const char TEMP_STAFF_FILE[] = "staff_temp.dat";
const char TEMP_ATTENDANCE_FILE[] = "attendance_temp.dat";

// XOR is obfuscation only. It hides passwords from a casual hex dump.
const unsigned char XOR_KEY = 0x5A;

struct UserRecord
{
    char username[30];
    char password[50];
    char role[20];
};

struct StudentRecord
{
    char username[30];
    char name[80];
    char dateOfBirth[20];
    char rollNumber[30];
    char semester[20];
    char subject[80];
    char program[50];
    char section[20];
};

struct LegacyStudentRecord
{
    char username[30];
    char rollNumber[30];
    char semester[20];
    char subject[80];
    char program[50];
    char section[20];
};

struct TeacherRecord
{
    char username[30];
    char teacherId[30];
    char name[80];
    char dateOfBirth[20];
    char department[50];
    char qualification[80];
};

struct LegacyTeacherRecord
{
    char username[30];
    char name[80];
    char dateOfBirth[20];
    char department[50];
    char qualification[80];
};

struct StaffRecord
{
    char username[30];
    char role[20];
    char name[80];
    char dateOfBirth[20];
    char department[50];
};

struct AttendanceRecord
{
    char username[30];
    char role[20];
    char rollNumber[30];
    char semester[20];
    char subject[80];
    char date[20];
    char status[15];
    char markedBy[30];
};

void clearScreen();
void clearInput();
void waitForEnter();
void discardLine();

string getCurrentDate();
string lowerText(string value);

bool isValidDate(const string &date);
bool isValidDateInput(const string &date, bool allowFuture);
bool isValidBirthDate(const string &date);
bool isValidStatus(const string &status);
bool hasValidRecordSize(const char *fileName, size_t recordSize);
bool fitsField(const string &value, size_t fieldSize);
bool equalsIgnoreCase(const char *storedValue, const string &input);
bool equalsIgnoreCase(const string &left, const string &right);
bool replaceFile(const char *originalFile, const char *temporaryFile);
bool readMenuChoice(int &choice);

void copyToField(char *destination, const string &source, size_t size);
void xorTransform(char *data, size_t size);

#endif
