/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// minRectangleDG.cpp 
// Dean Gadberry
// COSC 2436 0400
// ps1p1
// References:
    // https://stackoverflow.com/questions/8422709/random-boolean-value
    // https://stackoverflow.com/questions/9702053/how-to-declare-a-global-variable-in-c
    // https://www.geeksforgeeks.org/how-to-declare-a-2d-array-dynamically-in-c-using-new-operator/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// NO! A CLASS!!
// structure to store neighbors (1-values vertical or horizontal to a primary value)
    // initial location = pointer to primary value
    // northern neighbor = pointer to matrix value north of primary value
    // eastern neighbor = pointer to value east
    // southern neighbor
    // western neighbor
// function to return which neighbors 
    // this is a constructor in the neighbor class
// if else functions to check the equivalence of neighbors...
    // this seems tedious and difficult to manage
    // it ought to be a function within the the class, a public function?)
// function to test if a value is a 1
// function to receive coordinates and find neighbors
    // this will call the checking if the value is a 1.
    // in fact, that is an extraneous function
// if a coordinate is == 0 || coordinate == number_of_* - 1)
    // check -1 or 0
void promptUser();
void checkInput();
int* generateGrid();
void printGrid(int *);
void whichPower();
// find neighbors
void runAgain();
void countGroups(int *);
void powerFunction(int *,int,int);

const int MIN_ROWS = 2,
      MIN_COLUMNS = 2, 
      MAX_ROWS = 5, 
      MAX_COLUMNS = 5;
int number_of_rows, number_of_columns, power, groups = 0; 
class neighborhood // this class stores an initial value and 
{
    
};

int main()
{
    std::cout<<std::endl;
    srand(time(0)); // seed random number generator
    promptUser();
    int *grid = generateGrid();
    printGrid(grid);
    whichPower();
    countGroups(grid);
    // program which checks each number in the array 
        // it finds coordinates of numbers which have neighbors
        // it calls a function within it 
        // this internal function is an if else for up left right and down. 
            // it will return the x,x',y, or y' value
    // next steps here!!!
    runAgain();
    delete[] grid;
}

void promptUser()
{
    std::cout
        <<"Enter the number of rows ("<<MIN_ROWS<<"-"<<MAX_ROWS<<"): ";
    std::cin
        >>number_of_rows;
    std::cout
        <<"Enter the number of cols ("<<MIN_COLUMNS<<"-"<<MAX_COLUMNS<<"): ";
    std::cin
        >>number_of_columns;
    checkInput();
}

void checkInput()
{
    //check if numbers are outside of allowable bounds
    if (MIN_ROWS > number_of_rows 
            || number_of_rows > MAX_ROWS 
            || MIN_COLUMNS > number_of_columns 
            || number_of_columns > MAX_COLUMNS)
    {
        std::cout
            <<"For ROWS, use a number between "
            <<MIN_ROWS
            <<" and "
            <<MAX_ROWS
            <<"."
            <<std::endl
            <<"For COLUMNS, use a number between "
            <<MIN_COLUMNS
            <<" and "
            <<MAX_COLUMNS
            <<"."
            <<std::endl;
        promptUser();
    }
}

int* generateGrid()
{
    int *grid = new int[number_of_rows * number_of_columns];
    for (int i = 0; i < number_of_rows; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            *(grid + i * number_of_columns + j) = rand() % 2;
        }
    }
    return grid;
}

void printGrid(int *grid)
{
    std::cout
        <<std::endl
        <<" Generated grid: "
        <<std::endl
        <<std::endl;
    for (int i = 0; i < number_of_rows; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            std::cout
                <<" "
                <<*(grid + i * number_of_columns + j);
        }
        std::cout
            <<std::endl;
    }
}

void whichPower()
{
    power = 0;
    while (number_of_columns * number_of_rows > pow(2, power))
    {
        power++;
    }
}

void countGroups(int *grid)
{
    for (int i = 0; i < number_of_rows; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            if ( *(grid + i * number_of_columns + j) = 1)
            {
                powerFunction(grid, i, j);
            }
        }
    }
}

void powerFunction(int *grid, int row_index, int column_index)
{
    if (power == 3)
    {
        for (int i = row_index; i < number_of_rows; i++)
        {
            for (int j = column_index; j < number_of_columns; j++)
            {
                std::cout<<"test";
            }
        }
    }
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
        case 'Y': case 'y': 
        case '1': case '2': case '3': 
        case '4': case '5': case '6': 
        case '7': case '8': case '9': 
            main();
        case 'N': case 'n': case '0':
            break;
        default:
            runAgain();       
    };
}
