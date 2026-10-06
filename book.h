#ifndef book_h
#define book_h

#include<iostream>
#include<string>
#include"Database.h"

using namespace std;
class Book
{
private:
    Database& db;
public:
    Book(Database& database);  
    

    // Book(int b_id,string b_name,string a_name,string cat,int quant,int av);
    void addbook();
    
    void viewbook();
    
    void deletebook();
};

#endif