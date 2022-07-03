// programming challenge # 17 PROMPT
// Write a program that can be used as a math tutor for a young student. 
// The program should display two random numbers to be added, such as
//  247
// +129
// ----
// The program should then pause while the student works on the problem. 
// When the student is ready to check the answer, 
// he or she can press a key and the program will display the correct solution:
//  247
// +129
// ----
//  376
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    const int MIN_VALUE = 100; //minimum number for addition problem
    const int MAX_VALUE = 999; //maximum number for addition problem

    //declare variables
    int rand1, rand2, solution;
    
    //get the system time
    unsigned seed = time(0);
    
    //seed the random number generator
    srand(seed);

    //this is the only bit that is confusing me...
    //looks like in this example, 999 - 100 + 1 = 900
    //then the random number is divided by 900 and the remainder is retained. 
    //the remainder is added to the minimum value(100)
    //and it's a random number in the field defined??
    //how does this set the ceiling?
    //Oh! Because the remainder will never excede the upper limit
    //and it is added to the minimum value to put it within bounds.
    //Fascinating! and the +1, in case it comes out as a zero?
    //I wonder what role that +1 plays...
    rand1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    rand2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    //define solution
    solution = rand1 + rand2;

    cout << "Okay kid, here's a math problem for you." << endl
        << "Press [Enter] to see the solution." << endl 
        << setw(5) << right
        << rand1 << endl
        << " +" << rand2 << endl
        << " ----";
    cin.get();
    cout << setw(5) << right
        << solution << endl;
    return 0;
}

