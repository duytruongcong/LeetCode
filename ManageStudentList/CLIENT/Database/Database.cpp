#include "Database.h"
#include <iostream>
#ifndef DATABASE_FILE_PATH
#define DATABASE_FILE_PATH "Database/student.db"
#endif

Database::Database()
{
    CreateTable();
}

void Database::CreateTable()
{
    int result = sqlite3_open(DATABASE_FILE_PATH, &db);

    if (result != SQLITE_OK)
    {
        std::cout << "Cannot open database!\n";
        return;
    }

    const char *sql =
        "CREATE TABLE IF NOT EXISTS STUDENT("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "NAME TEXT NOT NULL,"
        "AGE INT NOT NULL,"
        "SCORE INT NOT NULL);";

    char *messageError;
    sqlite3_exec(db, sql, NULL, 0, &messageError);
    sqlite3_close(db);
}

void Database::Insert(const std::string &name, int age, int score)
{

    if (sqlite3_open(DATABASE_FILE_PATH, &db) != SQLITE_OK)
    {
        std::cout << "Cannot open database!\n";
        return;
    }

    const char *sql =
        "INSERT INTO STUDENT(NAME, AGE, SCORE) VALUES(?, ?, ?);";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, age);
    sqlite3_bind_int(stmt, 3, score);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        std::cout << "Insert success!\n";
    }
    else
    {
        std::cout << "Insert failed!\n";
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

std::vector<Student> Database::LoadData()
{
    std::vector<Student> students;

    if (sqlite3_open(DATABASE_FILE_PATH, &db) != SQLITE_OK)
    {
        std::cout << "Cannot open database!\n";
        return students;
    }

    const char *sql = "SELECT ID, NAME, AGE, SCORE FROM STUDENT;";
    sqlite3_stmt *stmt;
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (result != SQLITE_OK)
    {
        std::cout << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return students;
    }

    while ((result = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *nameText = sqlite3_column_text(stmt, 1);
        std::string name = nameText ? reinterpret_cast<const char *>(nameText) : "";
        int age = sqlite3_column_int(stmt, 2);
        int score = sqlite3_column_int(stmt, 3);
        students.emplace_back(id, name, age, score);
    }

    if (result != SQLITE_DONE)
    {
        std::cout << "Error loading data: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return students;
}

void Database::UpdateById(int id, const std::string &name, int age, int score)
{

    if (sqlite3_open(DATABASE_FILE_PATH, &db) != SQLITE_OK)
    {
        std::cout << "Cannot open database!\n";
        return;
    }

    const char *sql = "UPDATE STUDENT SET NAME = ?, AGE = ?, SCORE = ?"
                      "WHERE ID = ?;";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, age);
    sqlite3_bind_int(stmt, 3, score);
    sqlite3_bind_int(stmt, 4, id);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        std::cout << "Update success!\n";
    }
    else
    {
        std::cout << "Update failed!\n";
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void Database::RemoveById(int id)
{
    if (sqlite3_open(DATABASE_FILE_PATH, &db) != SQLITE_OK)
    {
        std::cout << "Cannot open database!\n";
        return;
    }

    const char *sql =
        "DELETE FROM STUDENT WHERE ID = ?;";

    sqlite3_stmt *stmt;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        std::cout << "Delete success!\n";
    }
    else
    {
        std::cout << "Delete failed!\n";
    }

    sqlite3_finalize(stmt);

    sqlite3_close(db);
}
