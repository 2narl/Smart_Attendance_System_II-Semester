# PROJECT REPORT

## SMART ATTENDANCE MANAGEMENT SYSTEM

**A Project Report**  
Submitted in partial fulfillment of the requirement of **Project-II (BIT156CO)**  
of  
**Bachelor of Information Technology (BIT)**

**Submitted to:**  
**Purbanchal University**  
Faculty of Science and Technology  
Biratnagar, Nepal

**Submitted by:**  
**[Student Name]** — [Symbol No.]  
**[Second Student Name, if applicable]** — [Symbol No.]  
**[Third Student Name, if applicable]** — [Symbol No.]

**Under the Supervision of:**  
**[Supervisor Name]**  
[Designation]

**[College Name]**  
[College Address]

**[Month, Year]**

---

# CERTIFICATE OF PROJECT COMPLETION

This is to certify that the project work entitled **“Smart Attendance Management System”** has been carried out by **[Student Name(s)]**, students of Bachelor of Information Technology (BIT), in partial fulfillment of the requirements of **Project-II (BIT156CO)** under Purbanchal University.

The project has been developed using C++ and demonstrates the application of object-oriented programming, file handling, data validation, role-based access, record management, and attendance management concepts.

The project report has been prepared under the guidance and supervision of the assigned project supervisor. To the best of our knowledge, the work presented in this report is suitable for academic evaluation.

**Project Supervisor:**  
Name: __________________________  
Signature: _______________________  
Date: ___________________________

**Program Coordinator:**  
Name: __________________________  
Signature: _______________________  
Date: ___________________________

---

# EXAMINER'S CERTIFICATION

The project report entitled **“Smart Attendance Management System”**, developed by **[Student Name(s)]**, is presented for the partial fulfillment of the requirements of Bachelor of Information Technology under Purbanchal University.

The project report is approved in its present form as it satisfies the academic requirements prescribed for the project work.

| | Internal Examiner | External Examiner |
|---|---|---|
| Name | __________________ | __________________ |
| Designation | __________________ | __________________ |
| Signature | __________________ | __________________ |
| Date | __________________ | __________________ |

---

# STUDENT'S DECLARATION

We hereby declare that the project report entitled **“Smart Attendance Management System”** is our original academic work carried out for **Project-II (BIT156CO)** of Bachelor of Information Technology under Purbanchal University.

The project has been developed using C++ and the work presented in this report is based on our implementation, study, testing, and documentation. We have used references and learning materials where required and have acknowledged them appropriately.

We further declare that this project report has not been submitted to any other institution for the fulfillment of another degree, diploma, or academic award.

**Student Name:** __________________________  
**Symbol No.:** ____________________________  
**Signature:** ______________________________  
**Date:** __________________________________

---

# ACKNOWLEDGEMENT

We would like to express our sincere gratitude to Purbanchal University for providing the academic opportunity to undertake this project as a part of the Bachelor of Information Technology program.

We are grateful to our project supervisor **[Supervisor Name]** for providing valuable guidance, suggestions, and encouragement throughout the development of the project. The supervisor's feedback helped us improve the system design, implementation, testing, and documentation.

We would also like to thank the BIT program coordinator, teachers, and staff members of **[College Name]** for their support and academic guidance. We are thankful to our classmates and friends who provided suggestions and feedback during the development and testing of the system.

Finally, we express our sincere gratitude to our family members for their continuous encouragement and support.

---

# ABSTRACT

The **Smart Attendance Management System** is a C++ console-based application developed as a second-semester Bachelor of Information Technology Project-II. The main purpose of the system is to provide a simple and organized way to manage user accounts, student and teacher information, and attendance records.

The system implements role-based access for **Administrator, Sub-Administrator, Student, and Teacher** users. Administrators can manage users, students, teachers, attendance records, and system settings, while Sub-Administrators have controlled administrative functions. Students and teachers can log in, view their personal information, and manage or view their attendance according to their roles.

The project uses **object-oriented programming in C++**, including classes, inheritance, encapsulation, member functions, and modular source/header files. Data is stored persistently using binary files such as `credentials.dat`, `students.dat`, `teachers.dat`, `staff.dat`, and `attendance.dat`. The system also includes input validation, duplicate checking, record searching, updating, deletion, attendance percentage calculation, and file-rewrite techniques for safe record modification.

For basic password protection, the project applies XOR-based obfuscation to stored credential records. This provides protection against casual inspection of the binary file, but it is not intended to replace a modern cryptographic password-hashing mechanism.

The system demonstrates how C++ object-oriented concepts can be applied to a practical educational management problem. It can serve as a foundation for a future web- or database-based attendance system with stronger authentication, centralized storage, reporting, and multi-user access.

**Keywords:** Attendance Management, C++, Object-Oriented Programming, Binary File Handling, Role-Based Access, Student Management, Teacher Management.

---

# TABLE OF CONTENTS

1. Chapter One: Introduction  
   1.1 Background  
   1.2 Problem Statement  
   1.3 Objectives  
   1.4 Scope of the Project  
   1.5 Significance of the Project  
   1.6 Major Features  
   1.7 Limitations  
   1.8 Organization of the Report  

2. Chapter Two: Literature Review  
   2.1 Introduction  
   2.2 Existing Attendance Practices  
   2.3 Manual Attendance System  
   2.4 Computerized Attendance Systems  
   2.5 Comparative Review  
   2.6 Summary  

3. Chapter Three: System Analysis  
   3.1 Introduction  
   3.2 Existing System  
   3.3 Proposed System  
   3.4 Feasibility Analysis  
   3.5 Functional Requirements  
   3.6 Non-Functional Requirements  
   3.7 Hardware Requirements  
   3.8 Software Requirements  
   3.9 User Roles and Permissions  

