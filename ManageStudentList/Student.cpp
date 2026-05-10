#include "Student.h"

int Student::BaseId = 0;

Student::Student()
{
}

Student::Student(const std::string &name, int age, int score)
{
    Id = ++BaseId;
    Name = name;
    Age = age;
    Score = score;
}