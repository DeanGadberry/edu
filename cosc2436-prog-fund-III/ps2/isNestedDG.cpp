/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// isNestedDG.cpp 
// Dean Gadberry
// COSC 2436 0400
// Problem Set 2, Problem 2
// References:

#include <iostream>
#include <string>
#include <vector>

void runAgain();

int main()
{
    std::cout
        <<std::endl
        <<"Enter an equation: ";
    std::string equation;
    std::getline(std::cin, equation);
    int parentheses, brackets, braces;
    parentheses = brackets = braces = 0;
    std::vector<char> delimeter_list;
    delimeter_list.clear();
    for (int i = 0; i < equation.length(); i++)
    {
        if (equation[i] == '(')
        {
            parentheses++;
            delimeter_list.push_back('(');
            std::cout<<*delimeter_list.end();
        }
        else if (equation[i] == ')')
        {
            parentheses--;
            if (*delimeter_list.end() == '(')
            {
                std::cout<<*delimeter_list.end();
                delimeter_list.pop_back();
            }
        }
        else if (equation[i] == '[')
        {
            brackets++;
            delimeter_list.push_back('[');
        }
        else if (equation[i] == ']')
        {
            brackets--;
        }
        else if (equation[i] == '{')
        {
            braces++;
            delimeter_list.push_back('{');
        }
        else if (equation[i] == '}')
        {
            braces--;
        }
        else
            break;
    }
    std::cout<<std::endl;
    if (parentheses + brackets + braces == 0)
        std::cout<<"Is nested correctly";
    else
        std::cout<<"Is not nested correctly";
    std::cout<<std::endl;
    runAgain();
}

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
