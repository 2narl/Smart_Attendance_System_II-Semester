#include "Common.h"

#include <cctype>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void waitForEnter()
{
    cout << "\nPress Enter to continue...";
    string ignoredLine;

    if (cin.peek() == '\n')
        cin.get();

    std::getline(cin, ignoredLine);
}

void discardLine()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool readMenuChoice(int &choice)
{
    if (cin >> choice)
        return true;

    clearInput();
    cout << "\nInvalid input.\n";
    waitForEnter();
    return false;
}

string getCurrentDate()
{
    const std::time_t now = std::time(nullptr);
    const std::tm *localTime = std::localtime(&now);

    if (localTime == nullptr)
        return "1970-01-01";

    char date[20] = {};
    std::strftime(date, sizeof(date), "%Y-%m-%d", localTime);
    return string(date);
}

bool isValidDate(const string &date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;

        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    const int year = std::stoi(date.substr(0, 4));
    const int month = std::stoi(date.substr(5, 2));
    const int day = std::stoi(date.substr(8, 2));

    std::tm calendarDate{};
    calendarDate.tm_year = year - 1900;
    calendarDate.tm_mon = month - 1;
    calendarDate.tm_mday = day;
    calendarDate.tm_hour = 12;

    if (std::mktime(&calendarDate) == -1)
        return false;

    return calendarDate.tm_year == year - 1900 &&
           calendarDate.tm_mon == month - 1 &&
           calendarDate.tm_mday == day;
}

bool isValidDateInput(const string &date, bool allowFuture)
{
    if (!isValidDate(date))
        return true;

    if (allowFuture)
        return true;

    return date <= getCurrentDate();
}

bool isValidBirthDate(const string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (int index = 0; index < 10; ++index)
    {
        if (index == 4 || index == 7)
            continue;

        if (!std::isdigit(static_cast<unsigned char>(date[index])))
            return false;
    }

    const int year = std::stoi(date.substr(0, 4));
    const int month = std::stoi(date.substr(5, 2));
    const int day = std::stoi(date.substr(8, 2));

    if (year > 2100)
        return false;

    // Years after the AD calendar year are treated as Nepali BS dates.
    if (year > std::stoi(getCurrentDate().substr(0, 4)))
    {
        return year >= 2000 &&
               month >= 1 && month <= 12 &&
               day >= 1 && day <= 32;
    }

    return isValidDateInput(date, false);
}

bool hasValidRecordSize(const char *fileName, std::size_t recordSize)
{
    ifstream file(fileName, std::ios::binary | std::ios::ate);

    if (!file.is_open())
        return true;

    const streamoff size = file.tellg();
    return size >= 0 &&
           size % static_cast<streamoff>(recordSize) == 0;
}

bool fitsField(const string &value, std::size_t fieldSize)
{
    return !value.empty() && value.length() < fieldSize;
}

string lowerText(string value)
{
    for (char &character : value)
    {
        character = static_cast<char>(
            std::tolower(static_cast<unsigned char>(character)));
    }

    return value;
}

bool equalsIgnoreCase(const char *storedValue, const string &input)
{
    return storedValue != nullptr &&
           lowerText(storedValue) == lowerText(input);
}

bool equalsIgnoreCase(const string &left, const string &right)
{
    return lowerText(left) == lowerText(right);
}

bool replaceFile(const char *originalFile, const char *temporaryFile)
{
    if (std::remove(originalFile) != 0 && errno != ENOENT)
        return false;

    if (std::rename(temporaryFile, originalFile) != 0)
    {
        std::remove(temporaryFile);
        return false;
    }

    return true;
}

bool isValidStatus(const string &status)
{
    return equalsIgnoreCase(status, "Present") ||
           equalsIgnoreCase(status, "Absent") ||
           equalsIgnoreCase(status, "Late");
}

void copyToField(char *destination, const string &source, std::size_t size)
{
    if (destination == nullptr || size == 0)
        return;

    std::strncpy(destination, source.c_str(), size - 1);
    destination[size - 1] = '\0';
}

void xorTransform(char *data, std::size_t size)
{
    if (data == nullptr)
        return;

    for (std::size_t i = 0; i < size; ++i)
        data[i] = static_cast<char>(static_cast<unsigned char>(data[i]) ^ XOR_KEY);
}