4. Chapter Four: System Design  
   4.1 System Architecture  
   4.2 Module Design  
   4.3 Data/File Design  
   4.4 Class Design  
   4.5 Use-Case Description  
   4.6 Data Flow  
   4.7 Attendance Workflow  
   4.8 Algorithms  
   4.9 Input Validation and Error Handling  

5. Chapter Five: System Development and Implementation  
   5.1 Development Environment  
   5.2 Programming Language  
   5.3 Project Structure  
   5.4 Authentication Module  
   5.5 User Management Module  
   5.6 Student Management Module  
   5.7 Teacher Management Module  
   5.8 Attendance Module  
   5.9 File Handling Module  
   5.10 Data Validation  
   5.11 Security and Credential Protection  
   5.12 User Interface  

6. Chapter Six: System Testing  
   6.1 Testing Introduction  
   6.2 Testing Strategy  
   6.3 Test Cases  
   6.4 Validation Tests  
   6.5 Error Handling Tests  
   6.6 Testing Limitations  

7. Chapter Seven: Limitations, Future Enhancements and Conclusion  
   7.1 Limitations  
   7.2 Future Enhancements  
   7.3 Conclusion  

References  
Appendices

---

# LIST OF FIGURES

| Figure | Title |
|---|---|
| Figure 4.1 | Overall System Architecture |
| Figure 4.2 | Main Login Flow |
| Figure 4.3 | User Management Flow |
| Figure 4.4 | Student Attendance Flow |
| Figure 4.5 | Manual Attendance Override Flow |
| Figure 4.6 | File-Based Data Storage Structure |

---

# LIST OF TABLES

| Table | Title |
|---|---|
| Table 3.1 | Functional Requirements |
| Table 3.2 | Non-Functional Requirements |
| Table 3.3 | Hardware Requirements |
| Table 3.4 | Software Requirements |
| Table 3.5 | User Roles and Permissions |
| Table 4.1 | Data File Description |
| Table 4.2 | Main Classes |
| Table 5.1 | Project Source Files |
| Table 6.1 | Functional Test Cases |
| Table 6.2 | Validation Test Cases |

---

# LIST OF ABBREVIATIONS

| Abbreviation | Meaning |
|---|---|
| BIT | Bachelor of Information Technology |
| PU | Purbanchal University |
| OOP | Object-Oriented Programming |
| CRUD | Create, Read, Update, Delete |
| IDE | Integrated Development Environment |
| XOR | Exclusive OR |
| DOB | Date of Birth |
| ID | Identification |
| UI | User Interface |
| DFD | Data Flow Diagram |
| CPU | Central Processing Unit |
| RAM | Random Access Memory |

---

# CHAPTER ONE: INTRODUCTION

## 1.1 Background

Attendance is an important part of educational institutions because it helps monitor student participation and provides information about regularity. In a traditional attendance system, teachers generally record attendance manually using paper registers or spreadsheets. Such methods may require considerable time and can make searching, updating, and calculating attendance percentages difficult.

The **Smart Attendance Management System** was developed to provide a simple computerized solution for managing attendance and related user records. The system is designed for educational environments such as schools, colleges, and universities where administrators, teachers, and students need different levels of access.

The project is implemented in C++ using object-oriented programming principles. Instead of relying on a database server, the current version uses binary files to store records. This approach makes the project lightweight and suitable for demonstrating C++ file handling and OOP concepts.

The system separates authentication and common data operations from role-specific panels. The major panels are **AdminPanel**, **SubAdminPanel**, and **StudentTeacherPanel**, all of which inherit common functionality from the **AuthenticationBase** class.

## 1.2 Problem Statement

Traditional attendance management can create several practical problems:

- Attendance records may be maintained manually.
- Searching for a student's record can take time.
- Attendance percentage calculation may require manual work.
- Updating or deleting records can be inconvenient.
- Different users may require different access permissions.
- Attendance records may become difficult to organize as the number of students increases.
- Maintaining separate paper records can increase the possibility of human error.
- A simple educational project is needed to demonstrate how C++ OOP and file handling can solve these problems.

Therefore, the project aims to develop a simple console-based attendance management system that organizes user, student, teacher, and attendance information in a structured manner.

## 1.3 Objectives

### 1.3.1 General Objective

To develop a simple and organized attendance management system using C++ and object-oriented programming concepts.

### 1.3.2 Specific Objectives

The specific objectives are:

1. To implement role-based user authentication.
2. To manage administrator and sub-administrator accounts.
3. To add, search, update, and delete student records.
4. To add, search, update, and delete teacher records.
5. To allow students and teachers to view their attendance.
6. To allow eligible users to mark attendance.
7. To provide administrative attendance marking and override facilities.
8. To prevent duplicate attendance for the same user, date, and subject.
9. To calculate attendance percentage from stored records.
10. To store data persistently using binary files.
11. To validate user input and reduce invalid records.
12. To demonstrate practical use of OOP, inheritance, encapsulation, and file handling in C++.

## 1.4 Scope of the Project

The project is designed for small educational environments where attendance and basic user records need to be maintained locally.

The system covers:

- User authentication.
- Admin and Sub-Admin management.
- Student management.
- Teacher management.
- Staff profile management.
- Attendance marking.
- Attendance viewing.
- Attendance history.
- Attendance percentage calculation.
- Manual attendance override.
- Search facilities.
- Data validation.
- Binary-file storage.
- Basic credential obfuscation.
- Legacy student and teacher file migration.

The current system is mainly intended as an academic project and a prototype rather than a large-scale institutional information system.

## 1.5 Significance of the Project

The project is significant because it demonstrates the practical application of concepts learned in the second semester of BIT, particularly C++ programming and object-oriented programming.

It provides the following benefits:

