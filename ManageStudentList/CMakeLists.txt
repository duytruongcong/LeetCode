cmake_minimum_required(VERSION 3.10)

project(StudentManagement VERSION 1.0)

add_executable(${PROJECT_NAME} Main.cpp Manager.cpp Student.cpp Database/Database.cpp)

find_package(SQLite3 REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3)