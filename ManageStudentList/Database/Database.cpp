#include "Database.h"
#include <iostream>

void Database::CreateTable()
{
    sqlite3 *db;

    int result = sqlite3_open("student.db", &db);

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
    sqlite3 *db;

    if (sqlite3_open("student.db", &db) != SQLITE_OK)
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

static int callback(void *data,
                    int argc,
                    char **argv,
                    char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << azColName[i]
                  << ": "
                  << argv[i]
                  << std::endl;
    }

    std::cout << "--------------\n";

    return 0;
}

void Select()
{
    sqlite3 *db;
    char *messageError;

    int result = sqlite3_open("student.db", &db);

    if (result != SQLITE_OK)
    {

        std::cout << "Cannot open database!\n";
        return;
    }

    const char *sql = "SELECT * FROM STUDENT;";

    sqlite3_exec(db, sql, callback, 0, &messageError);
    sqlite3_close(db);
}