- Reduces dependence on paper-based attendance.
- Makes basic attendance records easier to search.
- Provides role-based access.
- Reduces duplicate attendance entries.
- Automatically calculates attendance percentage.
- Demonstrates persistent file storage.
- Demonstrates inheritance and modular programming.
- Provides a foundation for future database-based systems.

## 1.6 Major Features

The major features are:

1. **Role-based login**
   - Admin
   - Sub-Admin
   - Student
   - Teacher

2. **User management**
   - Add user
   - View user
   - Update credentials
   - Delete user

3. **Student management**
   - Add student
   - Search student
   - Update student
   - Delete student
   - List students
   - View attendance

4. **Teacher management**
   - Add teacher
   - Search/view teacher
   - Update teacher
   - Delete teacher
   - View teacher attendance

5. **Attendance management**
   - Mark attendance
   - View attendance history
   - Attendance percentage
   - Manual attendance override
   - Duplicate attendance prevention
   - Present, Absent, and Late status

6. **Data validation**
   - Date validation
   - Birth-date validation
   - Field-size validation
   - Duplicate username checking
   - Duplicate roll-number checking
   - Duplicate teacher-ID checking

## 1.7 Limitations

The current project has several limitations:

1. It uses binary files instead of a relational database.
2. Most searches are sequential and may become slower with large amounts of data.
3. The user interface is console-based.
4. The system is primarily intended for local use.
5. It does not provide a web or mobile interface.
6. It does not provide remote multi-user access.
7. Password protection uses simple XOR obfuscation, not modern password hashing.
8. There is no cloud backup facility.
9. Reporting and data export are limited.
10. Attendance is not integrated with biometric devices, QR codes, RFID, or online services.

## 1.8 Organization of the Report

This report is organized into seven chapters. Chapter One introduces the project. Chapter Two reviews existing attendance approaches. Chapter Three presents system analysis and requirements. Chapter Four explains system design and algorithms. Chapter Five discusses development and implementation. Chapter Six presents testing. Chapter Seven discusses limitations, future enhancements, and conclusion. References and appendices are provided at the end.

---

# CHAPTER TWO: LITERATURE REVIEW

## 2.1 Introduction

Attendance management is a common requirement in educational institutions. Different institutions use different approaches depending on their size, available technology, and requirements. The main approaches can be divided into manual, spreadsheet-based, desktop, web-based, mobile-based, and automated systems.

## 2.2 Existing Attendance Practices

Traditional educational institutions commonly use attendance registers in which a teacher records attendance for each class. The records may later be transferred to spreadsheets or other systems.

The manual approach is easy to start but becomes difficult when there are many students, subjects, or attendance dates.

## 2.3 Manual Attendance System

In a manual system:

1. The teacher opens an attendance register.
2. Students are identified.
3. Attendance is marked.
4. The register is stored physically.
5. Attendance percentage is calculated later.

### Advantages

- Simple to use.
- Requires little technology.
- Low initial setup cost.

### Disadvantages

- Time-consuming.
- Difficult to search.
- Paper can be damaged or lost.
- Manual calculations may contain errors.
- Updating old records is inconvenient.

## 2.4 Computerized Attendance Systems

Computerized attendance systems store attendance records electronically. Depending on the system, data may be stored in files or databases.

A computerized system can provide:

- Faster searching.
- Automatic calculation.
- User authentication.
- Record updating.
- Centralized or structured storage.
- Better organization.

The present project uses a local binary-file approach to demonstrate these concepts while keeping the implementation suitable for a C++ academic project.

## 2.5 Comparative Review

| Feature | Manual System | Spreadsheet | Proposed System |
|---|---|---|---|
| User login | No | Limited | Yes |
| Role-based access | No | Limited | Yes |
| Student management | Manual | Yes | Yes |
| Teacher management | Manual | Yes | Yes |
| Attendance history | Paper | Yes | Yes |
| Attendance percentage | Manual | Formula-based | Automatic |
| Duplicate checking | Manual | Limited | Yes |
| Record update | Difficult | Yes | Yes |
| Record deletion | Difficult | Yes | Yes |
| Persistent storage | Paper | File | Binary files |
| Console interface | No | No | Yes |
| Database | No | No/optional | No |
| Web access | No | Usually no | No |

## 2.6 Summary

The review shows that computerized systems can reduce the effort required for managing attendance and records. The proposed system focuses on a small, local, educational environment and demonstrates the basic functions required for attendance management while applying C++ OOP and file-handling concepts.

---

# CHAPTER THREE: SYSTEM ANALYSIS

## 3.1 Introduction

System analysis identifies the requirements, users, existing problems, and resources required for developing the proposed system.

## 3.2 Existing System

The existing/manual approach generally relies on paper registers or basic spreadsheets. The process is often dependent on the teacher or administrator to maintain records and calculate attendance.

The major problems include:

- Repeated manual work.
- Difficult record searching.
- Possible data-entry errors.
- Difficult historical record management.
- Lack of role-based access.
- Manual percentage calculation.

## 3.3 Proposed System

The proposed system provides a structured console application with role-based login and separate management panels.

The application stores information in:

- `credentials.dat`
- `students.dat`
- `teachers.dat`
- `staff.dat`
- `attendance.dat`

The application uses temporary files when updating or deleting records to rewrite the corresponding binary data safely.

## 3.4 Feasibility Analysis

### 3.4.1 Technical Feasibility

The project is technically feasible because it uses standard C++ features and does not require expensive hardware or a database server. A computer capable of compiling and running C++ programs is sufficient.

### 3.4.2 Economic Feasibility

The project has low implementation cost because it uses C++ and local file storage. It does not require paid cloud hosting or a commercial database.

### 3.4.3 Operational Feasibility

The system provides simple menu-driven operations. Users can select options according to their roles, making it suitable for basic educational use.

