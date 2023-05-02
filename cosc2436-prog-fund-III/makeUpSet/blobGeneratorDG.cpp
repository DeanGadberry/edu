/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// royalOrderDG.cpp
// Dean Gadberry
// COSC 2436 0400
// Make Up Set, Problem 4
// References:
    // https://www.w3schools.com/cpp/cpp_conditions_shorthand.asp

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

const int MAX_SIZE = 50;

void blobs(char grid[][MAX_SIZE], int rows, int cols, int row, int col);
int countBlobs(char grid[][MAX_SIZE], int rows, int cols);
void printGrid(char grid[][MAX_SIZE], int rows, int cols);
void errorOutput();

int main() 
{
    char grid[MAX_SIZE][MAX_SIZE];
    int rows, cols, prob, blobs;
    char again = 'Y';
    srand(time(0));
    while (again == 'Y' || again == 'y'){
        std::cout 
            <<std::endl
            <<"Enter row size [1,50]: ";
        std::cin 
            >>rows;
        if (rows < 1 || rows > MAX_SIZE) 
        {
            errorOutput();
            continue;
        }
        std::cout 
            <<"Enter column size [1,50]: ";
        std::cin 
            >>cols;
        if (cols < 1 || cols > MAX_SIZE) 
        {
            errorOutput();
            continue;
        }
        std::cout 
            <<"Percentage probability [0,100]: ";
        std::cin 
            >>prob;
        if (prob < 0 || prob > 100) 
        {
            errorOutput();
            continue;
        }
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                if (rand() % 100 < prob) 
                {
                    grid[i][j] = 'X';
                } 
                else 
                {
                    grid[i][j] = '-';
                }
            }
        }
        std::cout 
            <<std::endl;
        printGrid(grid, rows, cols);
        blobs = countBlobs(grid, rows, cols);
        std::cout 
            <<std::endl
            <<"There " 
            <<(blobs == 1 ? "is 1 blob." : "are " + std::to_string(blobs) + " blobs.") 
            <<std::endl
            <<std::endl;
        std::cout 
            <<"Run Again (Y/N): ";
        std::cin 
            >>again;
        again = toupper(again);
    }
    return 0;
}

void errorOutput()
{
    std::cout 
        <<"Invalid input. Please try again." 
        <<std::endl;
}

void blobs(char grid[][MAX_SIZE], int rows, int cols, int row, int col)
{
    if (row < 0 
            || row >= rows 
            || col < 0 
            || col >= cols 
            || grid[row][col] != 'X') 
    {
        return;
    }
    grid[row][col] = '-';
    blobs(grid, rows, cols, row-1, col-1);
    blobs(grid, rows, cols, row-1, col);
    blobs(grid, rows, cols, row-1, col+1);
    blobs(grid, rows, cols, row, col-1);
    blobs(grid, rows, cols, row, col+1);
    blobs(grid, rows, cols, row+1, col-1);
    blobs(grid, rows, cols, row+1, col);
    blobs(grid, rows, cols, row+1, col+1);
}

int countBlobs(char grid[][MAX_SIZE], int rows, int cols) 
{
    int count = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (grid[i][j] == 'X') 
            {
                count++;
                blobs(grid, rows, cols, i, j);
            }
        }
    }
    return count;
}

void printGrid(char grid[][MAX_SIZE], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            std::cout 
                <<grid[i][j];
        }
        std::cout 
            <<std::endl;
    }
}
