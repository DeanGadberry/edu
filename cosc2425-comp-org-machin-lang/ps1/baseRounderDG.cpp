// baseRounderDG.cpp
// Dean Gadberry
// COSC 2425 0400
// ps1s1p4
// References:
    // https://stackoverflow.com/questions/46271465/find-character-in-a-string

#include <iostream>
#include <string>

void promptUser();
void round();
void runAgain();
int makeInt(int);

int base, decimal;
std::string value;

int main()
{
    promptUser();
    round();
    runAgain();
    return 0;
}

void promptUser()
{
    std::cout << "Enter a value: ";
    std::cin  >> value;
    std::cout << "Enter the base of the value: ";
    std::cin  >> base;
    std::cout << "Number of decimal places to round: ";
    std::cin  >> decimal;
}

void round()
{
    int working_index = value.find('.') + decimal + 1;
std::cout<<"working_index: "<<working_index<<"\n";
    double working_number = makeInt(working_index);
    if (working_number / base > 0.5)
    {
        working_index--; 
std::cout<<"working_index: "<<working_index<<"\n";
        working_number = makeInt(working_index);
        if (working_number == base)
        {
            value[working_index] = '0';
            working_number--;
            // then need to check it and increment or decrement it....
            // will probably do this by changing to a function with a do while loop
        }
    }
//divide the one after it by the base
//if this division is greater than or equal to 1/5
    // increment the preceding value
    // call a function
        // function checks if the next value can increment
        // if it can, decrement the index and call the function again
}

int makeInt(int i)
{
    int ascii = static_cast<int>(value[i]);
std::cout<<"ascii: "<<ascii<<std::endl;
    if (ascii < 9 + 48 && ascii > 0 + 48) // 0 - 9
    {
std::cout<<"integer form: "<<ascii - 48 <<std::endl;
        return ascii - 48;
    }
    else if (ascii < 72 && ascii > 64) // A - G
    {
std::cout<<"integer form: "<<ascii-7-48<<std::endl;
        return ascii - 17 + 10 - 48;
    }
    std::cout <<"Please enter only numerals, a decimal, and capital letters.\n";
    main();
    return 0;
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
            main();
        case 'N':
        case 'n':
            std::cout<<std::endl;
            break;
        default:
            runAgain();       
    };
}