### 3.4.4 Schedule Feasibility

The project can be developed incrementally by implementing authentication, user management, record management, attendance, testing, and documentation as separate stages.

## 3.5 Functional Requirements

| ID | Requirement |
|---|---|
| FR1 | System shall provide Admin login. |
| FR2 | System shall provide Sub-Admin login. |
| FR3 | System shall provide Student/Teacher login. |
| FR4 | Admin shall manage users. |
| FR5 | Admin/Sub-Admin shall manage students. |
| FR6 | Admin/Sub-Admin shall manage teachers. |
| FR7 | Authorized users shall view attendance. |
| FR8 | Student/Teacher shall be able to mark their attendance according to the implemented role rules. |
| FR9 | Admin/Sub-Admin shall manually mark or override attendance. |
| FR10 | System shall prevent duplicate attendance for the same user, date, and subject. |
| FR11 | System shall validate dates and attendance status. |
| FR12 | System shall store records persistently. |
| FR13 | System shall calculate attendance percentage. |
| FR14 | System shall support record update and deletion. |

## 3.6 Non-Functional Requirements

### Usability
The system should provide understandable menus and messages.

### Reliability
The system should validate files and input before performing important operations.

### Maintainability
The project is separated into header and source files, making maintenance easier.

### Portability
The source code uses standard C++ facilities and can be compiled using a compatible C++ compiler.

### Security
The system uses role checking and XOR-based credential obfuscation. However, XOR is not a modern secure password-storage technique.

### Performance
The system is appropriate for small datasets. Searches use sequential file reading, so performance may decrease with large datasets.

## 3.7 Hardware Requirements

Minimum practical requirements:

- Processor: Dual-core or equivalent.
- RAM: 2 GB or above.
- Storage: At least 100 MB free space.
- Keyboard and monitor.
- Operating system capable of running a C++ compiler.

## 3.8 Software Requirements

- C++ compiler supporting standard C++ features.
- GNU g++ or another compatible compiler.
- Windows/Linux environment.
- Text editor or IDE such as Visual Studio Code.
- Command-line terminal.

The repository includes a compilation example:

`g++ src/*.cpp -Iinclude -o project`

On Windows, the generated program can be executed using:

`.project.exe`

## 3.9 User Roles and Permissions

| Role | Main Permissions |
|---|---|
| Admin | User management, student management, teacher management, attendance viewing, attendance override, system configuration |
| Sub-Admin | Student/teacher management, attendance viewing, attendance override |
| Student | Login, view own attendance, mark own attendance, view personal details |
| Teacher | Login, view attendance, mark own attendance, view personal details |

---

# CHAPTER FOUR: SYSTEM DESIGN

## 4.1 System Architecture

The system follows a modular object-oriented architecture.

**User Interface Layer**
- Main menu
- Login menus
- Role-specific panels
- Management menus

**Application Logic Layer**
- Authentication
- User management
- Student management
- Teacher management
- Attendance management
- Validation

**Persistence Layer**
- Binary files
- Temporary files for record rewriting

### Figure 4.1: Overall Architecture

```
+------------------------------+
|        User Interface        |
| Main Menu / Role Panels      |
+--------------+---------------+
               |
               v
+------------------------------+
|     AuthenticationBase       |
| Authentication / Validation  |
| User / Student / Teacher     |
| Attendance Operations        |
+--------------+---------------+
               |
               v
+------------------------------+
|       Binary File Layer      |
| credentials.dat              |
| students.dat                 |
| teachers.dat                 |
| staff.dat                    |
| attendance.dat               |
+------------------------------+
```

## 4.2 Module Design

### 4.2.1 Main Module

The `main.cpp` file creates:

- `AdminPanel`
- `SubAdminPanel`
- `StudentTeacherPanel`

It displays the main menu and directs users to the appropriate login and panel.

### 4.2.2 Authentication Module

The `AuthenticationBase` class contains common authentication and record-management functionality.

Major functions include:

- `findUser()`
- `verifyCredentials()`
- `addUser()`
- `updateUserCredentials()`
- `deleteUser()`

### 4.2.3 Student Module

The student module provides:

- Add student.
- Search student.
- Update student.
- Delete student.
- List all students.
- View student details.
- View student attendance.

### 4.2.4 Teacher Module

The teacher module provides:

- Add teacher.
- Search/view teacher.
- Update teacher.
- Delete teacher.
- View teacher attendance.

### 4.2.5 Attendance Module

The attendance module provides:

- Mark attendance.
- Check duplicate attendance.
- Update attendance.
- View attendance history.
- Calculate attendance percentage.
- Manual attendance override.

## 4.3 Data/File Design

The project uses fixed-size C++ structures and binary files.

### Table 4.1: Data Files

| File | Purpose |
|---|---|
| credentials.dat | Stores username, password and role |
| students.dat | Stores student profile and academic information |
| teachers.dat | Stores teacher profile information |
| staff.dat | Stores Admin/Sub-Admin staff information |
| attendance.dat | Stores attendance records |
| *_temp.dat | Temporary files used during record rewriting |

### UserRecord

Fields:

- username
- password
- role

### StudentRecord

Fields:

- username
- name
- dateOfBirth
- rollNumber
- semester
- subject
- program
- section

### TeacherRecord

Fields:

- username
- teacherId
- name
- dateOfBirth
- department
- qualification

### StaffRecord

Fields:

- username
- role
- name
- dateOfBirth
- department

### AttendanceRecord

Fields:

- username
- role
- rollNumber
- semester
- subject
- date
- status
- markedBy

## 4.4 Class Design

The project uses inheritance to share common functionality.

### Table 4.2: Main Classes

