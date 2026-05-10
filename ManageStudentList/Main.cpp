#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student
{
    static int BaseId;
    int Id;
    std::string Name;
    int Age;
    int Score;

    Student(const std::string &name, int age, int score)
    {
        Id = ++BaseId;
        Name = name;
        Age = age;
        Score = score;
    }
};

int Student::BaseId = 0;

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

int main()
{
    Manager Manager;
    Manager.Add( "Duy", 36, 8);
    Manager.Add( "Trang", 30, 9);
    Manager.Add( "Tam", 20, 7);
    Manager.Add( "Minh", 40, 5);
    Manager.Add( "Lan", 40, 2);
    Manager.Add( "Phuong", 26, 7);
    Manager.View();

    Manager.EditById( 4, "Minh heo", 40, 5);

    std::cout << "---------------" << std::endl;
    Manager.View();

    return 0;
}