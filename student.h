#ifndef student_h
#define student_h

#include<iostream>
#include<string>
#include "Database.h"
using namespace std;
class Student{
private:
    Database& db;
public:
    Student(Database& database);

    void addstudent();
    void viewstudent();
    void deletestudent();
};
#endif