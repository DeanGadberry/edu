// baseRounderDG.cpp
// Dean Gadberry
// COSC 2425 0400
// ps1s1p4
// References:
    // https://stackoverflow.com/questions/46271465/find-character-in-a-string

#include <iostream>
#include <string>

void promptUser();
int round();
void runAgain();
int makeInt(int);
char intToChar(int);

std::string value;
int base, decimal, final_index, value_index;
double number;

int main()
{
    promptUser();
    final_index = value.find('.') + decimal;
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
    std::cin  >> decimal;
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
    const int 
        ASCII_0 = 48,
        ASCII_9 = 57,
        ASCII_A = 65,
        ASCII_F = 70;
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
        return i + 7 + 48; //ASCII Character value
    }
    return i + 48; //ASCII Numeric Value
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
