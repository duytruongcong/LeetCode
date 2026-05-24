#pragma one
#include <sqlite3.h>
#include <string>

class Database
{
private:
    static sqlite3 *db;

public:
    static void CreateTable();
    static void Insert(const std::string &name, int age, int score);
};
