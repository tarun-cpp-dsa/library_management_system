#include "book.h"

Book::Book(Database& database) : db(database)
{
    // bookid=0, bookname="", author="", category="", quantity=0, available=0;
}
void Book:: addbook()
{
    int quantity;
    string title, author, category;

    cout << "Enter book title: ";
    cin >> title;

    cout << "Enter author name: ";
    cin >> author;

    cout << "Enter category: ";
    cin >> category;

    cout << "Enter quantity: ";
    cin >> quantity;

    sql::Connection* connection = db.getConnection();

    sql::PreparedStatement* statement =
        connection->prepareStatement(
            "INSERT INTO books "
            "(title, author, category, quantity, available) "
            "VALUES (?, ?, ?, ?, ?)"
        );

    statement->setString(1, title);
    statement->setString(2, author);
    statement->setString(3, category);
    statement->setInt(4, quantity);
    statement->setInt(5, quantity);

    statement->executeUpdate();

    delete statement;

    cout << "Book added successfully!" << endl;

}
void Book::viewbook()
{
       try{
        sql::Connection* connection=db.getConnection();
        sql::Statement* statement=connection->createStatement();

        sql::ResultSet* res=statement->executeQuery("Select * From books");

        cout<<"\n---Library Book Catalog---";
        while (res->next())
        {
            cout<<"ID:"<<res->getInt("book_id");
            cout<<" | Title:"<<res->getString("title");
            cout<<" | Author:"<<res->getString("author");
            cout<<" | Category:"<<res->getString("category");
            cout<<" | Quantity:"<<res->getInt("quantity");
            cout<<" | Availability:"<<res->getInt("available");
        }
        delete res;
        delete statement;
       }
       catch(sql::SQLException &e){
        cout<<"Error Displaying books:"<<e.what()<<endl;
       }
}
void Book::deletebook()
{
    int targetid;
    cout << "Enter the id to be deleted:";
    cin >> targetid;

    try {
        sql::Connection* connection = db.getConnection();
        sql::PreparedStatement* statement = connection->prepareStatement(
            "DELETE FROM books WHERE id=?"
        );

        statement->setInt(1, targetid);
        int rowsaffect = statement->executeUpdate();

        if (rowsaffect > 0)
        {
            cout << "Book with ID " << targetid << " deleted successfully." << endl;
        }
        else
        {
            cout << "The ID " << targetid << " was not found." << endl;
        }

        delete statement;
    }
    catch (sql::SQLException& e)
    {
        cout << "Error deleting book: " << e.what() << endl;
    }
}



