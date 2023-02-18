//Course: COSC 2436
//Program set 1


//MinRectangles.cpp
#include <iostream> 
using namespace std;

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


void findLargestRectangle(int* M, int r, int c, int i, int j, int* ei, int* ej)
{
	int max_width = 0;
	int max_height = 0;
	int max_area_covered = 0;

	*ei = *ej = -1;
	for (max_width = 0; max_width < r - i && (*(M + j * r + (i + max_width)) != 0); max_width++)
	{
		int area_covered;
		int height_i = getMaxHeight(M, r, c, i, j, max_width + 1);
		if (height_i > max_height)
		{
			max_height = height_i;
		}
		area_covered = height_i * (max_width + 1);
		if (area_covered > max_area_covered)
		{
			max_area_covered = area_covered;
			*ei = i + max_width;
			*ej = j + height_i - 1;
		}
	}
}


void printMatrix(int* M, int r, int c)
{
	cout << "Generated grid:" << endl << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << *(M + r * i + j) << " ";
		}
		cout << endl;
	}
}


int main()
{

	int j2;
	int i2;
	int i = 0;
	int j = 0;
	int total_rects = 0;

	// Ask for number of rows and columns
	int r, c;
	cout << "Enter number of rows (2-10): ";
	cin >> r;

	// check that value is between 2 and 10
	if (r < 2 || r > 10)
	{
		cout << "Number of rows must be between 2 and 10" << endl;
		exit(1);
	}

	cout << "Enter number of columns (2-10): ";
	cin >> c;

	// check that value is between 2 and 10
	if (c < 2 || c > 10)
	{
		cout << "Number of columns must be between 2 and 10" << endl;
		exit(1);
	}

	// Create a matrix and fill it
	int* M = (int*)malloc((r * c) * sizeof(int));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			*(M + r * i + j) = (int)(rand() % 2); // random between 0 and 1
		}
	}
	cout << endl;
	printMatrix(M, r, c);
	cout << endl;

	for (j = 0; j < c; j++) {
		for (i = 0; i < r; i++)
		{
			if (*(M + j * c + i) == 1) // the value is 1
			{
				findLargestRectangle(M, r, c, i, j, &i2, &j2);
				int start_i;
				int start_j;
				total_rects++;
				for (start_j = j; start_j <= j2; start_j++)
				{
					for (start_i = i; start_i <= i2; start_i++)
					{
						*(M + start_j * c + start_i) = 2;
					}
				}
				//printMatrix(M, r, c);
			}
		}
	}
	cout << "The minimum number of rectnagles/squares formed is " << total_rects << endl; // print
	return 0;
}
