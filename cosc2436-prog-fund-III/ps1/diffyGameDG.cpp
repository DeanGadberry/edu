// diffyGameDG.cpp
// Dean Gadberry
// COSC 2436 0400
// ps1p2
// References:

#include <iostream>
#include <cstdlib>

void promptUser();
int absoluteDifference(int, int);
void runAgain();
void checkNumberOfZeros();

int zeros, numbers[4], steps, placeholder;

int main()
{
    promptUser();
    std::cout
        <<std::endl
        <<"The values for each of the corners:"
        <<std::endl;
    do {
        steps++;
        placeholder = absoluteDifference(numbers[0], numbers[3]);
        for (int i = 0; i < 3; i++)
        {
           numbers[i] = absoluteDifference(numbers[i], numbers[i+1]);
        }
        numbers[3] = placeholder;
        for (int i = 0; i < 4; i++)
        {
            std::cout
                <<numbers[i]
                <<" ";
        }
        std::cout
            <<std::endl;
        checkNumberOfZeros();
    } while (zeros != 4);
    std::cout
        <<std::endl
        <<"Number of steps: "
        <<steps
        <<std::endl;
    runAgain();
    return 0;
}

void promptUser()
{
    steps = 0;
    std::cout
        <<std::endl
        <<"Enter 4 integer numbers cockwise: ";
    for (int i = 0; i < 4; i++)
    {
        std::cin
            >>numbers[i];
    }
}

int absoluteDifference(int number_one, int number_two)
{
    int difference = number_one - number_two;
    return abs(difference);
}

void checkNumberOfZeros()
{
    zeros = 0;
    for (int i = 0; i < 4; i++)
    {
        if (numbers[i] == 0)
        zeros++;
    }
}

void runAgain()
{
    char c;
    std::cout
        <<std::endl
        <<"Run Again (Y/N): ";
    std::cin
        >>c;
    switch (c)
    {
        case 'Y':
        case 'y':
            main();
        case 'N':
        case 'n':
            std::cout
                <<std::endl;
            break;
        default:
            runAgain();       
    };
}
