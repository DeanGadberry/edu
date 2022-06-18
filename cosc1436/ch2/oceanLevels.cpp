// Chapter 2 Programming Challenge # 7
// Ocean Levels
/* Assuming the ocean’s level is currently rising at about 1.5 millimeters per year, write a program that displays:
• The number of millimeters higher than the current level that the ocean’s level will be in 5 years
• The number of millimeters higher than the current level that the ocean’s level will be in 7 years
• The number of millimeters higher than the current level that the ocean’s level will be in 10 years
*/
#include <iostream>
using namespace std;
    float sealevel = 101; //sea level (in millimeters) recorded February 2022
    float mpy = 1.5; //ocean level rises 1.5 Millimeters Per Year (MPY)
void yearlyIncrease(int years) //wrote repetitive cout into function. This function takes parameter "years" and uses that number to calculate the sealevel increase
    // must be formatted as  In◦5◦years◦the◦ocean's◦level◦will◦be◦higher◦by◦7.5◦millimeters
{
    float increase = mpy * years;
    cout << "In " << years 
        << " years the ocean's level will be higher by "
        << increase << " millimeters." 
        << endl; 
}
int main()
{
/*
    cout << "The current sea level is " 
         << sealevel << " millimeters."
         << endl;
 */   
    yearlyIncrease(5);
    yearlyIncrease(7);
    yearlyIncrease(10);
}
