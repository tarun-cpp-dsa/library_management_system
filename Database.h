#ifndef DATABASE_H
#define DATABASE_H

#include <mysql/jdbc.h>

class Database {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* connection;

public:
    Database();
    ~Database();

    sql::Connection* getConnection();
};

#endif