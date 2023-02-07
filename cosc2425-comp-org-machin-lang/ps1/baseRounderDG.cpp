/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// baseRounderDG.cpp
// Dean Gadberry
// COSC 2425 0400
// ps1s1p4
// References:
    // https://stackoverflow.com/questions/46271465/find-character-in-a-string
// 
// This program rounds any number from any base in range[2,16] 
// to any number of decimal places
//
// See some examples at the bottom of this program

#include <iostream>
#include <string>

void promptUser();
int round();
void runAgain();
int makeInt(int);
char intToChar(int);

std::string value;
int base, decimal_places, final_index, value_index; 
    // A NOTE 
    // Do you think that the value_index and final_index would be better
    // if named as final_pointer and value_pointer?
double number;
const int 
    ASCII_0 = 48,
    ASCII_9 = 57,
    ASCII_A = 65,
    ASCII_F = 70;

int main()
{
    promptUser();
    final_index = value.find('.') + decimal_places;
    value_index = final_index + 1;
    number = makeInt(value_index);
    if (number / base >= 0.5 ) 
    {
        round();
        value[value_index] = intToChar(number);
    }
    std::cout
        <<"The result in base "
        <<base
        <<": ";
    for (int i = 0; i <= final_index; i++)
    {
        std::cout
            <<value[i];
    }
    std::cout
        <<std::endl;
    runAgain();
    return 0;
}

void promptUser()
{
    std::cout << std::endl
              << "Enter a value: ";
    std::cin  >> value;
    std::cout << "Enter the base of the value: ";
    std::cin  >> base;
    std::cout << "Number of decimal places to round: ";
    std::cin  >> decimal_places;
    std::cout << std::endl;
}

int round()
{
    value_index--; 
    if (value[value_index] == '.')
    {
        round();
        return 0;
    }
    number = makeInt(value_index);
    if (++number == base) // This increments regardless 
    {
        value[value_index] = '0';
        if (value_index == 0 )
        {
            value = '1' + value;
            final_index++;
            return 0;
        }
        round();
        return 0;
    }
    return 0;
}

int makeInt(int i)
{
    int ascii = static_cast<int>(value[i]);
    if (ASCII_0 <= ascii && ascii <= ASCII_9)
    {
        return ascii - 48; 
    }
    else if (ASCII_A <= ascii && ascii <= ASCII_F)
    {
        return ascii - 17 + 10 - 48;
    }
    main();
    return 0;
}

char intToChar(int i)
{
    if (i > 9)
    {
        return ASCII_A + i - 10; 
    }
    return ASCII_0 + i; 
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

// EXAMPLES:
    // $ ./baseRounderDG 
    // 
    // Enter a value: 24.5555555
    // Enter the base of the value: 6
    // Number of decimal places to round: 5
    // 
    // The result in base 6: 25.00000
    //
    // Run Again (Y/N): y
    // 
    // Enter a value: CC.CCC
    // Enter the base of the value: 13
    // Number of decimal places to round: 2
    // 
    // The result in base 13: D00.00
    // 
    // Run Again (Y/N): y
    // 
    // Enter a value: E01.DB9F
    // Enter the base of the value: 16
    // Number of decimal places to round: 2
    // 
    // The result in base 16: E01.DC
    // 
    // Run Again (Y/N): y
    // 
    // Enter a value: 09.25D24
    // Enter the base of the value: 14
    // Number of decimal places to round: 2
    // 
    // The result in base 14: 09.26
    // 
    // Run Again (Y/N): n
    //
