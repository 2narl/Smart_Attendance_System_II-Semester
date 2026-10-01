# PROJECT REPORT

## SMART ATTENDANCE MANAGEMENT SYSTEM

**A Project Report**  
Submitted in partial fulfillment of the requirements of **Project-II (BIT156CO)**  
of  
**Bachelor of Information Technology (BIT)**

**Submitted to:**  
Purbanchal University  
Faculty of Science and Technology  
Biratnagar, Nepal

**Submitted by:**  
[Student Name] — [Symbol No.]  
[Second Student Name, if applicable] — [Symbol No.]

**Under the Supervision of:**  
[Supervisor Name]  
[Designation]

[College Name]  
[College Address]

[Month, Year]

---

# CERTIFICATE OF PROJECT COMPLETION

This is to certify that the project work entitled **“Smart Attendance Management System”** has been carried out by the student(s) of Bachelor of Information Technology (BIT), in partial fulfillment of the requirements of Project-II under Purbanchal University.

The system has been developed using C++ and demonstrates object-oriented programming, file handling, authentication, data validation, student and teacher management, and attendance management.

**Project Supervisor:** __________________________  
**Signature:** _________________________________  
**Date:** _____________________________________

**Program Coordinator:** ________________________  
**Signature:** _________________________________  
**Date:** _____________________________________

---

# STUDENT'S DECLARATION

We hereby declare that the project report entitled **“Smart Attendance Management System”** is our original academic work carried out for Project-II of the Bachelor of Information Technology program under Purbanchal University.

The system, implementation, testing, and documentation presented in this report are based on the project developed by us. References and learning resources used during the project have been acknowledged appropriately.

**Student Name:** ______________________________  
**Symbol No.:** ________________________________  
**Signature:** _________________________________  
**Date:** _____________________________________

---

# ACKNOWLEDGEMENT

We would like to express our sincere gratitude to Purbanchal University for providing the opportunity to undertake this project as part of the Bachelor of Information Technology program.

We are thankful to our project supervisor for valuable guidance, suggestions, and encouragement throughout the project. We also thank the program coordinator, teachers, staff members, classmates, and friends who provided support and suggestions during the development and documentation of the system.

Finally, we are grateful to our family members for their continuous encouragement and support.

---

# ABSTRACT

The **Smart Attendance Management System** is a C++ console-based application developed as an academic Project-II for the Bachelor of Information Technology program. The system provides a structured way to manage user accounts, student records, teacher records, staff information, and attendance records.

The system supports role-based authentication for **Admin, Sub-Admin, Student, and Teacher** users. Administrators and Sub-Administrators can manage student and teacher records and perform attendance operations, while students and teachers can log in, view their personal information, view attendance, and mark their own attendance.

The application is implemented using object-oriented programming concepts such as classes, inheritance, encapsulation, constructors, member functions, and modular source/header files. Persistent data is stored in binary files including `credentials.dat`, `students.dat`, `teachers.dat`, `staff.dat`, and `attendance.dat`. The system also provides input validation, duplicate checking, record searching, updating, deletion, attendance percentage calculation, and file-rewrite operations.

The project demonstrates how C++ OOP and file handling can be applied to a practical attendance-management problem. The current version is intended for local academic use and can be extended in the future with database storage, secure password hashing, graphical or web interfaces, automated attendance, and advanced reporting.

**Keywords:** Attendance Management, C++, Object-Oriented Programming, Binary File Handling, Authentication, Student Management, Teacher Management.

---

# TABLE OF CONTENTS

1. Chapter 1: Introduction  
   1.1 Background and Significance of the Project  
   1.2 Objectives and Scope  
   1.3 Project Features  
   1.4 Summary and Project Organization  

2. Chapter 2: Literature Review  
   2.1 Introduction  
   2.2 Previous System or Work Study  
   2.3 Manual Attendance System  
   2.4 Computerized Attendance System  
   2.5 Comparative Review  
   2.6 Summary  

3. Chapter 3: Analysis of Issues and Solution  
   3.1 Introduction to Existing Systems  
   3.2 Issues in the Existing System  
   3.3 Proposed Solution  
   3.4 Methods Used to Solve the Issues  
   3.5 Functional Requirements  
   3.6 Non-Functional Requirements  
   3.7 Feasibility of the Proposed Solution  

4. Chapter 4: Design Specification and Implementation  
   4.1 System Architecture  
   4.2 Context Diagram  
   4.3 Level 1 Data Flow Diagram  
   4.4 Data Dictionary  
   4.5 Working Procedure  
   4.6 Flowchart Diagram  
   4.7 Use Case Diagram  
   4.8 Class Design and Module Structure  
   4.9 Implementation Details  

5. Chapter 5: Experiment Result and Analysis  
   5.1 Introduction  
   5.2 Experiment Environment  
   5.3 Testing Scenarios  
   5.4 Experiment and Result  
   5.5 Result Analysis  

6. Chapter 6: Conclusion and Future Work  
   6.1 Conclusion  
   6.2 Limitations  
   6.3 Future Work  

