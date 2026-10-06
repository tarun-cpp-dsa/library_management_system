#include <iostream>
#include "Database.h"
#include "book.h"
#include "student.h"
#include "Issue.h"
using namespace std;

int main()
{
    try
    {
        Database db;
        Book book(db);
        Student student(db);
        Issue issue(db);

        int input;

        do
        {
            cout << "\n-------- Library Management --------\n";
            cout << "1. Add Book\n";
            cout << "2. View Books\n";
            cout << "3. Delete Book\n";
            cout << "4.Add Student\n";
            cout << "5.View Student\n";
            cout << "6.Delete Student\n";
            cout << "7.Issues the book\n";
            cout << "8.Return the book\n";
            cout << "9.View the issue\n";
            cout << "0. Exit\n";
            cout << "Enter the input: ";
            cin >> input;

            switch (input)
            {
            case 1:
                book.addbook();
                break;

            case 2:
                book.viewbook();
                break;

            case 3:
                book.deletebook();
                break;

            case 4:
                student.addstudent();
                break;
            
            case 5:
                student.viewstudent();
                break;

            case 6:
                student.deletestudent();
                break;
            
            case 7:
                issue.issuebook();
                break;
            
            case 8:
                issue.returnbook();
                break;
            
            case 9:
                issue.viewissue();
                break;
            
            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid option!" << endl;
            }

        } while (input != 0);
    }
    catch (sql::SQLException& e)
    {
        cout << "Database Error: " << e.what() << endl;
    }

    return 0;
}