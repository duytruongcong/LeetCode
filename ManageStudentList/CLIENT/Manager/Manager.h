#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <Student.h>
#include <StudentRepository.h>
#include <CSV.h>

class Manager
{
private:

    std::vector<Student> students;

    StudentRepository database;

    CSV CsvHandle;

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

    bool WriteToCsv();

    void ReadFromCsv();
};