References  
Bibliography (Optional)  
Appendixes

---

# REPORT FORMATTING STANDARDS

The final report should be formatted in a word-processing document using the following standards:

| Item | Required Format |
|---|---|
| Font | Times New Roman |
| Normal text | 12 pt |
| Line spacing | 1.5 |
| Paragraph spacing | 18 pt |
| Left margin | 1.5 inch |
| Right margin | 1.25 inch |
| Top margin | 1.25 inch |
| Bottom margin | 1.25 inch |
| Header | 0.5 inch |
| Footer | 0.5 inch |
| Heading 1 | 16 pt, Bold |
| Heading 2 | 14 pt, Bold |
| Heading 3 | 13 pt, Bold |
| Heading 4 | 12 pt, Bold |

**Note:** Markdown cannot enforce Times New Roman, margins, or Word paragraph spacing. These settings should be applied when this report is transferred to MS Word or another word processor.

---

# LIST OF FIGURES

| Figure | Title |
|---|---|
| Figure 4.1 | System Architecture |
| Figure 4.2 | Context Diagram |
| Figure 4.3 | Level 1 Data Flow Diagram |
| Figure 4.4 | Attendance Working Flowchart |
| Figure 4.5 | Use Case Diagram |
| Figure 4.6 | Class/Inheritance Structure |

---

# LIST OF TABLES

| Table | Title |
|---|---|
| Table 3.1 | Issues in Existing System and Proposed Solutions |
| Table 3.2 | Functional Requirements |
| Table 3.3 | Non-Functional Requirements |
| Table 4.1 | Data Dictionary |
| Table 4.2 | Main Classes |
| Table 5.1 | Experiment Environment |
| Table 5.2 | Testing Scenarios and Results |

---

# LIST OF ABBREVIATIONS

| Abbreviation | Meaning |
|---|---|
| BIT | Bachelor of Information Technology |
| PU | Purbanchal University |
| OOP | Object-Oriented Programming |
| CRUD | Create, Read, Update, Delete |
| DFD | Data Flow Diagram |
| IDE | Integrated Development Environment |
| UI | User Interface |
| XOR | Exclusive OR |
| ID | Identification |
| DOB | Date of Birth |
| RAM | Random Access Memory |
| CPU | Central Processing Unit |

---

# CHAPTER 1: INTRODUCTION

## 1.1 Background and Significance of the Project

Attendance is an important activity in educational institutions because it helps maintain records of student and teacher participation. In a traditional environment, attendance is commonly recorded using paper registers or manually maintained spreadsheets. Such methods can make searching, updating, storing, and calculating attendance more difficult as the number of records increases.

The **Smart Attendance Management System** was developed to provide a simple computerized method for managing attendance and related records. The system is designed for a small educational environment such as a school, college, or university.

The project is implemented in C++ using object-oriented programming principles. Instead of using a database server, the current implementation stores information in binary files. This approach keeps the system lightweight and demonstrates practical use of C++ file handling.

The system uses a common base class named `AuthenticationBase`. Role-specific classes named `AdminPanel`, `SubAdminPanel`, and `StudentTeacherPanel` inherit common functionality from the base class. This structure reduces code duplication and demonstrates inheritance.

The project is significant from an academic perspective because it applies C++ programming, object-oriented programming, file handling, authentication, validation, and modular programming to a practical real-world problem.

## 1.2 Objectives and Scope

### 1.2.1 General Objective

To develop a simple and organized attendance management system using C++ and object-oriented programming concepts.

### 1.2.2 Specific Objectives

The specific objectives are:

1. To implement role-based user authentication.
2. To manage Admin and Sub-Admin accounts.
3. To manage student records.
4. To manage teacher records.
5. To store staff information.
6. To allow students and teachers to view their attendance.
7. To allow students and teachers to mark their own attendance.
8. To allow authorized administrative users to mark or override attendance.
9. To prevent duplicate attendance records for the same user, date, and subject.
10. To calculate attendance percentage.
11. To validate user input and important record fields.
12. To store records persistently using binary files.
13. To demonstrate practical use of OOP and file handling.

### 1.2.3 Scope of the Project

The project focuses on local attendance management for a small educational environment.

The scope includes:

- Role-based authentication.
- Admin and Sub-Admin management.
- Student management.
- Teacher management.
- Staff information management.
- Attendance marking.
- Attendance history.
- Attendance percentage calculation.
- Manual attendance override.
- Search and update operations.
- Duplicate prevention.
- Data validation.
- Binary-file storage.

The current project does not attempt to provide a large-scale cloud-based institutional information system.

## 1.3 Project Features

The major features of the system are:

### 1.3.1 Authentication

The system provides separate login facilities for:

- Admin.
- Sub-Admin.
- Student.
- Teacher.

The login process verifies username, password, and role.

### 1.3.2 User Management

Admin users can:

- Add Admin/Sub-Admin accounts.
- View user details.
- Search users.
- Update user credentials.
- Delete users.