| Class | Responsibility |
|---|---|
| AuthenticationBase | Common authentication, records, validation and attendance operations |
| AdminPanel | Administrator login and administrative menu |
| SubAdminPanel | Sub-Administrator login and management menu |
| StudentTeacherPanel | Student/Teacher login and personal attendance menu |

### Inheritance Relationship

```
                 AuthenticationBase
                  /       |        \
                 /        |         \
                v         v          v
         AdminPanel  SubAdminPanel  StudentTeacherPanel
```

This structure reduces duplication because common functions are defined in the base class.

## 4.5 Use-Case Description

### Admin Use Cases

- Login.
- Manage Admin/Sub-Admin accounts.
- Manage students.
- Manage teachers.
- View attendance.
- Override attendance.
- View personal details.
- View system configuration.

### Sub-Admin Use Cases

- Login.
- Add students/teachers.
- Manage students.
- Manage teachers.
- View attendance.
- Override attendance.
- View personal details.

### Student Use Cases

- Login.
- View own attendance.
- Mark own attendance.
- View personal details.

### Teacher Use Cases

- Login.
- View own attendance.
- Mark own attendance.
- View personal details.

## 4.6 Data Flow

### Main Data Flow

```
User
  |
  v
Main Menu
  |
  v
Role Selection
  |
  v
Authentication
  |
  +---- Invalid ----> Error Message
  |
  +---- Valid ------> Role Panel
                         |
                         v
                  Application Operations
                         |
                         v
                    Binary Files
```

## 4.7 Attendance Workflow

1. User logs in.
2. System verifies username, password, and role.
3. User selects attendance operation.
4. System identifies the profile.
5. System obtains date and subject information.
6. System checks whether attendance already exists.
7. If duplicate exists, the system prevents a second record.
8. Otherwise, the attendance record is stored.
9. The record can later be displayed from the attendance file.
10. Attendance percentage is calculated from the number of Present records.

## 4.8 Algorithms

### Algorithm 1: User Login

**Input:** Username, password, role  
**Output:** Login success or failure

1. Start.
2. Read username.
3. Read password.
4. Read/select role.
5. Validate the credentials file.
6. Search the username.
7. Decrypt the stored username and password fields using the implemented XOR transformation.
8. Compare the username.
9. Compare the password.
10. Compare the role.
11. If all values match, set current username and role.
12. Display successful login.
13. Otherwise display invalid credentials.
14. Stop.

### Algorithm 2: Add Student

1. Start.
2. Enter username and password.
3. Verify that username does not already exist.
4. Enter student information.
5. Validate all required fields.
6. Check date of birth.
7. Check roll number uniqueness.
8. Create a StudentRecord.
9. Write the record to `students.dat`.
10. If successful, keep the account and profile.
11. Otherwise remove the incomplete account.
12. Stop.

### Algorithm 3: Search Student

1. Start.
2. Enter username, name, or roll number.
3. Search by username.
4. If not found, search by roll number.
5. If not found, search by name.
6. If found, display student details.
7. Otherwise display “Student not found.”
8. Stop.

### Algorithm 4: Mark Attendance

1. Start.
2. Identify the user's role.
3. Verify that the role is Student or Teacher.
4. Load the appropriate profile.
5. Determine roll number/teacher ID.
6. Determine subject.
7. Check whether an attendance record already exists for the same username, date, and subject.
8. If it exists, reject duplicate creation.
9. Otherwise create an AttendanceRecord.
10. Save the record to `attendance.dat`.
11. Stop.

### Algorithm 5: Manual Attendance Override

1. Start.
2. Enter target username.
3. Verify that the user exists.
4. Verify that the user is Student or Teacher.
5. Verify roll number or teacher ID.
6. Get the current date.
7. Enter attendance status.
8. Validate Present, Absent, or Late.
9. Check whether an attendance record already exists.
10. If it exists, update its status and marked-by field.
11. Otherwise create a new attendance record.
12. Save the result.
13. Stop.

### Algorithm 6: Attendance Percentage

1. Start.
2. Read attendance records for a user.
3. Apply semester/subject filters if supplied.
4. Count total matching records.
5. Count Present records.
6. Calculate:
   
   **Attendance Percentage = (Present Records / Total Records) × 100**

7. Display total records, present records, and percentage.
8. Stop.

### Algorithm 7: Delete Student

1. Start.
2. Enter student username.
3. Search the student.
4. Display details.
5. Ask for confirmation.
6. If confirmation is not given, cancel.
7. Remove the student's attendance records.
8. Remove the student's profile record.
9. Remove the user's credentials.
10. Report success or failure.
11. Stop.

## 4.9 Input Validation and Error Handling

The system implements several validation mechanisms:

- Checks for empty/oversized fields.
- Checks username uniqueness.
- Checks roll-number uniqueness.
- Checks teacher-ID uniqueness.
- Checks valid dates.
- Checks valid birth dates.
- Checks valid attendance status.
- Checks binary file record sizes.
- Detects corrupted file sizes.
- Uses temporary files when rewriting records.
- Prevents users from deleting their own currently active Admin account.
- Checks that a profile exists for Student and Teacher credentials.
- Prevents duplicate attendance.

---

# CHAPTER FIVE: SYSTEM DEVELOPMENT AND IMPLEMENTATION

## 5.1 Development Environment

The system was developed as a C++ console application.

### Development tools

- Programming Language: C++
- Compiler: g++
- IDE/Text Editor: Visual Studio Code or compatible editor
- Storage: Local binary files
- Version Control: Git/GitHub

## 5.2 Programming Language

C++ was selected because the project is intended to demonstrate object-oriented programming concepts. The implementation uses:

- Classes.
- Inheritance.
- Encapsulation.
- Constructors.
- Member functions.
- Structures.
- Strings.
- File streams.
- Vectors.
- Input/output operations.
- Function decomposition.

