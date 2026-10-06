cmake_minimum_required(VERSION 3.20)

project(library_management)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(mysql-concpp_DIR "${CMAKE_SOURCE_DIR}/connector/mysql-connector-c++-26.7.0-winx64")
find_package(mysql-concpp REQUIRED)

add_executable(library_management 
        main.cpp 
        book.cpp 
        Database.cpp
        Issue.cpp 
        student.cpp 
    )


target_link_libraries(library_management
    mysql::concpp-jdbc
)