### 1.3.3 Student Management

Authorized users can:

- Add students.
- Search students.
- Search by username, name, or roll number.
- Update student information.
- Delete student records.
- List student records.
- View student attendance.

### 1.3.4 Teacher Management

Authorized users can:

- Add teachers.
- Search teachers.
- Update teacher information.
- Delete teacher records.
- View teacher attendance.

### 1.3.5 Attendance Management

The system supports:

- Marking attendance.
- Viewing attendance history.
- Present, Absent, and Late status.
- Duplicate attendance prevention.
- Manual attendance override.
- Attendance percentage calculation.

### 1.3.6 Validation

The system validates:

- Username uniqueness.
- Roll-number uniqueness.
- Teacher-ID uniqueness.
- Date format.
- Birth date.
- Attendance status.
- Field length.
- Binary file record size.
- Menu input.

## 1.4 Summary and Project Organization

This report is organized into six chapters.

**Chapter 1: Introduction** presents the background, significance, objectives, scope, features, and organization of the project.

**Chapter 2: Literature Review** discusses previous and existing attendance-management approaches and compares manual, spreadsheet-based, and computerized systems.

**Chapter 3: Analysis of Issues and Solution** identifies problems in existing attendance practices and explains how the proposed system addresses them.

**Chapter 4: Design Specification and Implementation** presents the architecture, context diagram, DFD, data dictionary, working procedure, flowchart, use case diagram, class structure, and implementation details.

**Chapter 5: Experiment Result and Analysis** presents the testing environment, test scenarios, results, and analysis of the implemented system.

**Chapter 6: Conclusion and Future Work** presents the conclusion, limitations, and possible future improvements.

---

# CHAPTER 2: LITERATURE REVIEW

## 2.1 Introduction

Literature review provides an understanding of previous approaches and systems related to attendance management. Attendance systems range from simple manual registers to computerized, web-based, mobile, QR-code, RFID, and biometric systems.

For this academic project, the review mainly focuses on manual and computerized attendance management because the proposed system is a local C++ application.

## 2.2 Previous System or Work Study

Traditional attendance management normally involves a teacher recording student attendance in a physical register. Later, the attendance may be transferred to a spreadsheet or another record system.

Computerized attendance systems improve this process by storing information electronically and providing functions such as searching, updating, reporting, and automatic calculation.

Modern systems may also use:

- Web applications.
- Mobile applications.
- QR codes.
- RFID cards.
- Biometric devices.
- Cloud databases.

The present project uses a simpler local approach based on C++ and binary files. This approach is suitable for demonstrating programming and file-handling concepts within an academic project.

## 2.3 Manual Attendance System

A manual attendance process generally follows these steps:

1. Teacher opens the attendance register.
2. Students are identified.
3. Attendance is marked.
4. Register is stored physically.
5. Attendance is calculated later.

### Advantages

- Simple to understand.
- Requires little technical infrastructure.
- Easy to start.

### Disadvantages

- Searching records is time-consuming.
- Manual calculations can contain errors.
- Paper records can be lost or damaged.
- Updating historical records is inconvenient.
- Duplicate or inconsistent records may occur.
- Maintaining large numbers of records is difficult.

## 2.4 Computerized Attendance System

A computerized attendance system stores attendance information electronically.

Typical functions include:

- User authentication.
- Student management.
- Teacher management.
- Attendance marking.
- Attendance searching.
- Automatic percentage calculation.
- Record updating.
- Record deletion.
- Persistent storage.

The proposed system provides these basic functions using a C++ console interface and binary-file storage.

## 2.5 Comparative Review

| Feature | Manual System | Spreadsheet | Proposed System |
|---|---|---|---|
| User login | No | Limited | Yes |
| Role-based access | No | Limited | Yes |
| Student management | Manual | Yes | Yes |
| Teacher management | Manual | Yes | Yes |
| Attendance history | Paper | Yes | Yes |
| Percentage calculation | Manual | Formula | Automatic |
| Duplicate checking | Manual | Limited | Yes |
| Record update | Difficult | Yes | Yes |
| Record deletion | Difficult | Yes | Yes |
| Persistent storage | Paper | File | Binary files |
| Database server | No | No | No |
| Web access | No | Usually no | No |
| Console interface | No | No | Yes |

## 2.6 Summary

The literature review shows that computerized attendance management can organize attendance information more effectively than a purely manual process. The proposed project focuses on a small local environment and uses C++ OOP and binary files to implement the required attendance-management functions.

---

# CHAPTER 3: ANALYSIS OF ISSUES AND SOLUTION

## 3.1 Introduction to Existing Systems

The existing attendance process considered in this project is primarily manual or basic spreadsheet-based management.

In a manual process, attendance is recorded in a physical register. In a spreadsheet-based process, records are stored electronically but often depend on manually maintained files and formulas.

The main issue is that these approaches do not provide an integrated system for authentication, user management, attendance marking, duplicate checking, and role-based operations.

## 3.2 Issues in the Existing System

The major issues identified are:

