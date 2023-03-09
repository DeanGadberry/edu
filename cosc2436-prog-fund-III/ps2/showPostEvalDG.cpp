/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// showPostEvalDG.cpp 
// Dean Gadberry
// COSC 2436 0400
// Problem Set 2, Problem 3
// References:
    // https://stackoverflow.com/questions/31225418/how-to-put-words-from-a-sentence-input-into-an-array-c
        // used to convert string into individual operations 
    // https://en.cppreference.com/w/cpp/container/vector
    // https://stackoverflow.com/questions/3064976/why-have-pointer-parameters
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

void runAgain();
void stackNumbersList(std::vector<std::string>);
std::string operation(int, int, std::vector<std::string>*, std::string); // std::__cxx11::basic_string<char>

int main()
{
    std::cout
        <<std::endl
        <<"Enter a postfix expression: ";
    std::string postfix_expression;
    std::getline(std::cin, postfix_expression);
    // convert postfix_expression into individual operations
    std::istringstream input(postfix_expression);
    std::string individual_operation;
    std::vector<std::string> all_operations;
    while (input >> individual_operation)
        all_operations.push_back(individual_operation);
    std::cout
        <<std::endl
        <<std::endl
        <<"Stack Contents:"
        <<std::endl
        <<std::endl;
    std::vector<std::string> stack;
    for (auto&& individual_operation : all_operations)
    {
        if (
                individual_operation == "+" || 
                individual_operation == "-" || 
                individual_operation == "*" || 
                individual_operation == "/" )
        {
            int last_element_index = stack.size() - 1;
            int second_to_last_element_index = last_element_index - 1;
            stack.at(second_to_last_element_index) = operation(second_to_last_element_index, last_element_index, &stack, individual_operation);
            stack.pop_back();
            stackNumbersList(stack);
        }
        else if (stoi(individual_operation))
        {
            stack.push_back(individual_operation);
            std::cout
                <<"After push operation:";
            stackNumbersList(stack);
        }
    }
        std::cout
            <<std::endl
            <<"Final Value:";
        stackNumbersList(stack);
    runAgain();
return 0;}

void stackNumbersList(std::vector<std::string> stack)
{
    for (auto&& number : stack)
    {
        std::cout
            <<" "
            <<number;
    }
    std::cout
        <<std::endl;
}

std::string operation(int index_for_value1, int index_for_value2, std::vector<std::string> *stack, std::string operation)
{
    int final_value,
        v1 = std::stoi(stack->at(index_for_value1)),
        v2 = std::stoi(stack->at(index_for_value2));
    if (operation == "+")
        final_value = v1 + v2;
    if (operation == "-")
        final_value = v1 - v2;
    if (operation == "*")
        final_value = v1 * v2;
    if (operation == "/")
        final_value = v1 / v2;
    std::cout
        <<"After "
        <<operation
        <<" operation:";
    return std::to_string(final_value);
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
