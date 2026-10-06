#include "Issue.h"

#include<string>

Issue::Issue(Database& database) :db(database){}
void Issue::issuebook()
{
    int studentid;
    int bookid;

    cout<<"\n-----Issues Catalog---\n";

    cout<<"Enter the student id";
    cin>>studentid;

    cout<<"Enter the book id";
    cin>>bookid;

    try
    {
        sql::Connection* connection=db.getConnection();
        sql::PreparedStatement* checkstatement=connection->prepareStatement(
            "SELECT available FROM books WHERE book_id=?"
        );
        checkstatement->setInt(1,bookid);
        sql::ResultSet* res=checkstatement->executeQuery();

        if(!res->next())
        {
            cout<<"Book Id Not found"<<endl;
            delete checkstatement;
            delete res;
            return;
        }
        int available=res->getInt(1);

        if(available>0)
        {
            cout<<"Book is not available"<<endl;
            return;
        }
        sql::PreparedStatement* statement=connection->prepareStatement(
            "INSERT INTO issues"
            "(student_id,book_id,issues_date,statu)"
            "VALUES(?,?,CURDATE(),'ISSUED')"
        );
        statement->setInt(1,studentid);
        statement->setInt(2,bookid);

        statement->executeUpdate();

        delete statement;

        sql::PreparedStatement* updatestatement=connection->prepareStatement(
            "UPDATE books"
            "SET available =available-1"
            "WHERE book_id=?"
        );
        updatestatement->executeUpdate();
        delete updatestatement;
        cout<<"Book issued successfully"<<endl;
    }
    catch(const sql::SQLException& e)
    {
        cout<<"the bookid and the student id not match"<< e.what() << '\n';
    }
    
}
void Issue::returnbook()
{
    int studentid;
    int bookid;

    cout << "Enter the student id:";
    cin >> studentid;

    cout << "Enter the book id:";
    cin >> bookid;

    try
    {
        sql::Connection* connection = db.getConnection();
        sql::PreparedStatement* statement = connection->prepareStatement(
            "SELECT issue_id FROM issues "
            "WHERE student_id=? "
            "AND book_id=? "
            "AND statu='ISSUED'"
        );

        statement->setInt(1, studentid);
        statement->setInt(2, bookid);

        sql::ResultSet* res = statement->executeQuery();
        if (!res->next())
        {
            cout << "No active issued have found:" << endl;
            delete res;
            delete statement;
            return;
        }

        int issueid = res->getInt(1);
        delete res;
        delete statement;

        sql::PreparedStatement* updateStatement = connection->prepareStatement(
            "UPDATE books "
            "SET available = available + 1 "
            "WHERE book_id = ?"
        );

        updateStatement->setInt(1, bookid);
        updateStatement->executeUpdate();
        delete updateStatement;

        cout << "Book returned successfully!" << endl;
    }
    catch (const sql::SQLException& e)
    {
        cout << "Failed to return book: " << e.what() << '\n';
    }
}
void Issue::viewissue()
{
    try
    {
         sql::Connection* connection = db.getConnection();

        sql::Statement* statement =
            connection->createStatement();

        sql::ResultSet* result =
            statement->executeQuery(
                "SELECT issue_id, student_id, book_id, "
                "issues_date, return_date, statu "
                "FROM issues"
            );

        cout << "\n-------- Issue Records --------\n";

        while (result->next())
        {
            cout << "Issue ID: " << result->getInt(1)
                 << " | Student ID: " << result->getInt(2)
                 << " | Book ID: " << result->getInt(3)
                 << " | Issue Date: " << result->getString(4)
                 << " | Return Date: " << result->getString(5)
                 << " | Status: " << result->getString(6)
                 << endl;
        }

        delete result;
        delete statement;
    }
    catch(const sql::SQLException& e)
    {
        cout<<"Error Displaying Issue:"<< e.what() << '\n';
    }
    
}