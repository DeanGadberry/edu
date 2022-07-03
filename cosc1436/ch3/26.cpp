// review question # 26 PROMPT:
//
// Write a pseudocode algorithm for a program 
// that calculates the total of a retail sale.
// The program should ask for the amount of 
// the sale and the sales tax rate.
// The sales tax rate should be entered as 
// a floating-point number. 
// For example, if the sales tax rate is 6 
// percent, the user should enter 0.06. 
// The program should display the amount of 
// sales tax and the total of the sale.
// After you write the pseudocode algorithm, 
// convert it to a complete C++ program.
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    double price, tax;

    cout<< "Input Price and Tax as floating numbers\n"
        << "and I will tell you your total." 
        << endl
        << "Price: ";
    cin >> price;
    cout << "Tax: ";
    cin >> tax;
    price += tax * price;
    cout << setprecision(2)
        << fixed
        << "Total: "
        << price
        << endl;
    return 0;
}

// define sale price
// define tax rate
// request and record the sale price
// request and record the tax rate (be specific in prompt regarding formatting)
// price += tax rate * price
// display subtotal, tax rate, and final price
