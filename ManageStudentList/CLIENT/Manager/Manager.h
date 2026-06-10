#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <Student.h>
#include <IStudentRepository.h>
#include <CSV.h>
#include <memory>

class Manager
{
private:
    std::vector<Student> students;

    std::shared_ptr<IStudentRepository> prtStudentRespository;

    CSV CsvHandle;

public:
    Manager(std::shared_ptr<IStudentRepository> ptrDatabase) : prtStudentRespository(ptrDatabase)
    {
    }

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