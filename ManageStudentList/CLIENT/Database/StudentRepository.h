#pragma once
#include <sqlite3.h>
#include <string>
#include <vector>
#include <Student.h>

class StudentRepository
{
private:
    sqlite3 *db;

public:
    StudentRepository();
    void CreateTable();
    void Insert(const std::string &name, int age, int score);
    void UpdateById(int id, const std::string &name, int age, int score);
    void RemoveById(int id);
    std::vector<Student> LoadData();
};
