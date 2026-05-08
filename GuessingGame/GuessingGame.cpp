#include <iostream>
#include <cstdlib>
#include <ctime>
#include <tuple>

enum Level
{
    LOW,
    MEDIUM,
    HIGH
};

std::tuple<int, int> CreateValues(int level)
{
    int randomNum;
    int maxValue;
    srand(time(NULL));

    switch (level)
    {

    case LOW:
        randomNum = (rand() % 20) + 1; // from 01 to 20
        maxValue = 20;
        break;
        
    case MEDIUM:
        randomNum = (rand() % 50) + 1; // from 01 to 50
        maxValue = 50;
        break;

    case HIGH:
    default:
        randomNum = (rand() % 100) + 1; // from 01 to 100
        maxValue = 100;
        break;
    }

    return std::make_tuple(randomNum, maxValue);
}

int main()
{
    int randomNum;
    int guessNum;
    int tries;
    int intLevel;
    int maxValue;
    bool isContinue = true;

    std::cout << "********GUESSING NUMBER FUNNY GAME********" << std::endl;

    do
    {
        // choose level
        std::cout << "Which level do you quan to play? \n 0 - LOW \n 1 - MEDIUM \n 2 - HIGH" << std::endl;
        std::cin >> intLevel;

        auto [randomNum, maxValue] = CreateValues(intLevel);

        do
        {
            std::cout << "Please guess the number from 01 to " << maxValue << " : " << std::endl;

            std::cin >> guessNum;

            tries++;

            if (guessNum <= 0 || guessNum > maxValue)
            {
                std::cout << "The number must be from 01 to " << maxValue << ", try again!" << std::endl;
                continue;
            }

            if (guessNum > randomNum)
            {
                std::cout << "Too high!" << std::endl;
            }
            else if (guessNum < randomNum)
            {
                std::cout << "Too low!" << std::endl;
            }
            else
            {
                std::cout << "Correct! Your tries is " << tries << std::endl;

                (tries <= 5) ? std::cout << "You win!!!" : std::cout << "You lose!!!";

                std::cout << std::endl;

                break;
            }

        } while (guessNum != randomNum);

        std::cout << "Do you want to continue? (y/n)" << std::endl;

        char continueGame;

        std::cin >> continueGame;

        if (continueGame == 'y')
            isContinue = true;
        else
            isContinue = false;

    } while (isContinue);

    std::cout << "********END GAME********" << std::endl;

    return 0;
}