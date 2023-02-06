// minRectangleDG.cpp
// Dean Gadberry
// COSC 2436 0400
// ps1p1
// References:
    // https://stackoverflow.com/questions/8422709/random-boolean-value
    // https://stackoverflow.com/questions/9702053/how-to-declare-a-global-variable-in-c
    // https://www.youtube.com/watch?v=jn8_Xq3z48w&t=345s
        // really cool stuff that I decided not to use, 
        // but after looking at this, I noticed that it'll be 
        // easier to just allocate the max array and shrink it down later

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void promptUser();
void runAgain();
void checkInput();
void generateGrid();
int randomBit();
void printGrid();

const int MIN_ROWS = 2, MAX_ROWS = 10, MIN_COLUMNS = 2, MAX_COLUMNS = 10;

int grid[MAX_ROWS][MAX_COLUMNS];

int number_of_rows, number_of_columns; 

int main()
{
    srand(time(0)); // seed random number generator
    promptUser();
    generateGrid();
    printGrid();
    // next steps here!!!
    runAgain();
}

void promptUser()
{
    std::cout
        <<"Enter the number of rows (2-10): ";
    std::cin
        >>number_of_rows;
    std::cout
        <<"Enter the number of cols (2-10): ";
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
            <<"Valid Rows: between "
            <<MIN_ROWS
            <<" and "
            <<MAX_ROWS
            <<"."
            <<std::endl
            <<"Valid Columns: between "
            <<MIN_COLUMNS
            <<" and "
            <<MAX_COLUMNS
            <<"."
            <<std::endl;
        promptUser();
    }
}

void generateGrid()
{
    // std::vector<std::vector<int>> grid(number_of_rows, std::vector<int>(number_of_columns));
    grid[number_of_rows][number_of_columns];
    for (int i = 0; i < number_of_rows; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            grid[i][j] = randomBit();
        }
    }
}

int randomBit()
{
    // code found on stack exchange
    return rand() % 2;
}

void printGrid()
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
                <<grid[i][j];
        }
        std::cout
            <<std::endl;
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
