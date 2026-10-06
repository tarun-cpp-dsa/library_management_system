# Library Management System

A console-based Library Management System developed using **C++ and MySQL**.
The project manages books, students, and book issue/return records through a simple menu-driven interface.

## Features

* Add books
* View books
* Delete books
* Add students
* View students
* Delete students
* Issue books
* Return books
* View issue records
* Track available book quantity
* Store and manage data using MySQL

## Technologies Used

* **C++17**
* **MySQL 8**
* **MySQL Connector/C++**
* **CMake**
* **Git & GitHub**

## Project Structure

```text
library_management_system/
│
├── main.cpp
├── Database.h
├── Database.cpp
├── book.h
├── book.cpp
├── student.h
├── student.cpp
├── Issue.h
├── Issue.cpp
├── database.sql
├── CMakeLists.txt
├── .gitignore
└── README.md
```

## Database Structure

The project uses three main tables:

```text
students
   │
   │ student_id
   ↓
issues
   ↑
   │ book_id
   │
books
```

### `books`

Stores book information such as:

* Book ID
* Title
* Author
* Category
* Quantity
* Available books

### `students`

Stores:

* Student ID
* Name
* Email
* Phone number

### `issues`

Stores:

* Issue ID
* Student ID
* Book ID
* Issue date
* Return date
* Issue status

## Requirements

Before running the project, install:

1. C++ compiler compatible with the MySQL Connector/C++ package
2. CMake
3. MySQL Server
4. MySQL Connector/C++

## Database Setup

1. Open MySQL.
2. Run the SQL script from:

```text
database.sql
```

This creates the `library` database and the required tables.

## Configuration

Update the MySQL connection details in:

```text
Database.cpp
```

Example:

```cpp
connection = driver->connect(
    "tcp://127.0.0.1:3306",
    "root",
    "YOUR_PASSWORD"
);
```

Do not commit your actual MySQL password to GitHub.

## Build

From the project directory:

```bash
cmake -S . -B build
cmake --build build --config Release
```

## Run

On Windows:

```bash
./build/Release/library_management.exe
```

## Application Flow

```text
Start Program
      ↓
Connect to MySQL
      ↓
Display Menu
      ↓
┌─────────────────────────────┐
│ Book Management             │
│ Student Management          │
│ Issue / Return Management   │
└─────────────────────────────┘
      ↓
Perform Database Operation
      ↓
Display Result
```

## Future Improvements

* Login and authentication system
* Search books and students
* Due-date and fine calculation
* Better input validation
* Transaction-based issue/return operations
* GUI interface
* Improved error handling

## Author

**Tarun**

Mechanical Engineering Student | C++ | DSA | SQL

## License

This project is for educational and learning purposes.
