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

void listInsert(std::list<int> the_list, std::list<int>::iterator the_list_iterator)
{
    std::cout<<"insert"<<std::endl;
    std::cout
        <<"Enter a value: ";
};
void listDelete(std::list<int> the_list, std::list<int>::iterator the_list_iterator)
{
    std::cout<<"delete"<<std::endl;
};
void listSearch(std::list<int> the_list, std::list<int>::iterator the_list_iterator)
{
    std::cout<<"search"<<std::endl;
};
void listPrint(std::list<int> the_list, std::list<int>::iterator the_list_iterator)
{
    std::cout<<"print"<<std::endl;
};
void listSize(std::list<int> the_list, std::list<int>::iterator the_list_iterator)
{
    std::cout<<"size"<<std::endl;
};
void listSort(std::list<int> the_list, std::list<int>::iterator the_list_iterator)
{
    std::cout<<"sort"<<std::endl;
};
void listReverse(std::list<int> the_list, std::list<int>::iterator the_list_iterator)
{
    std::cout<<"reverse"<<std::endl;
};
void listRotate(std::list<int> the_list, std::list<int>::iterator the_list_iterator)
{
    std::cout<<"rotate"<<std::endl;
};
void listShift(std::list<int> the_list, std::list<int>::iterator the_list_iterator)
{
    std::cout<<"shift"<<std::endl;
};
void listClear(std::list<int> the_list, std::list<int>::iterator the_list_iterator)
{
    std::cout<<"clear"<<std::endl;
};
void help()
{
};

void menu(std::list<int> the_list, std::list<int>::iterator the_list_iterator)
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
    std::string user_input;
    std::getline(std::cin, user_input);
    char input = user_input[0];
    switch (input)
    {
        case '1': listInsert(the_list, the_list_iterator);  menu(the_list, the_list_iterator); break;
        case '2': listDelete(the_list, the_list_iterator);  menu(the_list, the_list_iterator); break;
        case '3': listSearch(the_list, the_list_iterator);  menu(the_list, the_list_iterator); break;
        case '4': listPrint(the_list, the_list_iterator);   menu(the_list, the_list_iterator); break;
        case '5': listSize(the_list, the_list_iterator);    menu(the_list, the_list_iterator); break;
        case '6': listSort(the_list, the_list_iterator);    menu(the_list, the_list_iterator); break;
        case '7': listReverse(the_list, the_list_iterator); menu(the_list, the_list_iterator); break;
        case '8': listRotate(the_list, the_list_iterator);  menu(the_list, the_list_iterator); break;
        case '9': listShift(the_list, the_list_iterator);   menu(the_list, the_list_iterator); break;
        case '0': listClear(the_list, the_list_iterator);   menu(the_list, the_list_iterator); break;
        case 'H': case 'h': help(); menu(the_list, the_list_iterator); break;
        case 'Q': case 'q': break;
    };
};

int main()
{
    std::list<int> the_list;
    std::list<int>::iterator the_list_iterator;
    menu(the_list, the_list_iterator);
}
