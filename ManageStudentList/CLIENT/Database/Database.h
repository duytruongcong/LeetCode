#pragma once
#include <sqlite3.h>
#include <string>
#include <vector>
#include <Student.h>

class Database
{
private:
    sqlite3 *db;

public:
    Database();
    void CreateTable();
    void Insert(const std::string &name, int age, int score);
    void UpdateById(int id, const std::string &name, int age, int score);
    void RemoveById(int id);
    std::vector<Student> LoadData();
};
