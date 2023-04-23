/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// showBinSearchDG.cpp
// Dean Gadberry
// COSC 2436 0400
// Problem Set 3, Problem 1
// References:

#include <iostream>
#include <string>

void runAgain();
int binarySearch(int array[], int first, int last, int value);

const int FIRST = 0;

int main()
{
   int value, last;
   std::cout
      <<std::endl
      <<"Enter largest range value [1-100000]: ";
   std::cin
      >>last;
   std::cout
      <<std::endl
      <<"Enter search target: ";
   std::cin
      >>value;
   std::cin;
   int *valueArray = new int[last];
   for (int i = 0; i < last; i++)
   { 
      valueArray[i] = i + 1; 
   }
   int searchIndex = binarySearch(valueArray, FIRST, last - 1, value);
   std::string whetherObtained;
   if (valueArray[searchIndex] == value)
      whetherObtained = "GOT IT!";
   else
      whetherObtained = "NOT GOT IT!";
   std::cout
      <<whetherObtained
      <<std::endl;
   delete valueArray;
   runAgain();
return 0;}

int binarySearch(int array[], int first, int last, int value)
{
   int middle; // Mid point of search
   if (first > last)
      return -1;
   middle = (first + last)/2;
   std::cout
      <<array[first]
      <<"-"
      <<array[middle]
      <<"-"
      <<array[last]
      <<std::endl;
   if (array[middle]==value)
      return middle;
   if (array[middle]<value)
      return binarySearch(array, middle+1,last,value);
   else
      return binarySearch(array, first,middle-1,value);
}

void runAgain()
{
    std::cout
        <<std::endl
        <<"Run Again (Y/N): ";
    std::string user_input;
    std::cin
       >>user_input;
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
