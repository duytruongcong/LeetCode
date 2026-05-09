#include <iostream>
#include <string>
#include <vector>

struct Student
{
    int Id;
    std::string Name;
    int Age;
    int Score;
};

void Add(std::vector<Student> &array, int id, const std::string &name, int age, int score)
{
    array.emplace_back(Student{id, name, age, score});
}

void View(const std::vector<Student> &array)
{
    for (const auto &x : array)
    {
        std::cout << "Id: " << x.Id << "| Name: " << x.Name << "| Age: " << x.Age << "| Score: " << x.Score << std::endl;
    }
}

void RemoveById(std::vector<Student> &array, int removeId)
{
    for (auto iter = array.begin(); iter != array.end();)
    {
        if (iter->Id == removeId)
            iter = array.erase(iter);
        else
            ++iter;
    }
}

void EditById(std::vector<Student> &array, int id, const std::string &name, int age, int score)
{
    for (auto &x : array)
    {
        if (x.Id == id)
        {
            x.Name = name;
            x.Age = age;
            x.Score = score;
        }
    }
}

int main()
{
    std::vector<Student> array;

    Add(array, 1, "Duy", 36, 8);
    Add(array, 2, "Trang", 30, 9);
    Add(array, 3, "Tam", 20, 7);
    Add(array, 4, "Minh", 40, 5);
    Add(array, 4, "Minh", 40, 5);
    Add(array, 4, "Minh", 40, 5);
    Add(array, 5, "Lan", 40, 2);
    Add(array, 6, "Phuong", 26, 7);

    View(array);
    // RemoveById(array, 4);

    EditById(array, 4, "Minh heo", 40, 5);

    std::cout << "---------------" << std::endl;
    View(array);

    return 0;
}