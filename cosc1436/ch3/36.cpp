//
#include <iostream>
using namespace std;

int main() 
{
    double pounds, kilograms;

    cout << "Aloha, what is your weight in pounds?" << endl;
    cin >> pounds;

    kilograms = pounds / 2.2;

    cout << "You weigh " << kilograms << " kilograms,\nLose some weight!" << endl;
    return 0;
}
