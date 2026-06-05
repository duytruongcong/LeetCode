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

bool Manager::WriteToCsv()
{
    LoadDataFromDatabase();
    return CsvHandle.SaveToCsv(students);
}

void Manager::ReadFromCsv()
{
    students.clear();
    CsvHandle.LoadFromCsv(students);
}

// TODO:DUY don't UI for manager
void Manager::View() const
{
    for (const auto &x : students)
    {
        std::cout << "Id: " << x.Id << "| Name: " << x.Name << "| Age: " << x.Age << "| Score: " << x.Gpa << std::endl;
    }
}
