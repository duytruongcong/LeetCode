#include "Database.h"
#include <fstream>
#include <sstream>

void Database::Save(const std::vector<Student> &students, const std::string &filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        return;
    }

    for (const auto s : students)
    {
        file << s.Id << ","
             << s.Name << ","
             << s.Age << ","
             << s.Score
             << "\n";
    }

    file.close();
}

void Database::Load(std::vector<Student> &students, const std::string &filename)
{
    std::ifstream file(filename);

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

        Student s;
        s.Id = std::stoi(idStr);
        s.Name = name;
        s.Age = std::stoi(ageStr);
        s.Score = std::stoi(scoreStr);

        students.push_back(s);
    }

    file.close();
}