## 5.3 Project Structure

The repository contains the following major files:

```
Smart_Attendance_System_II-Semester/
|
+-- include/
|   +-- AuthenticationBase.h
|   +-- Common.h
|   +-- Panels.h
|
+-- src/
|   +-- AuthenticationBase.cpp
|   +-- Common.cpp
|   +-- Panels.cpp
|   +-- main.cpp
|
+-- credentials.dat
+-- students.dat
+-- teachers.dat
+-- staff.dat
+-- attendance.dat
+-- project.exe
+-- README.md
```

### Table 5.1: Source Files

| File | Purpose |
|---|---|
| main.cpp | Main application entry point |
| Common.h | Shared constants, structures and helper declarations |
| Common.cpp | Common helper implementation |
| AuthenticationBase.h | Base class declaration |
| AuthenticationBase.cpp | Authentication, management and attendance logic |
| Panels.h | Role-specific class declarations |
| Panels.cpp | Role-specific login and menu implementation |

## 5.4 Authentication Module

The authentication system stores user credentials in `credentials.dat`.

Each user has:

- Username.
- Password.
- Role.

The `verifyCredentials()` function searches for the username and checks both password and role before granting access.

The system initializes default administrative accounts when required:

- Admin account: `admin`
- Sub-Admin account: `subadmin`

The corresponding default passwords are defined in the implementation and should be changed in a production system.

## 5.5 User Management Module

The Admin panel provides:

- Add Admin/Sub-Admin.
- View user details.
- Search user.
- Update Admin/Sub-Admin credentials.
- Delete user.

The system prevents deletion of the account currently being used by the Admin.

## 5.6 Student Management Module

Student records contain personal and academic information.

The module supports:

- Add student.
- Search by username.
- Search by roll number.
- Search by name.
- Update student.
- Delete student.
- View student details.
- List all students.
- View attendance.
- View all student attendance by date.

The system checks roll-number uniqueness before adding or changing a student.

## 5.7 Teacher Management Module

Teacher records include:

- Username.
- Teacher ID.
- Name.
- Date of birth.
- Department.
- Qualification.

The module supports:

- Add teacher.
- View/search teacher.
- Update teacher details.
- Delete teacher.
- View teacher attendance.

Teacher ID uniqueness is checked during record creation.

## 5.8 Attendance Module

Attendance records include:

- Username.
- Role.
- Roll number or teacher ID.
- Semester.
- Subject.
- Date.
- Status.
- Marked by.

Supported statuses are:

- Present
- Absent
- Late

The system prevents duplicate records based on username, date, and subject.

The manual override facility allows Admin/Sub-Admin users to update an existing attendance record or create a new one.

## 5.9 File Handling Module

The project uses C++ binary file streams.

### Append Operation

New records are written using binary append mode.

### Read Operation

Records are read sequentially using `ifstream`.

### Update Operation

Because fixed-size binary records are stored in files, updates are performed by:

1. Opening the original file for reading.
2. Opening a temporary file for writing.
3. Reading records one by one.
4. Replacing the target record.
5. Writing all records to the temporary file.
6. Closing both files.
7. Replacing the original file with the temporary file.

### Delete Operation

Deletion follows a similar file-rewrite method, except the matching record is skipped.

This method is implemented for user, student, teacher, and attendance data.

## 5.10 Data Validation

The `Common.cpp` module contains helper functions for:

- Current date generation.
- Date validation.
- Birth-date validation.
- Attendance status validation.
- Case-insensitive comparison.
- Field-size validation.
- Safe string copying.
- File replacement.
- Menu input validation.

## 5.11 Security and Credential Protection

The project uses an XOR transformation with a fixed key for username/password fields before writing credential records to the binary file.

This should be described as **obfuscation**, not strong encryption. A fixed XOR key is reversible and does not provide modern password security.

For a production version, password hashing with a modern password-hashing algorithm and secure authentication practices should be implemented.

## 5.12 User Interface

The system provides a menu-driven console interface.

### Main Menu

1. Admin Login
2. Sub-Admin Login
3. Student / Teacher Login
4. System Help
5. Exit

### Admin Panel

1. User Management
2. Student Management
3. Teacher Management
4. View User Attendance
5. Manual Attendance Mark/Override
6. System Configuration
7. View My Personal Details
8. Logout

### Sub-Admin Panel

1. Add Student/Teacher
2. Student Management
3. Teacher Management
4. View Attendance
5. Manual Attendance Override
6. View My Personal Details
7. Logout

### Student/Teacher Panel

1. View My Attendance
2. Mark My Attendance
3. View My Personal Details
4. Logout

---

# CHAPTER SIX: SYSTEM TESTING

## 6.1 Testing Introduction

Testing is performed to determine whether the system behaves according to its functional requirements and handles invalid inputs appropriately.

Because this is an academic local application, testing focuses mainly on:

- Authentication.
- Record creation.
- Searching.
- Updating.
- Deletion.
- Attendance.
- Duplicate prevention.
- Validation.
- File handling.

## 6.2 Testing Strategy

The system can be tested using:

1. Unit-level testing of individual functions.
2. Module testing.
3. Integration testing.
4. Functional testing.
5. Validation testing.
6. Error-handling testing.

## 6.3 Functional Test Cases

