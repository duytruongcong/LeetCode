#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include "Include/Student.h"
#include "Include/Manager.h"
#include "Include/Database.h"

const int VIEW = 1;
const int ADD = 2;
const int EDIT = 3;
const int REMOVE = 4;

void AddStudent(Manager &manager)
{
    std::string name;
    int age;
    int score;
    std::cout << "\n Name : ";
    std::cin >> name;
    std::cout << "\n Age: ";
    std::cin >> age;
    std::cout << "\n Score: ";
    std::cin >> score;

    manager.database.Insert(name, age, score);
}

void EditStudent(Manager &manager)
{
    int id;
    std::cout << "\n Which Id do you want to edit: ";
    std::cin >> id;

    std::string name;
    int age;
    int score;
    std::cout << "\n Name : ";
    std::cin >> name;
    std::cout << "\n Age: ";
    std::cin >> age;
    std::cout << "\n Score: ";
    std::cin >> score;

    manager.database.UpdateStudent(id, name, age, score);
}

void RemoveStudent(Manager &manager)
{
    int id;
    std::cout << "\n Which Id do you want to remove: ";
    std::cin >> id;

    manager.database.RemoveById(id);
}

int main()
{
    Manager Manager;
    bool isContinue = true;

    //TODO: DUY FIX LATER
    Manager.database.CreateTable();

    do
    {
        char confirm;

        std::cout << "***MANAGE STUDENT***" << std::endl;
        std::cout << "Press 1 to VIEW student list" << std::endl;
        std::cout << "Press 2 to ADD student to list" << std::endl;
        std::cout << "Press 3 to EDIT student infomation" << std::endl;
        std::cout << "Press 4 to REMOVE student infomation" << std::endl;

        int mode;

        std::cin >> mode;

        switch (mode)
        {
        case VIEW:
            Manager.LoadFromSqlDatabase();
            Manager.View();
            break;

        case ADD:
            AddStudent(Manager);
            break;

        case EDIT:
            EditStudent(Manager);
            break;

        case REMOVE:
            RemoveStudent(Manager);
            break;

        default:
            std::cout << "Please enter the number from 1 to 4" << std::endl;
            break;
        }

        std::cout << "\n Do you want to continue? Y/N" << std::endl;
        std::cin >> confirm;

        if (confirm == 'y')
        {
            isContinue = true;
        }
        else
        {
            isContinue = false;
        }

    } while (isContinue);

    std::cout << "***BYE BYE***" << std::endl;

    return 0;
}