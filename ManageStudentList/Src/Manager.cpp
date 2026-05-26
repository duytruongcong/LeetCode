#include "Manager.h"

void Manager::InsertStudent(const std::string &name, int age, int score)
{
    database.Insert(name, age, score);
}

void Manager::RemoveStudentById(int removeId)
{
    database.RemoveById(removeId);
}

void Manager::LoadDataFromDatabase()
{
    students = database.LoadData();
}

void Manager::UpdateStudentById(int id, const std::string &name, int age, int score)
{
    database.UpdateById(id, name, age, score);
}

void Manager::CreateStudentTable()
{
    database.CreateTable();
}

// TODO:DUY don't UI for manager
void Manager::View() const
{
    for (const auto &x : students)
    {
        std::cout << "Id: " << x.Id << "| Name: " << x.Name << "| Age: " << x.Age << "| Score: " << x.Score << std::endl;
    }
}

void Manager::SaveToCsv(const std::string &filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        return;
    }
    //TODO: 
    // for (const auto student : students)
    // {
    //     file << student.Id << ","
    //          << student.Name << ","
    //          << student.Age << ","
    //          << student.Score
    //          << "\n";
    // }

    file.close();
}

void Manager::LoadFromCsv(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        return;
    }
    //TODO: DUY
    // students.clear();

    // std::string line;

    // while (std::getline(file, line))
    // {
    //     std::stringstream ss(line);

    //     std::string idStr;
    //     std::string name;
    //     std::string ageStr;
    //     std::string scoreStr;

    //     std::getline(ss, idStr, ',');
    //     std::getline(ss, name, ',');
    //     std::getline(ss, ageStr, ',');
    //     std::getline(ss, scoreStr, ',');

    //     Student student;
    //     student.Id = std::stoi(idStr);
    //     student.Name = name;
    //     student.Age = std::stoi(ageStr);
    //     student.Score = std::stoi(scoreStr);

    //     students.push_back(student);
    // }

    file.close();
}