| ID | Test Case | Input/Action | Expected Result |
|---|---|---|---|
| TC01 | Admin Login | Valid Admin credentials | Admin panel opens |
| TC02 | Invalid Login | Wrong password | Login rejected |
| TC03 | Sub-Admin Login | Valid Sub-Admin credentials | Sub-Admin panel opens |
| TC04 | Student Login | Valid student credentials and S role | Student panel opens |
| TC05 | Teacher Login | Valid teacher credentials and T role | Teacher panel opens |
| TC06 | Add Student | Unique username and roll number | Student created |
| TC07 | Duplicate Username | Existing username | Creation rejected |
| TC08 | Duplicate Roll | Existing roll number | Creation rejected |
| TC09 | Search Student | Valid name/username/roll | Student details displayed |
| TC10 | Update Student | Valid new information | Student record updated |
| TC11 | Delete Student | Confirm deletion | Student and related attendance removed |
| TC12 | Add Teacher | Unique teacher ID | Teacher created |
| TC13 | Duplicate Teacher ID | Existing ID | Creation rejected |
| TC14 | Update Teacher | Valid new details | Teacher updated |
| TC15 | Mark Attendance | Valid student/teacher | Attendance saved |
| TC16 | Duplicate Attendance | Same user/date/subject | Duplicate rejected |
| TC17 | Override Attendance | Existing attendance | Status updated |
| TC18 | Invalid Status | Invalid status | Operation rejected |
| TC19 | View Attendance | Existing records | History displayed |
| TC20 | Percentage | Attendance records | Percentage calculated |

## 6.4 Validation Test Cases

| ID | Validation | Expected Behavior |
|---|---|---|
| VT01 | Empty username | Reject input |
| VT02 | Oversized field | Reject input |
| VT03 | Invalid date | Reject input |
| VT04 | Invalid attendance status | Reject input |
| VT05 | Duplicate username | Reject creation |
| VT06 | Duplicate roll number | Reject creation |
| VT07 | Duplicate teacher ID | Reject creation |
| VT08 | Corrupted record size | Display file corruption error |
| VT09 | Missing profile | Prevent inconsistent Student/Teacher account |
| VT10 | Delete active Admin account | Prevent deletion |

## 6.5 Error Handling Tests

The system includes messages for:

- Invalid credentials.
- Missing user.
- Missing student/teacher profile.
- Invalid role.
- Invalid date.
- Invalid attendance status.
- Duplicate records.
- File opening errors.
- Corrupted file record size.
- Failed update/deletion.

## 6.6 Testing Limitations

The repository contains the implementation and executable, but a formal laboratory test log, screenshots, test-data sheet, and independent test report are not part of the source repository. Therefore, before final academic submission, the project team should execute the listed test cases on the final build and record actual results and screenshots.

---

# CHAPTER SEVEN: LIMITATIONS, FUTURE ENHANCEMENTS AND CONCLUSION

## 7.1 Limitations

The current implementation has the following limitations:

### 7.1.1 Binary File Storage

The project stores records in binary files instead of a database. This is suitable for demonstrating file handling but is less flexible than a database system.

### 7.1.2 Sequential Searching

Most searches read records sequentially. With a large number of records, this may reduce performance.

### 7.1.3 Console Interface

The user interface is text-based. It does not provide a graphical, web, or mobile interface.

### 7.1.4 Local Operation

The system is designed for local execution and does not provide centralized remote access.

### 7.1.5 Basic Credential Protection

The XOR method used by the project is reversible and should not be treated as secure password encryption.

### 7.1.6 Limited Reporting

The current implementation provides attendance history and percentage information but does not provide advanced report generation, PDF export, graphical statistics, or automated institutional reports.

## 7.2 Future Enhancements

The system can be improved in the following ways:

1. Replace binary files with MySQL, PostgreSQL, SQLite, or another database.
2. Use secure password hashing.
3. Develop a graphical user interface.
4. Develop a web-based interface.
5. Develop an Android/mobile application.
6. Add QR-code attendance.
7. Add RFID-based attendance.
8. Add biometric attendance.
9. Add automated email/SMS notifications.
10. Add PDF and Excel attendance reports.
11. Add attendance charts and dashboards.
12. Add subject-wise and semester-wise reports.
13. Add role and permission configuration.
14. Add audit logs.
15. Add automated backup and restore.
16. Add cloud-based storage.
17. Add multi-user concurrent access.
18. Add stronger database transaction and recovery mechanisms.

## 7.3 Conclusion

The **Smart Attendance Management System** successfully demonstrates the development of a practical C++ application for managing users, students, teachers, and attendance records.

The project applies important concepts of object-oriented programming such as classes, inheritance, encapsulation, constructors, and member functions. It also demonstrates binary file handling, record searching, updating, deletion, validation, authentication, and modular programming.

The role-based design separates the responsibilities of administrators, sub-administrators, students, and teachers. Attendance functionality includes duplicate prevention, status validation, attendance history, percentage calculation, and administrative override.

Although the current system has limitations such as binary-file storage, sequential searching, a console interface, and basic credential obfuscation, it provides a useful foundation for further development. With database integration, secure authentication, web/mobile access, automated attendance technologies, and advanced reporting, the system could be extended into a more complete institutional attendance platform.

Overall, the project meets its academic purpose by applying second-semester BIT programming and object-oriented concepts to a real-world attendance management problem.

---

# REFERENCES

1. Purbanchal University, **Bachelor of Information Technology (BIT) Curriculum**, Faculty of Science and Technology.

2. Purbanchal University, **Project-II (BIT156CO)**, Bachelor of Information Technology, Second Semester.

3. Balagurusamy, E., **Object Oriented Programming with C++**, McGraw Hill Education.

4. Schildt, H., **C++: The Complete Reference**, McGraw Hill.

5. Stroustrup, B., **The C++ Programming Language**, Addison-Wesley.

6. The project source code and implementation files maintained in the project's GitHub repository.

---

# APPENDIX 1: USER MANUAL

## A1.1 Starting the Application

Compile the project using:

```bash
g++ src/*.cpp -Iinclude -o project
```

Run the application on Windows using:

```powershell
.\project.exe
```

## A1.2 Main Menu

After starting, the system displays:

1. Admin Login
2. Sub-Admin Login
3. Student / Teacher Login
4. System Help
5. Exit

