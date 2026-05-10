#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Manager.h"


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

    Manager.Save("students.csv");
    //Manager.EditById( 4, "Minh heo", 40, 5);

    //std::cout << "---------------" << std::endl;
    //Manager.View();


    return 0;
}