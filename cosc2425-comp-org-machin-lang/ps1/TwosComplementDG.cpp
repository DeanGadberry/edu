// TwosComplementDG.cpp
// Dean Gadberry
// COSC 2425 0400
// ps1s1p2
// References:

#include <iostream>

void positiveToBinary();
void negativeToBinary();
void runAgain();
int run = 0, value;

int main() 
{
    do 
    {
        std::cout
            <<"Enter a value: ";
        std::cin
            >>value;
        std::cout
            <<value
            <<" = ";
    if (value > 0)
        positiveToBinary();
    else
        negativeToBinary();

    } while (run == 1);
}

void positiveToBinary()
{

}

void negativeToBinary()
{

}

void runAgain()
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
            run = 1;
            break;
        case 'N':
        case 'n':
            run = 0;
            break;
        default:
            runAgain();       
    };
}


/*
2. Write a program to convert a decimal value to an eight-bit two's complement binary number. Let the
user enter a decimal whole number X, either positiveToBinary or negativeToBinary, and output the equivalent two's
complement binary number. The value of X will range from [-128,127]. Error check input size. Output
to the screen, each X and its eight-bit two's complement equivalent separated by a space, =, and then
another space. Finally, the program should ask if the user wants to run the program again (Check case).
Refer to the sample output below.
Sample Runs:
Enter a value: 15
15 = 00001111
Run again (Y/N): Y
Enter a value: -49
-49 = 11001111
Run again (Y/N): n
Name the program: TwosComplementXX.cpp or TwosComplementXX.java, where XX are your initials.
3. Write a program, given a positiveToBinary number n, rotates the base-10 digits m positions rightward. That is,
*/
