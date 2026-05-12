#include "Manager.h"

std::vector<Student> Manager::students;
int Manager::maxId = 0;

void Manager::Add(const std::string &name, int age, int score)
{
    students.emplace_back(name, age, score);
}

void Manager::View() const
{
    for (const auto &x : students)
    {
        std::cout << "Id: " << x.Id << "| Name: " << x.Name << "| Age: " << x.Age << "| Score: " << x.Score << std::endl;
    }
}

void Manager::RemoveById(int removeId)
{
    students.erase(std::remove_if(students.begin(), students.end(), [removeId](const Student &s)
                                  { return s.Id == removeId; }),
                   students.end());
}

void Manager::EditById(int id, const std::string &name, int age, int score)
{
    for (auto &x : students)
    {
        if (x.Id == id)
        {
            x.Name = name;
            x.Age = age;
            x.Score = score;
        }
    }
}

void Manager::Save(const std::string &filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        return;
    }

    for (const auto student : Manager::students)
    {
        file << student.Id << ","
             << student.Name << ","
             << student.Age << ","
             << student.Score
             << "\n";
    }

    file.close();
}

void Manager::Load(const std::string &filename)
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

        Student student;
        student.Id = std::stoi(idStr);
        student.Name = name;
        student.Age = std::stoi(ageStr);
        student.Score = std::stoi(scoreStr);

        students.push_back(student);
    }

    for (auto x : students)
    {
        if (Manager::maxId < x.Id)
            Manager::maxId = x.Id;
    }

    file.close();
}