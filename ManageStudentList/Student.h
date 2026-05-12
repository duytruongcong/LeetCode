#pragma once
#include <string>

struct Student
{
    int Id;
    std::string Name;
    int Age;
    int Score;

    Student();

    Student(const std::string &name, int age, int score);
};