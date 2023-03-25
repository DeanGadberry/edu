/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// hexNoConversion.cpp
// Dean Gadberry
// COSC 2425 0400
// Problem Set 2, Problem 1
// References:
#include <iostream>

void runAgain();

int main()
{
    //
    // receive user input
    //
    std::cout
        <<std::endl
        <<"Enter a postfix expression: ";
    std::string postfix_expression;

return 0;}

void runAgain()
{
    std::cout
        <<std::endl
        <<"Run Again (Y/N): ";
    std::string user_input;
    std::getline(std::cin, user_input);
    char input = user_input[0];
    switch (input)
    {
        case 'Y': case 'y': 
            main();
        case 'N': case 'n': 
            break;
        default:
            runAgain();       
    };
}
