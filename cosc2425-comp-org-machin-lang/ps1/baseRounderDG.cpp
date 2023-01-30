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
int base, decimal, final_index, index_to_work_with;
double number_to_work_with;

int main()
{
    promptUser();
    final_index = value.find('.') + decimal;
    index_to_work_with = final_index + 1;
        std::cout<<"index_to_work_with: "<<index_to_work_with<<"\n";
    number_to_work_with = makeInt(index_to_work_with);
    if (number_to_work_with / base > 0.5 ) // || number_to_work_with + 1 == base)
    {
        round();
        value[index_to_work_with] = intToChar(number_to_work_with);
    }
//    else if (number_to_work_with / base < 0.5)
//    don't need ^^^^^^^^^ this line
//        ;
//        cutNumber();
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

int round()
{
    index_to_work_with--; //final_index
        std::cout<<"index_to_work_with: "<<index_to_work_with<<"\n";
    if (value[index_to_work_with] == 46)
    {
        round();
        return 0;
    }
    number_to_work_with = makeInt(index_to_work_with);
    if (number_to_work_with++ == base) // this should increment the number
    {
        value[index_to_work_with] = '0';
        round();
        return 0;
    }
    return 0;
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
    else if (ascii < 71 && ascii > 64) // A - F
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
