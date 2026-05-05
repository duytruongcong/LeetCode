#include <iostream>

int main()
{
    double numOne, numTwo;
    char oper = '\0';
    char question = '\0';

    std::cout << "***Caculator***" << std::endl;

    do
    {
        std::cout << "Please input:" << std::endl;

        std::cin >> numOne >> oper >> numTwo;

        switch (oper)
        {
        case '+':
            std::cout << " = " << numOne + numTwo;
            break;

        case '-':
            std::cout << " = " << numOne - numTwo;
            break;

        case '*':
            std::cout << " = " << numOne * numTwo;
            break;

        case '/':
            std::cout << " = " << numOne / numTwo;
            break;

        case '%':
        {
            int iNumOne = (int)numOne;
            int iNumTwo = (int)numTwo;

            if (iNumTwo != 0)
            {
                std::cout << " = " << iNumOne % iNumTwo;
            }
            else
            {
                std::cout << "Number two must be different 0!";
            }

            break;
        }

        default:

            std::cout << "Operator is not valid!";

            break;
        }

        std::cout << "\nDo you want continue?? y/n" << std::endl;

        std::cin >> question;

    } while (question != 'n');

    return 0;
}