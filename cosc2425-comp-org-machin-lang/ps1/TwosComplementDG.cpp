// TwosComplementDG.cpp
// Dean Gadberry
// COSC 2425 0400
// ps1s1p2
// References:
        // https://en.wikipedia.org/wiki/Two%27s_complement
        // https://www.cuemath.com/numbers/decimal-to-binary/
        // https://stackoverflow.com/questions/8468597/prepend-stdstring
        // https://stackoverflow.com/questions/22746429/c-decimal-to-binary-converting
#include <iostream>
#include <string>

void runAgain();
void promptUser();
void checkValue();
void printBinary();
std::string positiveToBinary(int);
std::string negativeConvert(std::string);
char invert(std::string, int);

int run = 0, value; 
std::string output;

int main() 
{
    do {
        promptUser();
        printBinary();
        runAgain();
    } while (run == 1);
    return 0;
}

void promptUser()
{
    std::cout
        <<std::endl
        <<"Enter a value: ";
    std::cin
        >>value;
    std::cout
        <<std::endl;
    checkValue();
}

void checkValue()
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

char invert(std::string str, int i)
{
    char c;
    if (str[i] == '0')
        c = '1';
    else
        c = '0';
    return c;
}

std::string negativeConvert(std::string str)
{
    //std::cout<<"ptb "<<str<<std::endl;
    int index = 7;
    bool complete = 0;
    for (int i = 0; i < 8; i++)
    {
        str[i] = invert(str, i);
    };
    //std::cout<<"inverted "<<str<<std::endl;
    for (int i = 7; i >= 0; i--)
    {
        if (str[i] == '0')
        {
            //std::cout<<"last was 0\n";
            str[i] = invert(str, i);
            return str;
        }
        //std::cout<<"last was 1\n";
        str[i] = invert(str, i);
    };
    /*
    while (complete != 1)
    {
        if (str[index] == '0')
        {
            str[index] = invert(str, index);
            complete = 1;
        }
        else
            str[index] = invert(str, index);
            index--;
    };
    */
}

void printBinary()
{
        std::cout
            <<value
            <<" = "
            <<output
            <<std::endl;
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
