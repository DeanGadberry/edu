//
#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    double volume, radius, height;

    cout << "This program will tell you the volume of\n";
    cout << "a cylinder-shaped fuel tank.\n";
    cout << "How tall is the tank? ";
    cin >> height;
    cout << "What is the radius of the tank? ";
    cin >> radius;

    volume = 3.14159 * radius * radius * height;
    
    cout << "The volume of the fuel tank is " << volume << endl;

    return 0;
}

