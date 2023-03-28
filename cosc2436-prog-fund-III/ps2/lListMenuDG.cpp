/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// lListMenuDG.cpp 
// Dean Gadberry
// COSC 2436 0400
// Problem Set 2, Problem 4
// References:

#include <iostream>
#include <string>
#include <list>

char userInput()
{
    std::string user_input;
    std::getline(std::cin, user_input);
    return user_input[0];
};

void listInsert(std::list<int> the_list, std::list<int>::iterator iterator_of_the_list)
{
// insert - push_back and push_front
    std::cout
        <<std::endl
        <<"+-----------------+"<<std::endl
        <<"| 1. Insert First |"<<std::endl
        <<"| 2. Insert Last  |"<<std::endl
        <<"+-----------------+"<<std::endl
        <<std::endl
        <<"Make a Selection: ";
    // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
    switch (userInput() - '0')
    {
    case 1:
        std::cout
            <<"Enter an integer: ";
        the_list.push_front(userInput() - '0');
        break;
    case 2:
        std::cout
            <<"Enter an integer: ";
        the_list.push_back(userInput() - '0');
        break;
    default: listInsert(the_list, iterator_of_the_list);
    }
};

void listDelete(std::list<int> the_list, std::list<int>::iterator iterator_of_the_list)
{
// delete - pop_front and pop_back
    std::cout
        <<std::endl
        <<"+-----------------+"<<std::endl
        <<"| 1. Delete First |"<<std::endl
        <<"| 2. Delete Last  |"<<std::endl
        <<"+-----------------+"<<std::endl
        <<std::endl
        <<"Make a Selection: ";
    switch (userInput() - '0')
    {
    case 1:
        the_list.pop_front();
        break;
    case 2:
        std::cout
            <<"Enter an integer: ";
        the_list.pop_back();
        break;
    default: listDelete(the_list, iterator_of_the_list);
    };
};

void listSearch(std::list<int> the_list, std::list<int>::iterator iterator_of_the_list)
{
// search - for each of the elements, check if they equal the search term
    std::cout<<"search"<<std::endl;
};
void listPrint(std::list<int> the_list, std::list<int>::iterator iterator_of_the_list)
{
// print  - for each element, if it isn't the end, apend with the arrows
    int length_of_list = 0;
    for (iterator_of_the_list = the_list.begin(); iterator_of_the_list != the_list.end(); iterator_of_the_list++)
        length_of_list++;

//  std::cout
//      <<"+-----+--+"<<std::endl
//      <<"|     |\ |"<<std::endl
//      <<"|     | \|"<<std::endl
//      <<"+-----+--+"<<std::endl
    for (iterator_of_the_list = the_list.begin(); iterator_of_the_list != the_list.end(); iterator_of_the_list++)
    {
        std::cout
            <<"+-----+--+      " *\ length_of_list<<std::endl
            <<"|     |  |----->" * length_of_list<<std::endl
            <<"|     |  |      " * length_of_list<<std::endl
            <<"+-----+--+      " * length_of_list<<std::endl
    };
};
void listSize(std::list<int> the_list, std::list<int>::iterator iterator_of_the_list)
{
// size   - for each element, increment a counter
    std::cout<<"size"<<std::endl;
};
void listSort(std::list<int> the_list, std::list<int>::iterator iterator_of_the_list)
{
// sort   - implement a sort function through a loop of the elements
    std::cout<<"sort"<<std::endl;
};
void listReverse(std::list<int> the_list, std::list<int>::iterator iterator_of_the_list)
{
// reverse- list.reverse()
    std::cout<<"reverse"<<std::endl;
};
void listRotate(std::list<int> the_list, std::list<int>::iterator iterator_of_the_list)
{
// rotate - check if the list has only 1 element or less (no effect)
    // temporary list which receives all 
    // of the primary list elements shifted by 1
    // copy temporary list to primary and delete all of temporary list
    std::cout<<"rotate"<<std::endl;
};
void listShift(std::list<int> the_list, std::list<int>::iterator iterator_of_the_list)
{
// shift  - check element length
            // temp list which receives all even numbered values
            // and then the odd number values after that
            // then copy the temp list to the primary and delete the temp
    std::cout<<"shift"<<std::endl;
};
void listClear(std::list<int> the_list, std::list<int>::iterator iterator_of_the_list)
{
// clear  - list.erase(firstIter, lastIter)
    std::cout<<"clear"<<std::endl;
};

void help()
{
    // Error check user input function
// insert - push_back and push_front
// delete - pop_front and pop_back
// search - for each of the elements, check if they equal the search term
// print  - for each element, if it isn't the end, apend with the arrows
// size   - for each element, increment a counter
// sort   - implement a sort function through a loop of the elements
// reverse- list.reverse()
// rotate - check if the list has only 1 element or less (no effect)
            // temporary list which receives all 
            // of the primary list elements shifted by 1
            // copy temporary list to primary and delete all of temporary list
// shift  - check element length
            // temp list which receives all even numbered values
            // and then the odd number values after that
            // then copy the temp list to the primary and delete the temp
// clear  - list.erase(firstIter, lastIter)
// help   - maybe list this stuff
};

void menu(std::list<int> the_list, std::list<int>::iterator iterator_of_the_list)
{
    std::cout
        <<std::endl
        <<"Menu:"
        <<std::endl
        <<std::endl
        <<"+------------+------------+"<<std::endl
        <<"| 1. Insert  | 6. Sort    |"<<std::endl
        <<"| 2. Delete  | 7. Reverse |"<<std::endl
        <<"| 3. Search  | 8. Rotate  |"<<std::endl
        <<"| 4. Print   | 9. Shift   |"<<std::endl
        <<"| 5. Size    | 0. Clear   |"<<std::endl
        <<"+------------+------------+"<<std::endl
        <<"| H. Help    | Q. Quit    |"<<std::endl
        <<"+-------------------------+"<<std::endl
        <<std::endl
        <<"Make a selection: ";
    switch (userInput())
    {
        case '1':  listInsert(the_list, iterator_of_the_list); break;
        case '2':  listDelete(the_list, iterator_of_the_list); break;
        case '3':  listSearch(the_list, iterator_of_the_list); break;
        case '4':   listPrint(the_list, iterator_of_the_list); break;
        case '5':    listSize(the_list, iterator_of_the_list); break;
        case '6':    listSort(the_list, iterator_of_the_list); break;
        case '7': listReverse(the_list, iterator_of_the_list); break;
        case '8':  listRotate(the_list, iterator_of_the_list); break;
        case '9':   listShift(the_list, iterator_of_the_list); break;
        case '0':   listClear(the_list, iterator_of_the_list); break;
        case 'H': case 'h': help(); menu(the_list, iterator_of_the_list); break;
        case 'Q': case 'q': break;
        default: std::cout<<std::endl<<"Please enter an integer from the Menu."<<std::endl; menu(the_list, iterator_of_the_list); break;
    };
};

int main()
{
    std::list<int> the_list;
    std::list<int>::iterator iterator_of_the_list;
    menu(the_list, iterator_of_the_list);
}
