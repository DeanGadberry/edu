// UnaryNosDG.cpp
// Dean Gadberry
// COSC 2425 0400
// ps1s1p1
// References:

#include <iostream>

void askToRunAgain();
void printUnary();
void promptUser();
void checkValue();

int positiveNumber, continueRunning = 0;

int main()
{
    do
    {
        promptUser();
        printUnary();
        askToRunAgain();
    } while (continueRunning == 1);
return 0; }

void checkValue()
{
    if (positiveNumber <=0 || positiveNumber > 80)
        promptUser();
}

void promptUser()
{
    std::cout
        <<"Enter a positive number: ";
    std::cin
        >>positiveNumber;
    checkValue();
}

void printUnary()
{
    std::cout
        <<positiveNumber
        <<" in Unary is: ";
    for (int i = 1; i < positiveNumber; i++)
    {
        std::cout
            <<"1";
    }
    std::cout
        <<"0";
}

void askToRunAgain()
{
    char c;
    std::cout
        <<"\nRun Again (Y/N): ";
    std::cin
        >>c;
    switch (c)
    {
        case 'Y':
        case 'y':
            continueRunning = 1;
            break;
        case 'N':
        case 'n':
            continueRunning = 0;
            break;
        default:
            askToRunAgain();       
    };
}


/*
Section One- Choose two problems.
1. Something simpler than binary numbers are unary numbers. A unary number, n > 0, is coded as n -
1 one bits followed by a zero bit. Thus, the code for the number 5 is 11110. Here are some examples of
unary numbers.
decimal unary
1 0
2 10
3 110
4 1110
5 11110
6 111110
7 1111110
Input from the keyboard a positive integer in the range [1,80]. Error check input. For each number,
output to the screen the number followed by its unary equivalent with no leading or trailing spaces.
Finally, the program should ask if the user wants to run the program again (Check case). Refer to the
sample output below.
Sample Run:
Enter a positive number: 37
37 in unary is: 1111111111111111111111111111111111110
Run again (Y/N): Y
Enter a positive number: 1
1 in unary is: 0
Run again (Y/N): n
Name the program: UnaryNosXX.cpp or UnaryNosXX.java, where XX are your initials.
2. Write a program to convert a decimal value to an eight-bit two's complement binary number. Let the
*/
