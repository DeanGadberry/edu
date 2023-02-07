/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
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
    return 0; 
}

void checkValue()
{
    if (positiveNumber <=0 || positiveNumber > 80)
        promptUser();
}

void promptUser()
{
    std::cout
        <<std::endl
        <<"Enter a positive number: ";
    std::cin
        >>positiveNumber;
    checkValue();
}

void printUnary()
{
    std::cout
        <<std::endl
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
        <<std::endl
        <<std::endl
        <<"Run Again (Y/N): ";
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
            std::cout
                <<std::endl;
            break;
        default:
            askToRunAgain();       
    };
}
