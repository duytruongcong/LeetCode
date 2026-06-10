#pragma once
#include <string>
#include <vector>
#include "Student.h"

class IStudentRepository
{
public:
    virtual ~IStudentRepository() = default;
    virtual void CreateTable() = 0;
    virtual void Insert(const std::string &name, int age, int score) = 0;
    virtual void UpdateById(int id, const std::string &name, int age, int score) = 0;
    virtual void RemoveById(int id) = 0;
    virtual std::vector<Student> LoadData() = 0;
};