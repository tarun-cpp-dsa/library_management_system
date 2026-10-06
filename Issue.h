#ifndef Issue_h
#define Issue_h

#include<iostream>
#include<string>
#include "Database.h"
#include "book.h"
#include "student.h"

using namespace std;

class Issue{
private:
    Database& db;
public:
    Issue(Database& database);
    void issuebook();
    void returnbook();
    void viewissue();
};
#endif
