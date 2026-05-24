#pragma one
#include <vector>
#include <algorithm>
#include <iostream>
#include "Student.h"
#include <fstream>
#include <sstream>
#include <Database.h>

class Manager
{
public:

    static std::vector<Student> students;

    static int maxId;

    static Database database;
    
    Manager()
    {
    }

    ~Manager()
    {
    }

    void Add(const std::string &name, int age, int score);

    void View() const;

    void RemoveById(int removeId);

    void EditById(int id, const std::string &name, int age, int score);

    static void SaveToCsv(const std::string &filename);

    static void LoadFromCsv(const std::string &filename);

    static void SaveToSqlDatabase();
};