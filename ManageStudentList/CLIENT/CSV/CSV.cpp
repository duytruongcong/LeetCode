#include "CSV.h"
#ifndef CSV_FILE_PATH
#define CSV_FILE_PATH "CSV/student.csv"
#endif

bool CSV::SaveToCsv( std::vector<Student> students)
{
    std::ofstream file(CSV_FILE_PATH);

    if (!file.is_open())
    {
        return false;
    }

    for (const auto student : students)
    {
        file << student.Id << ","
             << student.Name << ","
             << student.Age << ","
             << student.Gpa
             << "\n";
    }

    file.close();

    return true;
}

void CSV::LoadFromCsv( std::vector<Student> &students)
{
    std::ifstream file(CSV_FILE_PATH);

    if (!file.is_open())
    {
        return;
    }

    students.clear();

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string idStr;
        std::string name;
        std::string ageStr;
        std::string scoreStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, name, ',');
        std::getline(ss, ageStr, ',');
        std::getline(ss, scoreStr, ',');

        Student student;
        student.Id = std::stoi(idStr);
        student.Name = name;
        student.Age = std::stoi(ageStr);
        student.Gpa = std::stoi(scoreStr);

        students.push_back(student);
    }

    file.close();
}