1. Manual attendance recording requires repeated work.
2. Searching old attendance records is inconvenient.
3. Attendance percentage may need manual calculation.
4. Updating records is difficult in paper-based systems.
5. Different users require different permissions.
6. Duplicate attendance can occur without validation.
7. Student and teacher records may be maintained separately.
8. Physical records may be damaged or lost.
9. Maintaining large records manually becomes difficult.
10. There is no centralized process for authentication and attendance management.

## 3.3 Proposed Solution

The proposed solution is a local console-based **Smart Attendance Management System** developed in C++.

The system provides:

- Role-based authentication.
- Student and teacher management.
- Admin and Sub-Admin management.
- Attendance marking.
- Attendance viewing.
- Attendance percentage calculation.
- Duplicate prevention.
- Data validation.
- Persistent binary-file storage.

The main data files are:

- `credentials.dat`
- `students.dat`
- `teachers.dat`
- `staff.dat`
- `attendance.dat`

## 3.4 Methods Used to Solve the Issues

### 3.4.1 Role-Based Authentication

The system verifies username, password, and role before granting access. This separates the operations available to Admin, Sub-Admin, Student, and Teacher users.

### 3.4.2 Electronic Record Storage

Binary files are used to store records persistently. This removes dependence on paper records and allows the program to read and update records electronically.

### 3.4.3 Search and Update Operations

The system provides searching by username, name, roll number, or teacher ID where applicable. Record updates are performed by rewriting the relevant binary file through a temporary file.

### 3.4.4 Duplicate Prevention

Before saving attendance, the system checks whether an attendance record already exists for the same user, date, and subject.

### 3.4.5 Automatic Percentage Calculation

The system counts total attendance records and Present records and calculates:

**Attendance Percentage = (Present Records / Total Records) × 100**

### 3.4.6 Input Validation

The system validates dates, attendance status, field sizes, usernames, roll numbers, teacher IDs, and menu choices.

### 3.4.7 Controlled Attendance Override

Admin and Sub-Admin users can manually create or update attendance records when correction is required.

### Table 3.1: Issues in Existing System and Proposed Solutions

| Existing Issue | Proposed Solution |
|---|---|
| Manual attendance recording | Computerized attendance module |
| Difficult searching | Search functions |
| Manual percentage calculation | Automatic calculation |
| Duplicate attendance | Duplicate checking |
| Different access requirements | Role-based authentication |
| Difficult updating | File-rewrite update mechanism |
| Physical record storage | Binary-file storage |
| Invalid data | Input validation |
| Difficult attendance correction | Admin/Sub-Admin override |

## 3.5 Functional Requirements

| ID | Functional Requirement |
|---|---|
| FR1 | The system shall provide Admin login. |
| FR2 | The system shall provide Sub-Admin login. |
| FR3 | The system shall provide Student/Teacher login. |
| FR4 | Admin shall manage Admin/Sub-Admin users. |
| FR5 | Authorized users shall manage student records. |
| FR6 | Authorized users shall manage teacher records. |
| FR7 | Users shall view applicable attendance records. |
| FR8 | Students and teachers shall be able to mark their own attendance. |
| FR9 | Admin/Sub-Admin shall be able to mark or override attendance. |
| FR10 | The system shall prevent duplicate attendance. |
| FR11 | The system shall validate input data. |
| FR12 | The system shall store records persistently. |
| FR13 | The system shall calculate attendance percentage. |
| FR14 | The system shall support record update and deletion. |

## 3.6 Non-Functional Requirements

### 3.6.1 Usability

The system should provide simple menu-driven interaction and understandable messages.

### 3.6.2 Reliability

The system should validate input and file structures before performing important operations.

### 3.6.3 Maintainability

The project is divided into header and source files and uses a common base class for shared functionality.

### 3.6.4 Performance

The current system is suitable for small datasets. Most searches are sequential and therefore may become slower as the number of records increases.

### 3.6.5 Security

The system checks credentials and user roles. The current credential protection uses XOR-based obfuscation, which is not equivalent to modern password hashing.

## 3.7 Feasibility of the Proposed Solution

### 3.7.1 Technical Feasibility

The system can be implemented using standard C++ facilities and does not require a database server.

### 3.7.2 Economic Feasibility

The project has low implementation cost because it uses local storage and commonly available development tools.

### 3.7.3 Operational Feasibility

The menu-driven interface is simple enough for basic users to operate after a short introduction.

### 3.7.4 Schedule Feasibility

The system can be developed in stages: requirement analysis, design, authentication, record management, attendance implementation, testing, and documentation.

---

# CHAPTER 4: DESIGN SPECIFICATION AND IMPLEMENTATION

## 4.1 System Architecture

The system follows a simple modular architecture consisting of three major layers.

### 4.1.1 User Interface Layer

This layer includes:

- Main menu.
- Login menus.
- Admin panel.
- Sub-Admin panel.
- Student/Teacher panel.

### 4.1.2 Application Logic Layer

This layer performs:

- Authentication.
- User management.
- Student management.
- Teacher management.
- Attendance management.
- Validation.
- Searching.
- Updating.
- Deleting.

### 4.1.3 Data Storage Layer

This layer stores information in binary files.

The architecture can be represented as:

**Figure 4.1: System Architecture**

```
+------------------------------------------------+
|                USER INTERFACE                  |
| Main Menu | Admin | Sub-Admin | Student/Teacher|
+--------------------------+---------------------+
                           |
                           v
+------------------------------------------------+
|              APPLICATION LOGIC                |
| Authentication | Validation | User Management |
| Student | Teacher | Attendance | Search/Update |
+--------------------------+---------------------+
                           |
                           v
+------------------------------------------------+
|                 FILE STORAGE                  |
| credentials.dat | students.dat | teachers.dat|
| staff.dat | attendance.dat                    |
+------------------------------------------------+
```

## 4.2 Context Diagram

The context diagram represents the complete system as one process and shows the interaction between external users and the system.

**Figure 4.2: Context Diagram**

```
                   +----------------+
                   |     Admin      |
                   +-------+--------+
                           |
                           | Manage users,
                           | students, teachers,
                           | attendance
                           v
+----------------+   +---------------------------+   +----------------+
|   Sub-Admin    |-->| Smart Attendance          |<--|    Student     |
+----------------+   | Management System         |   +----------------+
                     +-------------+-------------+
                                   ^
                                   |
                                   |
                            +------+-------+
                            |    Teacher   |
                            +--------------+
```

### External Entities

- **Admin:** manages administrative accounts, records, attendance, and configuration.
- **Sub-Admin:** manages student/teacher records and attendance.
- **Student:** views and marks personal attendance.
- **Teacher:** views and marks personal attendance.

## 4.3 Level 1 Data Flow Diagram

The Level 1 DFD decomposes the system into major processes.

**Figure 4.3: Level 1 Data Flow Diagram**

```
                 +----------------+
                 |      User      |
                 +-------+--------+
                         |
                         v
                +-------------------+
                | 1.0 Authentication|
                +---------+---------+
                          |
                          v
                +-------------------+
                | 2.0 User/Profile  |
                |     Management    |
                +---------+---------+
                          |
             +------------+-------------+
             |                          |
             v                          v
     +---------------+          +----------------+
     | 3.0 Attendance|          | 4.0 Validation |
     |    Management|          |   and Search   |
     +-------+-------+          +-------+--------+
             |                          |
             +------------+-------------+
                          |
                          v
                +-------------------+
                |   Binary Files    |
                | credentials.dat   |
                | students.dat      |
                | teachers.dat      |
                | staff.dat         |
                | attendance.dat    |
                +-------------------+
```

## 4.4 Data Dictionary

The system uses fixed-size structures stored in binary files.

### Table 4.1: Data Dictionary

| Data Entity | Field | Description |
|---|---|---|
| UserRecord | username | User login name |
| UserRecord | password | User password/obfuscated credential field |
| UserRecord | role | User role |
| StudentRecord | username | Student account name |
| StudentRecord | name | Student name |
| StudentRecord | dateOfBirth | Student birth date |
| StudentRecord | rollNumber | Student roll number |
| StudentRecord | semester | Student semester |
| StudentRecord | subject | Student subject/course |
| StudentRecord | program | Academic program |
| StudentRecord | section | Class section |
| TeacherRecord | username | Teacher account name |
| TeacherRecord | teacherId | Unique teacher ID |
| TeacherRecord | name | Teacher name |
| TeacherRecord | dateOfBirth | Teacher birth date |
| TeacherRecord | department | Teacher department |
| TeacherRecord | qualification | Teacher qualification |
| StaffRecord | username | Staff account name |
| StaffRecord | role | Admin/Sub-Admin role |
| StaffRecord | name | Staff name |
| StaffRecord | dateOfBirth | Staff birth date |
| StaffRecord | department | Staff department |
| AttendanceRecord | username | Account associated with attendance |
| AttendanceRecord | role | Student/Teacher role |
| AttendanceRecord | rollNumber | Student roll number where applicable |
| AttendanceRecord | semester | Student semester where applicable |
| AttendanceRecord | subject | Attendance subject |
| AttendanceRecord | date | Attendance date |
| AttendanceRecord | status | Present, Absent, or Late |
| AttendanceRecord | markedBy | User who marked attendance |

### File Dictionary

| File | Purpose |
|---|---|
| `credentials.dat` | Stores login credentials and roles |
| `students.dat` | Stores student records |
| `teachers.dat` | Stores teacher records |
| `staff.dat` | Stores Admin/Sub-Admin staff records |
| `attendance.dat` | Stores attendance records |
| `*_temp.dat` | Temporary files used during updates/deletions |

## 4.5 Working Procedure

The overall working procedure is:

1. Start the application.
2. Display the main menu.
3. Select the required login type.
4. Enter username and password.
5. For Student/Teacher login, select the applicable role.
6. Verify credentials.
7. Open the appropriate role panel.
8. Select the required operation.
9. Validate the input.
10. Read, create, update, or delete the required record.
11. Save changes to the appropriate binary file.
12. Display the result.
13. Continue using the panel or log out.
14. Exit the application.

### Attendance Working Procedure

1. User logs in.
2. User selects **Mark My Attendance**.
3. System identifies the current user and role.
4. System loads the relevant profile.
5. System obtains the current date.
6. System checks whether an attendance record already exists.
7. If a duplicate exists, the system rejects the new entry.
8. If no duplicate exists, a new attendance record is created.
9. The record is written to `attendance.dat`.
10. A success or failure message is displayed.

## 4.6 Flowchart Diagram

**Figure 4.4: Attendance Flowchart**

```
              START
                |
                v
        Display Login Menu
                |
                v
        Enter Login Details
                |
                v
        Verify Credentials
           /          \
         No            Yes
         |              |
         v              v
   Invalid Login    Open User Panel
         |              |
         |              v
         |       Select Attendance
         |              |
         |              v
         |       Load User Profile
         |              |
         |              v
         |       Check Duplicate
         |          /        \
         |        Yes         No
         |         |           |
         |         v           v
         |     Reject       Create Record
         |                     |
         |                     v
         |               Save Attendance
         |                     |
         +----------+----------+
                    |
                    v
                  END
```

## 4.7 Use Case Diagram

**Figure 4.5: Use Case Diagram**

```
                  +--------------------------------------+
                  | Smart Attendance Management System  |
                  |                                      |
 Admin ---------->| Login                                |
   |              | Manage Admin/Sub-Admin Users        |
   |              | Manage Students                     |
   |              | Manage Teachers                     |
   |              | View Attendance                     |
   |              | Mark/Override Attendance            |
   |              | System Configuration                |
   |              |                                      |
 Sub-Admin ------>| Login                                |
   |              | Add/Manage Students and Teachers    |
   |              | View Attendance                     |
   |              | Mark/Override Attendance            |
   |              |                                      |
 Student -------->| Login                                |
   |              | View Personal Details               |
   |              | View Own Attendance                 |
   |              | Mark Own Attendance                 |
   |              |                                      |
 Teacher -------->| Login                                |
                  | View Personal Details               |
                  | View Own Attendance                 |
                  | Mark Own Attendance                 |
                  +--------------------------------------+
```

## 4.8 Class Design and Module Structure

The system uses inheritance to share common functionality.

**Figure 4.6: Class/Inheritance Structure**

```
                    AuthenticationBase
                    /        |         \
                   /         |          \
                  v          v           v
          AdminPanel   SubAdminPanel   StudentTeacherPanel
```

### Table 4.2: Main Classes

| Class | Responsibility |
|---|---|
| AuthenticationBase | Common authentication, validation, record, and attendance operations |
| AdminPanel | Admin login, user management, system configuration, and administrative operations |
| SubAdminPanel | Sub-Admin login and student/teacher/attendance management |
| StudentTeacherPanel | Student/Teacher login and personal attendance operations |

## 4.9 Implementation Details

### 4.9.1 Main Program

The `main.cpp` file creates the three panel objects:

- `AdminPanel`
- `SubAdminPanel`
- `StudentTeacherPanel`

It displays the main menu and directs the user to the selected login process.

### 4.9.2 Authentication Implementation

The `AuthenticationBase` class provides functions for:

- Finding users.
- Verifying credentials.
- Adding users.
- Updating credentials.
- Deleting users.
- Finding student and teacher records.

The implemented default accounts are:

- Admin username: `admin`
- Admin password: `admin123`
- Sub-Admin username: `subadmin`
- Sub-Admin password: `sub123`

These are development defaults and should not be treated as secure production credentials.

### 4.9.3 Student and Teacher Implementation

Student and teacher records are stored separately in binary files. The system checks uniqueness of roll numbers and teacher IDs before creating records.

### 4.9.4 Attendance Implementation

The attendance module supports:

- Present.
- Absent.
- Late.
- Duplicate checking.
- Manual override.
- Attendance history.
- Attendance percentage.

### 4.9.5 File Handling

The project uses C++ binary file streams. New records are appended to files. For updates and deletions, temporary files are used to rewrite records safely.

### 4.9.6 Credential Protection

The current implementation uses a fixed XOR transformation for credential fields. This is only basic obfuscation and is reversible. It should not be considered modern password security.

---

# CHAPTER 5: EXPERIMENT RESULT AND ANALYSIS

## 5.1 Introduction

Testing is performed to determine whether the implemented system behaves according to its requirements and whether invalid inputs are handled correctly.

The experiments focus on authentication, record management, attendance management, validation, duplicate prevention, and percentage calculation.

## 5.2 Experiment Environment

### Table 5.1: Experiment Environment

| Component | Environment |
|---|---|
| Programming Language | C++ |
| Compiler | g++ |
| Development Environment | Visual Studio Code or compatible IDE |
| Operating System | Windows/Linux compatible environment |
| Storage | Local binary files |
| Version Control | Git/GitHub |
| Main Input | Keyboard |
| Interface | Console |