Select the required option by entering the menu number.

## A1.3 Admin Login

The system initially creates the default administrator account defined in the source code.

**Default username:** `admin`  
**Default password:** `admin123`

For actual deployment, the default password should be changed immediately.

## A1.4 Sub-Admin Login

**Default username:** `subadmin`  
**Default password:** `sub123`

For actual deployment, the default password should be changed immediately.

## A1.5 Creating a Student

1. Log in as Admin or Sub-Admin.
2. Open Student Management.
3. Select Add Student.
4. Enter username and password.
5. Enter student name.
6. Enter date of birth.
7. Enter roll number.
8. Enter semester.
9. Enter subject/course.
10. Enter program.
11. Enter section.
12. Submit the information.

The system validates the information and stores the account/profile if the data is valid.

## A1.6 Searching a Student

1. Open Student Management.
2. Select Search Student.
3. Enter username, name, or roll number.
4. The system displays the matching student record.

## A1.7 Marking Attendance

1. Log in using a Student or Teacher account.
2. Select Mark My Attendance.
3. The system determines the current date.
4. The system checks for an existing attendance record.
5. If no duplicate exists, attendance is saved.

## A1.8 Manual Attendance Override

Admin/Sub-Admin users can:

1. Select Manual Attendance Mark/Override.
2. Enter target username.
3. Verify the student's roll number or teacher ID.
4. Select Present, Absent, or Late.
5. If a record already exists, update it.
6. Otherwise create a new record.

---

# APPENDIX 2: PROJECT ALGORITHMS SUMMARY

## Authentication Algorithm

```
START
 |
Read username, password and role
 |
Search credentials file
 |
User found?
 |---- No ----> Invalid Login -> STOP
 |
Yes
 |
Compare password and role
 |
Match?
 |---- No ----> Invalid Login -> STOP
 |
Yes
 |
Set current user and role
 |
Open role-specific panel
 |
STOP
```

## Attendance Algorithm

```
START
 |
Identify user and role
 |
Load profile
 |
Determine subject/date/ID
 |
Check duplicate attendance
 |
Duplicate?
 |---- Yes ----> Reject/Override
 |
No
 |
Create AttendanceRecord
 |
Write to attendance.dat
 |
Display success
 |
STOP
```

---

# APPENDIX 3: DATABASE/FIL​E FIELD SUMMARY

## Credentials

```
username
password
role
```

## Student

```
username
name
dateOfBirth
rollNumber
semester
subject
program
section
```

## Teacher

```
username
teacherId
name
dateOfBirth
department
qualification
```

## Staff

```
username
role
name
dateOfBirth
department
```

## Attendance

```
username
role
rollNumber
semester
subject
date
status
markedBy
```

---

# APPENDIX 4: SCREENSHOT CHECKLIST FOR FINAL SUBMISSION

The following screenshots should be captured from the final running system and inserted into the final formatted report:

1. Main application menu.
2. Admin login.
3. Admin dashboard.
4. User management menu.
5. Add student screen.
6. Student details screen.
7. Student search result.
8. Student update screen.
9. Teacher management menu.
10. Add teacher screen.
11. Teacher details screen.
12. Student/Teacher login.
13. Student attendance screen.
14. Attendance marking screen.
15. Attendance history.
16. Attendance percentage result.
17. Manual attendance override.
18. System configuration.
19. Invalid login message.
20. Duplicate attendance message.
21. Invalid input message.
22. Successful logout.
23. Final exit screen.

---

# APPENDIX 5: PROJECT FILE SUMMARY

```
include/
├── AuthenticationBase.h
├── Common.h
└── Panels.h

src/
├── AuthenticationBase.cpp
├── Common.cpp
├── Panels.cpp
└── main.cpp

Data Files/
├── credentials.dat
├── students.dat
├── teachers.dat
├── staff.dat
└── attendance.dat
```

---

# APPENDIX 6: PROJECT DEVELOPMENT TASKS

| Phase | Major Activities |
|---|---|
| Phase 1 | Topic selection and requirement identification |
| Phase 2 | Problem analysis |
| Phase 3 | System design |
| Phase 4 | Class and data-structure design |
| Phase 5 | Authentication implementation |
| Phase 6 | Student and teacher management |
| Phase 7 | Attendance implementation |
| Phase 8 | Validation and error handling |
| Phase 9 | Integration and debugging |
| Phase 10 | Testing |
| Phase 11 | Documentation |
| Phase 12 | Final presentation and submission |

---

# APPENDIX 7: OBJECT-ORIENTED CONCEPTS USED

## Encapsulation

Data and related operations are organized inside classes such as `AuthenticationBase` and the role-specific panel classes.

## Inheritance

`AdminPanel`, `SubAdminPanel`, and `StudentTeacherPanel` inherit common functionality from `AuthenticationBase`.

## Abstraction

Common authentication, file-handling, searching, and attendance operations are provided through member functions rather than exposing all implementation details to the role-specific panels.

## Polymorphism

The project mainly uses inheritance and shared base-class functionality. It does not heavily depend on runtime virtual-function polymorphism.

## Modular Programming

The source is separated into:

- Header files.
- Implementation files.
- Common utility functions.
- Role-specific panel implementation.
- Main program.

---

# APPENDIX 8: PROJECT SCOPE SUMMARY

The current project is a **local educational attendance management prototype**. It is intended to demonstrate practical application of C++ OOP and file handling rather than provide a full enterprise-level attendance platform.

The system currently focuses on:

**Authentication → User Management → Student/Teacher Management → Attendance → File Storage → Reporting**

Future development can extend this foundation toward:

**Authentication → Database → Web/Mobile Interface → Automated Attendance → Analytics → Cloud Backup**

---

## END OF REPORT
