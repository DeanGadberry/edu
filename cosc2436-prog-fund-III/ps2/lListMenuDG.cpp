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
    // https://stackoverflow.com/questions/39443349/how-to-display-horizontally-in-c
    // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
    // https://stackoverflow.com/questions/16747591/how-to-get-an-element-at-specified-index-from-c-list
        // This reference really drove home the fact that the stl list is still a class
// 
// TODO:
    // rotate does not work properly
        // clear the temp after rotate
    // shift does not work properly
    // delete
        // after a rotate, things function oddly
    // search
        // tell where the value is (within the list)
        // cout when value is not found

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <iomanip>

int listInsert(std::list<int> the_list);
int listDelete(std::list<int> the_list);
int listSearch(std::list<int> the_list);
int listPrint(std::list<int> the_list);
int listSize(std::list<int> the_list);
int listSort(std::list<int> the_list);
int listReverse(std::list<int> the_list);
int listRotate(std::list<int> the_list);
int listShift(std::list<int> the_list);
int listClear(std::list<int> the_list);
int menu(std::list<int> the_list);
char userInput();
bool listEmpty(std::list<int>);
int help();

int main()
{
    std::list<int> the_list;
    menu(the_list);
    return 0;
}

int menu(std::list<int> the_list)
{
    std::cout
        <<std::endl
        <<"Continue to Menu? (y/n): ";
    switch (userInput())
    {
        case 'y': case 'Y': break;
        case 'n': case 'N': 
                            std::cout
                                <<std::endl
                                <<"Sorry, you can literally only continue to the menu."
                                <<std::endl;
                            menu(the_list); return 0;
    }
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
        <<"|            | Q. Quit    |"<<std::endl
        <<"+-------------------------+"<<std::endl
        <<std::endl
        <<"Make a selection: ";
    switch (userInput())
    {
        case '1':  listInsert(the_list); break;
        case '2':  listDelete(the_list); break;
        case '3':  listSearch(the_list); break;
        case '4':   listPrint(the_list); break;
        case '5':    listSize(the_list); break;
        case '6':    listSort(the_list); break;
        case '7': listReverse(the_list); break;
        case '8':  listRotate(the_list); break;
        case '9':   listShift(the_list); break;
        case '0':   listClear(the_list); break;
        case 'Q': case 'q': break;
        default: std::cout<<std::endl<<"Please enter an integer from the Menu."<<std::endl; menu(the_list); break;
    }
    return 0;
};

char userInput()
{
    std::string user_input;
    std::getline(std::cin, user_input);
    return user_input[0];
};

int listInsert(std::list<int> the_list)
{
    std::cout
        <<std::endl
        <<"Enter an integer: ";
    int value = (userInput() - '0');
    for (auto&& v : the_list)
    {
        if (v == value)
        {
            std::cout
                <<std::endl
                <<"Please select a different value. The value, "
                <<value
                <<", is already in use."
                <<std::endl;
            listInsert(the_list);
            return 0;
        }
    }
    std::cout
        <<std::endl
        <<"+-----------------+"<<std::endl
        <<"| 1. Insert First |"<<std::endl
        <<"| 2. Insert Last  |"<<std::endl
        <<"+-----------------+"<<std::endl
        <<std::endl
        <<"Make a selection to insert value ("
        <<value
        <<"): ";
    char selection = userInput();
    if (selection == '1')
    {
        the_list.push_front(value);
        menu(the_list);
        return 0;
    }
    else if (selection == '2')
    {
        the_list.push_back(value);
        menu(the_list);
        return 0;
    }
    else 
    {
        listInsert(the_list);
        return 0;
    };
};

int listDelete(std::list<int> the_list)
{
    if (the_list.size() == 0)
    {
        std::cout
            <<std::endl
            <<"Cannot Delete, List is empty."
            <<std::endl;
        menu(the_list);
        return 0;
    };
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
        the_list.pop_back();
        break;
    default: listDelete(the_list);
    };
    menu(the_list);
    return 0;
};

int listSearch(std::list<int> the_list)
{
    std::cout
        <<std::endl
        <<"Enter a search value: ";
    int search = (userInput() - '0');
    for (std::list<int>::iterator iter = the_list.begin(); iter != the_list.end(); iter++)
    {
        if (*iter == search)
            std::cout
                <<std::endl
                <<*iter
                <<" exists in the list."
                <<std::endl;
    };
    menu(the_list);
    return 0;
};

int listPrint(std::list<int> the_list)
{
    if (the_list.size() == 0)
    {
        menu(the_list);
        return 0;
    }
    std::ostringstream line_a, line_b, line_c, line_d;
    int last_value, output_number;
    for (std::list<int>::iterator iter = the_list.begin(); iter != the_list.end(); iter++)
    {
        if (*iter == the_list.back()) 
        {
            last_value = *iter;
            continue;
        }
        line_a <<std::setw(16) <<"+-----+--+      ";
        line_b <<std::setw(16) <<"|     |  | ---> ";
        line_c <<"|  " <<*iter<<"  |  |      ";
        line_d <<std::setw(16) <<"+-----+--+      ";
    };
    std::cout
        <<std::endl
        <<line_a.str() <<"+-----+--+"
        <<std::endl
        <<line_b.str() <<"|     |\\ |"
        <<std::endl
        <<line_c.str() <<"|  "<<last_value <<"  | \\|"
        <<std::endl
        <<line_d.str() <<"+-----+--+"
        <<std::endl;
    menu(the_list);
    return 0;
};

int listSize(std::list<int> the_list)
{
    int list_size = 0;
    for (std::list<int>::iterator iter = the_list.begin(); iter != the_list.end(); iter++)
    {
        list_size++;
    };
    if (list_size > 1)
    {
        std::cout
            <<std::endl
            <<"List is currently "
            <<list_size
            <<" values in length."
            <<std::endl;
    }
    else
    {
        std::cout
            <<std::endl
            <<"List is currently "
            <<list_size
            <<" value in length."
            <<std::endl;
    }
    menu(the_list);
    return 0;
};

int listSort(std::list<int> the_list)
{
    the_list.sort();
    menu(the_list);
    return 0;
};

int listReverse(std::list<int> the_list)
{
    the_list.reverse();
    menu(the_list);
    return 0;
};

int listRotate(std::list<int> the_list)
{
    if (the_list.size() < 2)
    {
        menu(the_list);
        return 0;
    }
    int temporary = the_list.front();
    the_list.push_back(temporary);

    menu(the_list);
    return 0;
};

int listShift(std::list<int> the_list)
{
    if (the_list.size() < 2)
    {
        menu(the_list);
        return 0;
    }
    std::list<int> temporary_list;
    int iterator = 0;
    for (auto&& value : the_list)
    {
        if (++iterator % 2 == 0)
        {
            temporary_list.push_back(value);
        }
    }
    for (auto&& value : the_list)
    {
        if (++iterator % 2 == 1)
        {
            temporary_list.push_back(value);
        }
    }
    the_list.swap(temporary_list);
    menu(the_list);
    return 0;
};

int listClear(std::list<int> the_list)
{
    the_list.erase(the_list.begin(), the_list.end());
    std::cout
        <<std::endl
        <<"Empty List"
        <<std::endl;
    menu(the_list);
    return 0;
};