The project can be compiled using:

```bash
g++ src/*.cpp -Iinclude -o project
```

On Windows, the executable can be run using:

```powershell
.\project.exe
```

## 5.3 Testing Scenarios

The following scenarios cover the main functions of the project:

1. Valid Admin login.
2. Invalid Admin login.
3. Valid Sub-Admin login.
4. Valid Student login.
5. Valid Teacher login.
6. Adding a student.
7. Adding a duplicate student username.
8. Adding a duplicate roll number.
9. Searching for a student.
10. Updating a student.
11. Deleting a student.
12. Adding a teacher.
13. Adding a duplicate teacher ID.
14. Updating a teacher.
15. Marking attendance.
16. Attempting duplicate attendance.
17. Manual attendance override.
18. Invalid attendance status.
19. Viewing attendance.
20. Calculating attendance percentage.

## 5.4 Experiment and Result

### Table 5.2: Testing Scenarios and Results

| Test ID | Experiment | Expected Result | Result/Status |
|---|---|---|---|
| TC01 | Enter valid Admin credentials | Admin panel opens | Verify during final run |
| TC02 | Enter wrong password | Login rejected | Verify during final run |
| TC03 | Enter valid Sub-Admin credentials | Sub-Admin panel opens | Verify during final run |
| TC04 | Enter valid Student credentials | Student panel opens | Verify during final run |
| TC05 | Enter valid Teacher credentials | Teacher panel opens | Verify during final run |
| TC06 | Add unique student | Student record created | Verify during final run |
| TC07 | Add existing username | Operation rejected | Verify during final run |
| TC08 | Add existing roll number | Operation rejected | Verify during final run |
| TC09 | Search student | Matching record displayed | Verify during final run |
| TC10 | Update student | Updated record stored | Verify during final run |
| TC11 | Delete student | Student and related data removed | Verify during final run |
| TC12 | Add teacher with unique ID | Teacher created | Verify during final run |
| TC13 | Add duplicate teacher ID | Operation rejected | Verify during final run |
| TC14 | Update teacher | Teacher record updated | Verify during final run |
| TC15 | Mark attendance | Attendance record stored | Verify during final run |
| TC16 | Mark same attendance again | Duplicate prevented | Verify during final run |
| TC17 | Override attendance | Existing status updated | Verify during final run |
| TC18 | Enter invalid status | Input rejected | Verify during final run |
| TC19 | View attendance | Attendance history displayed | Verify during final run |
| TC20 | Calculate percentage | Correct percentage displayed | Verify during final run |

**Important:** The source repository contains the implementation but does not provide an independent laboratory test log. Therefore, the final academic report should replace the “Verify during final run” entries with the actual observed result after executing the final build and should include screenshots of important test cases.

## 5.5 Result Analysis

The implementation provides mechanisms corresponding to the major requirements of the system.

### 5.5.1 Authentication Analysis

The code provides separate authentication functions for Admin, Sub-Admin, and Student/Teacher users. The Student/Teacher login also checks whether the selected role is Student or Teacher.

### 5.5.2 Record Management Analysis

The system provides functions for creating, searching, updating, and deleting records. Temporary files are used for record-rewrite operations.

### 5.5.3 Attendance Analysis

Attendance is associated with a username, role, date, subject, status, and user who marked the attendance. The system checks for an existing record before creating another one.

### 5.5.4 Validation Analysis

The project contains validation functions for dates, status, field sizes, duplicate usernames, roll numbers, teacher IDs, and menu input.

### 5.5.5 Storage Analysis

The binary-file approach is simple and suitable for the academic project. However, sequential searching and fixed-size records make the design less suitable for large-scale institutional use.

### 5.5.6 Security Analysis

The project uses role checking and XOR-based credential obfuscation. Because XOR obfuscation is reversible, the current implementation should be improved with secure password hashing before real-world deployment.

---

# CHAPTER 6: CONCLUSION AND FUTURE WORK

## 6.1 Conclusion

The **Smart Attendance Management System** provides a computerized method for managing user accounts, student records, teacher records, and attendance information.

The project successfully demonstrates important C++ and object-oriented programming concepts including classes, inheritance, encapsulation, constructors, member functions, structures, file handling, validation, and modular programming.

The system provides role-based access for Admin, Sub-Admin, Student, and Teacher users. It supports student and teacher management, attendance marking, attendance viewing, duplicate prevention, attendance percentage calculation, and administrative attendance override.

The project also demonstrates persistent storage using binary files. Although this approach is simple and suitable for an academic project, it has limitations when the number of records becomes large.

Overall, the project provides a practical example of applying second-semester BIT programming concepts to an attendance-management problem.

## 6.2 Limitations

The current system has the following limitations:

