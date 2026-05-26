#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Student.h"
#include <fstream>
#include <sstream>
#include "Database.h"

class Manager
{
private:

    std::vector<Student> students;

    Database database;

public:
    Manager()
    {
    }

    ~Manager()
    {
    }

    void CreateStudentTable();

    void InsertStudent(const std::string &name, int age, int score);

    void RemoveStudentById(int removeId);

    void View() const;

    void UpdateStudentById(int id, const std::string &name, int age, int score);

    void LoadDataFromDatabase();

    //TODO:DUY refactor later
    static void SaveToCsv(const std::string &filename);

    //TODO:DUY refactor later
    static void LoadFromCsv(const std::string &filename);

    //TODO:DUY refactor later
    static void SaveToSqlDatabase();
};