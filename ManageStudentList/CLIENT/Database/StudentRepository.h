#pragma once
#include <sqlite3.h>
#include <string>
#include <vector>
#include <Student.h>
#include "IStudentRepository.h"

class StudentRepository : public IStudentRepository
{
private:
    sqlite3 *db;

public:
    StudentRepository() ;
    void CreateTable() override;
    void Insert(const std::string &name, int age, int score) override;
    void UpdateById(int id, const std::string &name, int age, int score) override;
    void RemoveById(int id) override;
    std::vector<Student> LoadData() override;
};
