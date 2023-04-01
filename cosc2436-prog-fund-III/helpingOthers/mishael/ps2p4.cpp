#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <iomanip>

using namespace std;

//reference https://github.com/DeanGadberry/edu/blob/main/cosc2436-prog-fund-III/ps2/lListMenuDG.cpp

int listInsert(list<int> the_list);
int listDelete(list<int> the_list);
int listSearch(list<int> the_list);
int listPrint(list<int> the_list);
int listSize(list<int> the_list);
int listSort(list<int> the_list);
int listReverse(list<int> the_list);
int listRotate(list<int> the_list);
int listShift(list<int> the_list);
int listClear(list<int> the_list);
int Options(list<int> the_list);


char userInput()
{
    string user_input;
    getline(std::cin, user_input);
    return user_input[0];
};

int options(list<int> the_list)
{
    cout << "1. Insert  | 2. Delete" << endl;
    cout << "3. Search  | 4. Print" << endl;
    cout << "5. Size    | 6 Sort" << endl;
    cout << "7. Reverse | 8. Rotate" << endl;
    cout << "9. Shift   | 0. Clear" << endl;
    cout << "Q. Quit    |" << endl;

    cout << "Option #: ";

    switch (userInput())
    {
        case '1': listInsert(the_list); break;
//      case '2': listDelete(the_list); break;
//      case '3': listSearch(the_list); break;
//      case '4': listPrint(the_list); break;
//      case '5': listSize(the_list); break;
//      case '6': listSort(the_list); break;
//      case '7': listReverse(the_list); break;
//      case '8': listRotate(the_list); break;
//      case '9': listShift(the_list); break;
//      case '0': listClear(the_list); break;
//      case 'Q': case 'q': break;
    }
    return 0;
};

int listInsert(list<int> the_list)
{
    cout << "Insert variable: ";
    int value = (userInput() - '0');
    for (auto&& v : the_list)
    {
        if (v == value)
        {
            std::cout
                << endl
                << "Please select a different value. The value, " << value << ", is already in use." << endl;

            listInsert(the_list);
            return 0;
        }

        else
        {
            for (auto x = the_list.begin(); x != the_list.end(); ++x)
            {
                cout << *x << " ";
                the_list.push_front(value);
            }
        }
    }


    return 0;
};

int main()
{
    list<int> the_list;
        options(the_list);
    return 0;
}
int listInsert(list<int> the_list);
int listDelete(list<int> the_list);
int listSearch(list<int> the_list);
int listPrint(list<int> the_list);
int listSize(list<int> the_list);
int listSort(list<int> the_list);
int listReverse(list<int> the_list);
int listRotate(list<int> the_list);
int listShift(list<int> the_list);
int listClear(list<int> the_list);
int Options(list<int> the_list);
