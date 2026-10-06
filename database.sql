-- ============================================
-- Library Management System Database
-- C++ + MySQL
-- ============================================

CREATE DATABASE IF NOT EXISTS library;

USE library;


-- ============================================
-- Books Table
-- ============================================

CREATE TABLE IF NOT EXISTS books (
    book_id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(100) NOT NULL,
    author VARCHAR(100) NOT NULL,
    category VARCHAR(50) NOT NULL,
    quantity INT NOT NULL CHECK (quantity >= 0),
    available INT NOT NULL DEFAULT 0 CHECK (available >= 0),
    CONSTRAINT chk_available CHECK (available <= quantity)
);


-- ============================================
-- Students Table
-- ============================================

CREATE TABLE IF NOT EXISTS students (
    student_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    phone VARCHAR(20) NOT NULL UNIQUE
);


-- ============================================
-- Issues Table
-- ============================================

CREATE TABLE IF NOT EXISTS issues (
    issue_id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT NOT NULL,
    book_id INT NOT NULL,
    issues_date DATE NOT NULL,
    return_date DATE,
    statu VARCHAR(20) NOT NULL DEFAULT 'ISSUED',

    CONSTRAINT fk_issue_student
        FOREIGN KEY (student_id)
        REFERENCES students(student_id),

    CONSTRAINT fk_issue_book
        FOREIGN KEY (book_id)
        REFERENCES books(book_id)
);