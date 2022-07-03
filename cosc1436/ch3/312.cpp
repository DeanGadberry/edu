// This program tells the ASCII code for any given character
#include <iostream>
using namespace std;

int main() 
{
    char letter;

    cout << "enter a character\n";
    cin >> letter;
    cout << "ASCII code for \"" << letter;
    cout << "\" is " << static_cast<int>(letter) << endl;
    
    return 0;
}

