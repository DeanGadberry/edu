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
    // MinRectangles provided by professor Chegwidden 
        // used, with modifications, to count groups

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

void promptUser();
void checkInput();
int* generateGrid();
void printGrid(int *);
void whichPower();
void runAgain();
void countGroups(int *);
void powerFunction(int *,int,int);
void numberOfGroups(int*);
void findLargestRectangle(int*, int, int, int, int, int*, int*);
int getMaxHeight(int*, int, int, int, int, int);

const int MIN_ROWS = 2,
      MIN_COLUMNS = 2, 
      MAX_ROWS = 10, 
      MAX_COLUMNS = 10;
int number_of_rows, number_of_columns, power, groups = 0; 

class group {
};

int main()
{
    std::cout<<std::endl;
    srand(time(0)); // seed random number generator
    promptUser();
    int *grid = generateGrid();
    std::cout
        <<std::endl
        <<" Generated grid: "
        <<std::endl;
    printGrid(grid);
    // whichPower();
    numberOfGroups(grid);
    runAgain();
    delete grid;
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

/*
void whichPower()
{
    power = 0;
    while (number_of_columns * number_of_rows > pow(2, power))
    {
        power++;
    }
}
//
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
//
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
*/

void numberOfGroups(int* matrix)
{
    int i2, j2, total_rects = 0 ;
	for (int main_index_1 = 0; main_index_1 < number_of_columns; main_index_1++) {
		for (int main_index_2 = 0; main_index_2 < number_of_rows; main_index_2++)
		{
			if (*(matrix + main_index_1 * number_of_columns + main_index_2) == 1) // the value is 1
			{
				findLargestRectangle(matrix, number_of_rows, number_of_columns, main_index_2, main_index_1, &i2, &j2);
				total_rects++;
				for (int start_j = main_index_1; start_j <= j2; start_j++)
				{
					for (int start_i = main_index_2; start_i <= i2; start_i++)
					{
						*(matrix + start_j * number_of_columns + start_i) = 2;
					}
				}
//                printGrid(matrix); //printMatrix(M, r, c);
			}
		}
	}
    std::cout
        <<std::endl
        <<"The least number of rectangles/squares formed is "<<total_rects
        <<std::endl;
}

void findLargestRectangle(int* matrix, int rows, int columns, int main_index_2, int main_index_1, int* ei, int* ej)
{
	int max_width = 0;
	int max_height = 0;
	int max_area_covered = 0;
	*ei = *ej = -1;
	for (max_width = 0; 
            max_width < rows - main_index_2 
            && (*(matrix + main_index_1 * rows + (main_index_2 + max_width)) != 0); 
            max_width++)
	{
		int height_i = getMaxHeight(matrix, rows, columns, main_index_2, main_index_1, max_width + 1);
		if (height_i > max_height)
		{
			max_height = height_i;
		}
		int area_covered = height_i * (max_width + 1);
		if (area_covered > max_area_covered)
		{
			max_area_covered = area_covered;
			*ei = main_index_2 + max_width;
			*ej = main_index_1 + height_i - 1;
		}
	}
}

int getMaxHeight(int* M, int r, int c, int i, int j, int w)
{
	int j2 = -1;
	int i2;
	if (*(M + j * r + i) != 0) {
		for (j2 = j; j2 < c && *(M + j2 * r + i) != 0; j2++)
		{
			for (i2 = i; i2 - i < w; i2++)
			{
				if (*(M + r * j2 + i2) == 0)
					return j2 - j;
			}
		}
	}
	return j2 - j;
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
