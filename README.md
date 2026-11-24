# Smart Attendance Management System

A console-based **Smart Attendance Management System** developed as a Second Semester project for the **Bachelor of Information Technology (BIT), Purbanchal University, Nepal**.

The system is designed to manage student, teacher, staff, and attendance information through role-based access. It uses C++ and local file storage, so records can be maintained between program runs without requiring an external database server.

## Table of Contents

- [Project Overview](#project-overview)
- [Objectives](#objectives)
- [User Roles](#user-roles)
- [Main Features](#main-features)
- [Technology Used](#technology-used)
- [Data Storage](#data-storage)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [How to Use](#how-to-use)
- [Important Notes](#important-notes)
- [Limitations and Future Improvements](#limitations-and-future-improvements)
- [Academic Information](#academic-information)

## Project Overview

The Smart Attendance Management System provides a simple way to record and manage attendance in an educational institution. It separates access according to user roles so that administrators, sub-administrators, teachers, and students can access the functions intended for them.

The application runs in a terminal/command-line environment. It stores application records in local data files and uses a menu-driven interface for navigation.

## Objectives

- Reduce manual work involved in maintaining attendance records.
- Organize student, teacher, and staff information.
- Provide role-based access to system functions.
- Maintain attendance records using local file handling.
- Help users view and manage attendance information efficiently.
- Apply C++ object-oriented programming concepts in a practical project.

## User Roles

| Role | Main responsibility |
|---|---|
| **Administrator** | Manages the system and its records, including user accounts and attendance administration. |
| **Sub-Administrator** | Performs delegated administrative tasks and can assist with attendance management. |
| **Teacher** | Uses the system to manage and record class attendance. |
| **Student** | Logs in to access student-related attendance information. |

The main menu provides separate login options for Administrator, Sub-Administrator, and the combined Student/Teacher login panel.

## Main Features

- **Role-based login:** Separate entry points for Administrator, Sub-Administrator, and Student/Teacher.
- **User and record management:** Supports management of the records required by the attendance system.
- **Attendance management:** Supports attendance recording and administrative attendance correction.
- **Local data persistence:** Stores information in files so records can be reused when the application is restarted.
- **Input validation:** Uses menu-choice validation to handle invalid menu input.
- **System help:** Provides basic instructions about account access and system usage.
- **Duplicate prevention:** Avoids duplicate records where duplicate checks are implemented.
- **Credential handling:** Includes credential transformation logic; this should not be treated as a replacement for modern password hashing.

## Technology Used

| Technology | Purpose |
|---|---|
| **C++** | Main programming language |
| **Object-Oriented Programming (OOP)** | Organizing system components and responsibilities |
| **File Handling** | Reading and writing persistent records |
| **Standard C++ Library** | Input/output and general program operations |
| **Git and GitHub** | Version control and project hosting |

## Data Storage

The application uses local data files for persistent storage. The project uses the following data files:

| File | Purpose |
|---|---|
| `credentials.dat` | Stores login credential records. |
| `students.dat` | Stores student information. |
| `teachers.dat` | Stores teacher information. |
| `staff.dat` | Stores staff information. |
| `attendance.dat` | Stores attendance records. |

**Important:** Keep the data files in the locations expected by the program. Do not manually edit or delete them while the application is running. Use test data when experimenting.

## Project Structure

The repository is organized into three main parts: **source files**, **header files**, and **local data files**. The current structure on the `main` branch is:

```text
Smart_Attendance_System_II-Semester/
│
├── include/                         # Header files
│   ├── AuthenticationBase.h         # Authentication base class declarations
│   ├── Common.h                     # Shared functions and common declarations
│   └── Panels.h                     # Admin, Sub-Admin, and Student/Teacher panel declarations
│
├── src/                             # C++ implementation files
│   ├── main.cpp                     # Program entry point and main menu
│   ├── AuthenticationBase.cpp       # Authentication implementation
│   ├── Common.cpp                   # Common utility function implementations
│   └── Panels.cpp                   # User panel and menu implementations
│
├── attendance.dat                   # Stored attendance records
├── credentials.dat                  # Stored login credential records
├── students.dat                      # Stored student records
├── teachers.dat                      # Stored teacher records
├── staff.dat                         # Stored staff records
│
├── project.exe                       # Windows executable (precompiled program)
├── .gitignore                        # Files and folders ignored by Git
└── README.md                         # Project documentation
```

### Directory and file descriptions

| Path | Description |
|---|---|
| `include/` | Contains header files (`.h`) that declare classes, functions, and shared interfaces. |
| `src/` | Contains C++ source files (`.cpp`) that implement the application logic. |
| `src/main.cpp` | Starts the application and displays the main login menu. |
| `src/AuthenticationBase.cpp` | Implements the authentication-related functionality. |
| `src/Common.cpp` | Implements common utility functions used by the application. |
| `src/Panels.cpp` | Implements the different user panels and their menu operations. |
| `*.dat` | Local files used to persist credentials, user information, and attendance records. |
| `project.exe` | A precompiled Windows executable included in the repository. |
| `.gitignore` | Defines generated and temporary files that Git should ignore. |

**Note:** The `.dat` files are currently located in the repository root, not inside a separate `data/` directory. Run the application from the repository root so that relative file paths resolve correctly. The structure above reflects the files currently present in the repository; update it whenever the project layout changes.

## Getting Started

### Prerequisites

- A C++ compiler that supports the C++ standard used by the source code (for example, GCC/MinGW-w64).
- A terminal or command prompt.
- Git (optional, for cloning the repository).

Check that the compiler is installed:

```bash
g++ --version
```

### 1. Clone the repository

```bash
git clone https://github.com/2narl/Smart_Attendance_System_II-Semester.git
cd Smart_Attendance_System_II-Semester
```

### 2. Compile the project

Compile the program with **all required implementation (.cpp) files** and make sure the compiler can locate the project header files.

For example, if all implementation files are under `src/`:

```bash
g++ -std=c++17 -Wall -Wextra -Isrc src/*.cpp -o attendance
```

Adjust the command if implementation files are stored in other folders. Do not compile header files separately.

### 3. Run the application

On Windows:

```powershell
.\attendance.exe
```

On Linux/macOS:

```bash
./attendance
```

Run the program from the project directory if the application uses relative paths to access its data files.

## How to Use

1. Start the compiled application.
2. Select a login option from the main menu:
   - Administrator Login
   - Sub-Administrator Login
   - Student / Teacher Login
3. Enter the credentials provided by the system administrator.
4. After successful login, use the available panel options.
5. Follow the on-screen instructions to manage records or attendance.
6. Log out or exit the application when finished.

### Account and access notes

- Self-registration is disabled in the current main-menu help text.
- New students and teachers must obtain their login credentials from an administrator.
- Administrator and Sub-Administrator accounts can manually override attendance, as indicated by the current system help menu.
- Do not publish real usernames, passwords, or private student information in this repository.

## Important Notes

- This is an academic project and is intended for learning and demonstration.
- The system uses local files; back up the data files regularly.
- Do not commit real personal information, login credentials, or production attendance records to GitHub.
- Credential transformation is not equivalent to secure password hashing. A production system should use a vetted password-hashing algorithm and appropriate access controls.
- The compile command above is a general example. Update it to match the actual locations of all project source files.

## Limitations and Future Improvements

Possible improvements for future versions include:

- Use a database such as SQLite instead of plain local data files.
- Store passwords using a modern password-hashing algorithm.
- Add stronger input validation and clearer error messages.
- Add attendance summaries, date-wise reports, and percentage calculations.
- Add export options for attendance reports (CSV or PDF).
- Add automated backups and recovery for stored records.
- Improve the interface and add unit tests for important operations.

## Academic Information

| Detail | Information |
|---|---|
| University | Purbanchal University, Nepal |
| Program | Bachelor of Information Technology (BIT) |
| Semester | Second Semester |
| Project | Smart Attendance Management System |
| Language | C++ |

---

## Contributors

- **Narayan Aryal** — [GitHub Profile](https://github.com/2narl)
- **Prabesh Karki** — [GitHub Profile](https://github.com/prabeshkarki0202-lab)
