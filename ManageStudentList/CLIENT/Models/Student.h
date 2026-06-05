#pragma once
#include <string>

struct Student
{
    int Id;
    std::string Name;
    int Age;
    int Gpa;

    Student();

    Student(const std::string &name, int age, int score);

    Student(int id, const std::string &name, int age, int score);

};