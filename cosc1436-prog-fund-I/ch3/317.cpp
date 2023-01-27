//
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    cout << "1234567890" << endl;

    double a = 34.789;
    cout << setw(9) << setprecision(2) << fixed << a << endl;
    
    double b = 7.0;
    cout << setw(5) << setprecision(3) << fixed << showpoint << b << endl;

    double c = 5.789e+12;
    cout << setw(12) << setprecision(1) << fixed << showpoint << c << endl;

    int d = 67;
    cout << setw(7) << setprecision(0) << fixed << left << d << endl;

    return 0;
}

