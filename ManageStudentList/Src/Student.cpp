#include "Student.h"
#include "Manager.h"

Student::Student()
{
    Id = ++Manager::maxId;
}

Student::Student(const std::string &name, int age, int score)
{
    Id = ++Manager::maxId;
    Name = name;
    Age = age;
    Score = score;
}
Student::Student(int id, const std::string &name, int age, int score)
{
    Id = id;
    Name = name;
    Age = age;
    Score = score;
}
