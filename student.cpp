#include "student.h"
#include<string>

Student::Student(Database& database) :db(database){

}

void Student::addstudent()
{
    string name,email,phone;

    cout<<"\n----Add Student----\n";
    cin.ignore();


    cout<<"Enter the name of the student:";
    getline(cin,name);

    cout<<"Enter the email of the student:";
    getline(cin,email);

    cout<<"Enter the phone number";
    getline(cin,phone);

    try
    {
        sql::Connection* connection=db.getConnection();
        sql::PreparedStatement* statement=connection->prepareStatement(
            "INSERT INTO students"
            "(name,email,phone)"
            "VALUES(?,?,?)"
        );
        statement->setString(1,name);
        statement->setString(2,email);
        statement->setString(3,phone);

        statement->executeUpdate();
        cout<<"Student Added Successfully";

        delete statement;
    }
    catch(const sql::SQLException& e)
    {
        cout<<"Error the adding student:"<< e.what() << '\n';
    }
    
}
void Student::viewstudent()
{
    try
    {
        sql::Connection* connection = db.getConnection();

        sql::Statement* statement = connection->createStatement();

        sql::ResultSet* res = statement->executeQuery(
            "SELECT student_id, name, email, phone FROM students"
        );

        cout << "\n----Library Student Catalog----\n";

        while (res->next())
        {
            cout << "ID: " << res->getInt(1);
            cout << " | Name: " << res->getString(2);
            cout << " | Email: " << res->getString(3);
            cout << " | Phone Number: " << res->getString(4);
            cout << endl;
        }

        delete res;
        delete statement;
    }
    catch (const sql::SQLException& e)
    {
        cout << "Error Displaying Student: "<< e.what() << endl;
    }
}
void Student::deletestudent()
{
    int id;
    cout<<"Enter the id of the student to be delete:";
    cin>>id;

    try
    {
        sql::Connection* connection=db.getConnection();
        sql::PreparedStatement* statement=connection->prepareStatement(
            "DELETE FROM students WHERE student_id=?"
        );

        statement->setInt(1,id);
        int rowaffected=statement->executeUpdate();
        if(rowaffected>0)
        {
            cout<<"Student deleted successfully:"<<endl;
        }
        else
        {
            cout<<"Student id not found"<<endl;
        }
        delete statement;
    }
    catch(const sql::SQLException& e)
    {
        cout<<"the id is not found"<< e.what() << '\n';
    }
    
}