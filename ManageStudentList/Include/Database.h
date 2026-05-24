#pragma once
#include <sqlite3.h>
#include <string>
#include <vector>
#include "Student.h"

class Database
{
public:
    static void CreateTable();
    static void Insert(const std::string &name, int age, int score);
    static void UpdateStudent(int id, const std::string &name, int age, int score);
    static void RemoveById(int id);
    static std::vector<Student> LoadData();
};
