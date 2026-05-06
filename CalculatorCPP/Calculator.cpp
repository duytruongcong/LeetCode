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
            if (numTwo != 0)
                std::cout << " = " << numOne / numTwo;
            else
                std::cout << "Number two must be different 0!";
            break;

        case '%':
        {
            bool isNumOneInt = (int)numOne == numOne;
            bool isNumTwoInt = (int)numTwo == numTwo;

            if (isNumOneInt && isNumTwoInt && numTwo != 0)
            {
                std::cout << " = " << (int)numOne % (int)numTwo;
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