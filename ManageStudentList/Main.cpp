#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"
#include "Database.h"

class Manager
{
private:
    std::vector<Student> students;

public:
    Manager()
    {
    }

    ~Manager()
    {
    }

    void Add(const std::string &name, int age, int score)
    {
        students.emplace_back(name, age, score);
    }

    void View() const
    {
        for (const auto &x : students)
        {
            std::cout << "Id: " << x.Id << "| Name: " << x.Name << "| Age: " << x.Age << "| Score: " << x.Score << std::endl;
        }
    }

    void RemoveById(int removeId)
    {
        students.erase(std::remove_if(students.begin(), students.end(), [removeId](const Student &s)
                                      { return s.Id == removeId; }),
                       students.end());
    }

    void EditById(int id, const std::string &name, int age, int score)
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
};

void View(const std::vector<Student> &array)
{
    for (const auto &x : array)
    {
        std::cout
            << x.Id << " | "
            << x.Name << " | "
            << x.Age << " | "
            << x.Score
            << '\n';
    }
}

int main()
{
    // Manager Manager;
    // Manager.Add( "Duy", 36, 8);
    // Manager.Add( "Trang", 30, 9);
    // Manager.Add( "Tam", 20, 7);
    // Manager.Add( "Minh", 40, 5);
    // Manager.Add( "Lan", 40, 2);
    // Manager.Add( "Phuong", 26, 7);
    // Manager.View();

    // Manager.EditById( 4, "Minh heo", 40, 5);

    // std::cout << "---------------" << std::endl;
    // Manager.View();

    std::vector<Student> students;

    Database::Load(students, "students.csv");

    students.emplace_back("Duy", 36, 8);
    students.emplace_back("Trang", 30, 9);

    Database::Save(students, "students.csv");

    View(students);

    return 0;
}