// TwosComplementDG.cpp
// Dean Gadberry
// COSC 2425 0400
// ps1s1p2
// References:
        // https://stackoverflow.com/questions/22746429/c-decimal-to-binary-converting
            // Used as reference for positiveToBinary()
        // https://en.wikipedia.org/wiki/Two%27s_complement
            // Used for sequence to convert positive binary to negative binary
#include <iostream>
#include <string>

void runAgain();
void convertToBinary();
std::string positiveToBinary(int);
std::string negativeConvert(std::string);
char invert(std::string, int);
void promptUser();

int run = 0, value; 
std::string output;

int main() 
{
    do {
        promptUser();
        std::cout<<value<<" = "<<output<<std::endl;
        runAgain();
    } while (run == 1);
    return 0;
}

void promptUser()
{
    std::cout <<std::endl <<"Enter a value: ";
    std::cin >>value;
    std::cout <<std::endl;
    convertToBinary();
}

void convertToBinary()
{
    if (value >= 0 && value < 128)
    {
        output = positiveToBinary(value);
    }
    else if (value < 0 && value > -129) 
    {
        output = positiveToBinary(value);
        output = negativeConvert(output); 
    }
    else
        promptUser();
}


std::string positiveToBinary(int to_binary)
{
    std::string binary_form;
    while (to_binary != 0)
    {
        if ( to_binary % 2 == 0)
            binary_form = "0" + binary_form;
        else
            binary_form = "1" + binary_form;
        to_binary /= 2;
    };
    while (binary_form.size() != 8)
    {
        binary_form = "0" + binary_form;
    };
    return binary_form;
}

std::string negativeConvert(std::string str)
{
    for (int i = 0; i < 8; i++)
    {
        str[i] = invert(str, i);
    };
    for (int i = 7; i >= 0; i--)
    {
        if (str[i] == '0')
        {
            str[i] = invert(str, i);
            return str;
        }
        str[i] = invert(str, i);
    };
    return str;
}

char invert(std::string str, int i)
{
    char c;
    if (str[i] == '0')
        c = '1';
    else
        c = '0';
    return c;
}

void runAgain()
{
    char c;
    std::cout
        <<"\nRun Again (Y/N): ";
    std::cin
        >>c;
    switch (c)
    {
        case 'Y':
        case 'y':
            run = 1;
            break;
        case 'N':
        case 'n':
            run = 0;
            std::cout<<std::endl;
            break;
        default:
            runAgain();       
    };
}

// https://stackoverflow.com/questions/22746429/c-decimal-to-binary-converting
// used this to model my positiveToBinary function
/*
std::string toBinary(int n)
{
    std::string r;
    while( n!=0 ) 
    {
        r = ( n % 2 == 0 ? "0" : "1" ) + r; 
        n /= 2;
    }
    return r;
}
*/

/*
2. Write a program to convert a decimal value to an eight-bit two's complement binary number. Let the
user enter a decimal whole number X, either positiveToBinary or negativeConvert, and output the equivalent two's
complement binary number. The value of X will range from [-128,127]. Error check input size. Output
to the screen, each X and its eight-bit two's complement equivalent separated by a space, =, and then
another space. Finally, the program should ask if the user wants to run the program again (Check case).
Refer to the sample output below.
Sample Runs:
Enter a value: 15
15 = 00001111
Run again (Y/N): Y
Enter a value: -49
-49 = 11001111
Run again (Y/N): n
Name the program: TwosComplementXX.cpp or TwosComplementXX.java, where XX are your initials.
3. Write a program, given a positiveToBinary number n, rotates the base-10 digits m positions rightward. That is,
*/