1. It uses binary files instead of a relational database.
2. Most searches are sequential.
3. The interface is console-based.
4. The system is mainly intended for local use.
5. It does not provide web or mobile access.
6. It does not support remote multi-user operation.
7. Credential protection uses reversible XOR obfuscation rather than secure password hashing.
8. Advanced reporting and data export are limited.
9. There is no cloud backup.
10. It is not integrated with QR, RFID, or biometric devices.

## 6.3 Future Work

The system can be extended in the following ways:

1. Replace binary files with SQLite, MySQL, PostgreSQL, or another database.
2. Implement secure password hashing.
3. Develop a graphical user interface.
4. Develop a web-based system.
5. Develop a mobile application.
6. Add QR-code attendance.
7. Add RFID-based attendance.
8. Add biometric attendance.
9. Add automated email or SMS notifications.
10. Add PDF and spreadsheet reports.
11. Add graphical attendance dashboards.
12. Add subject-wise and semester-wise reporting.
13. Add audit logs.
14. Add automated backup and restore.
15. Add cloud-based storage.
16. Add concurrent multi-user access.

---

# REFERENCES

1. Purbanchal University, **Bachelor of Information Technology (BIT) Curriculum**, Faculty of Science and Technology.

2. Purbanchal University, **Project-II (BIT156CO)**, Bachelor of Information Technology.

3. Balagurusamy, E., **Object Oriented Programming with C++**, McGraw Hill Education.

4. Schildt, H., **C++: The Complete Reference**, McGraw Hill.

5. Stroustrup, B., **The C++ Programming Language**, Addison-Wesley.

6. C++ Standard Library documentation and learning resources consulted during implementation.

7. Project source code maintained in the GitHub repository **Smart_Attendance_System_II-Semester**.

---

# BIBLIOGRAPHY

Bibliography may include additional books, websites, tutorials, and learning materials consulted during the development of the project.

---

# APPENDIX A: USER MANUAL

## A.1 Starting the Application

Compile the project:

```bash
g++ src/*.cpp -Iinclude -o project
```

Run on Windows:

```powershell
.\project.exe
```

## A.2 Main Menu

The main menu provides:

1. Admin Login
2. Sub-Admin Login
3. Student / Teacher Login
4. System Help
5. Exit

## A.3 Admin Login

Development default:

- Username: `admin`
- Password: `admin123`

## A.4 Sub-Admin Login

Development default:

- Username: `subadmin`
- Password: `sub123`

## A.5 Student/Teacher Login

The user enters:

- Username.
- Password.
- Role: S for Student or T for Teacher.

## A.6 Marking Attendance

1. Log in as Student or Teacher.
2. Select **Mark My Attendance**.
3. The system identifies the current user.
4. The current date is obtained.
5. The system checks for duplicate attendance.
6. If no duplicate exists, attendance is saved.

## A.7 Manual Attendance Override

Admin/Sub-Admin users can:

1. Select attendance override.
2. Enter the target username.
3. Verify the target profile.
4. Select Present, Absent, or Late.
5. Update an existing record or create a new record.

---

# APPENDIX B: PROJECT FILE STRUCTURE

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

---

# APPENDIX C: MAIN ALGORITHMS

## C.1 Login Algorithm

```
START
  |
Read username, password and role
  |
Search credentials
  |
User found?
 /       \
No        Yes
|          |
Invalid    Compare password and role
Login      |
           v
        Match?
       /      \
     No        Yes
     |          |
 Invalid       Set current user
 Login         |
              Open role panel
                   |
                  STOP
```

## C.2 Attendance Algorithm

```
START
  |
Identify user
  |
Load profile
  |
Get date and subject
  |
Check duplicate attendance
  |
Duplicate?
 /       \
Yes       No
|          |
Reject     Create AttendanceRecord
           |
       Write attendance.dat
           |
       Display result
           |
          STOP
```

---

# APPENDIX D: SCREENSHOT CHECKLIST

The following screenshots should be captured from the final running system and inserted into the final Word report:

1. Main application menu.
2. Admin login.
3. Admin panel.
4. User management.
5. Add student.
6. Student details.
7. Student search result.
8. Student update.
9. Teacher management.
10. Add teacher.
11. Teacher details.
12. Student/Teacher login.
13. Student attendance.
14. Attendance marking.
15. Attendance history.
16. Attendance percentage.
17. Manual attendance override.
18. System configuration.
19. Invalid login message.
20. Duplicate attendance message.
21. Invalid input message.
22. Successful logout.
23. Exit screen.

---

# APPENDIX E: PROJECT DEVELOPMENT PHASES

| Phase | Activity |
|---|---|
| Phase 1 | Topic selection |
| Phase 2 | Requirement identification |
| Phase 3 | Existing-system analysis |
| Phase 4 | System design |
| Phase 5 | Class and data-structure design |
| Phase 6 | Authentication implementation |
| Phase 7 | Student and teacher management |
| Phase 8 | Attendance implementation |
| Phase 9 | Validation and error handling |
| Phase 10 | Integration and debugging |
| Phase 11 | Testing |
| Phase 12 | Documentation |

---

# END OF REPORT
