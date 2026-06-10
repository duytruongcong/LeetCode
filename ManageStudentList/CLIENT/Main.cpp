#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <Student.h>
#include <Manager.h>
#include <StudentRepository.h>

const int VIEW = 1;
const int ADD = 2;
const int EDIT = 3;
const int REMOVE = 4;
const int WRITE_TO_CSV = 5;
const int READ_FROM_CSV = 6;

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

    manager.InsertStudent(name, age, score);
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

    manager.UpdateStudentById(id, name, age, score);
}

void RemoveStudent(Manager &manager)
{
    int id;
    std::cout << "\n Which Id do you want to remove: ";
    std::cin >> id;

    manager.RemoveStudentById(id);
}

void WriteToCsv(Manager &manager)
{
    if (manager.WriteToCsv())
    {
        std::cout << "\n Write to CSV successfully! ";
    }
    else
    {
        std::cout << "\n Write to CSV failed! ";
    }
}

void ReadFromCsv(Manager &manager)
{
    manager.ReadFromCsv();
}

int main()
{
    auto repo = std::make_shared<StudentRepository>();

    Manager mainManager(repo);

    bool isContinue = true;

    do
    {
        char confirm;

        std::cout << "***MANAGE STUDENT***" << std::endl;
        std::cout << "Press 1 to VIEW student list" << std::endl;
        std::cout << "Press 2 to ADD student to list" << std::endl;
        std::cout << "Press 3 to EDIT student infomation" << std::endl;
        std::cout << "Press 4 to REMOVE student infomation" << std::endl;
        std::cout << "Press 5 to WRITE TO CSV file" << std::endl;
        std::cout << "Press 6 to READ FROM CSV file" << std::endl;

        int mode;

        std::cin >> mode;

        switch (mode)
        {
        case VIEW:
            mainManager.LoadDataFromDatabase();
            mainManager.View();
            break;

        case ADD:
            AddStudent(mainManager);
            break;

        case EDIT:
            EditStudent(mainManager);
            break;

        case REMOVE:
            RemoveStudent(mainManager);
            break;

        case WRITE_TO_CSV:
            WriteToCsv(mainManager);
            break;

        case READ_FROM_CSV:
            mainManager.ReadFromCsv();
            mainManager.View();
            break;

        default:
            std::cout << "Please enter the number from 1 to 5" << std::endl;
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