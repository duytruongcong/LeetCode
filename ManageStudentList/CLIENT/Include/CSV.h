#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Student.h"

class CSV
{
public:
    bool SaveToCsv(std::vector<Student> students);
    void LoadFromCsv(std::vector<Student> &students);
};
