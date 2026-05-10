#pragma one
#include <vector>
#include <string>
#include "Student.h"

class Database
{

public:
    static void Save(const std::vector<Student> &students, const std::string &filename);
    static void Load(std::vector<Student> &students, const std::string &filename);
};
