#include "Database.h"

Database::Database() {
    driver = sql::mysql::get_mysql_driver_instance();

    connection = driver->connect(
        "tcp://127.0.0.1:3306",
        "root",
        "Tarun@1234"
    );

    connection->setSchema("library");
}

Database::~Database() {
    delete connection;
}

sql::Connection* Database::getConnection() {
    return connection;
}