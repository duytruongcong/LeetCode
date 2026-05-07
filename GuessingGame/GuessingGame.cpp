#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    int randomNum;
    int guessNum;
    int tries;
    bool isContinue = true;

    std::cout << "********GUESSING NUMBER FUNNY GAME********" << std::endl;

    do
    {
        srand(time(NULL));
        randomNum = (rand() % 100) + 1;

        do
        {
            std::cout << "Please guess the number from 01 to 100 : " << std::endl;

            std::cin >> guessNum;

            tries++;

            if (guessNum <= 0 || guessNum > 100)
            {
                std::cout << "The number must be from 01 to 100, try again!" << std::endl;
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