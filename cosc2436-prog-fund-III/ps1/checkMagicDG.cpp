// checkMagicDG.cpp
// Dean Gadberry
// COSC 2436 0400
// ps1p1
// References:

#include <iostream>
#include <string>

bool checkSum(int, int, int);
void runAgain(char);

bool run = 1, r1,r2,r3,c1,c2,c3,d1,d2;
int arr[9], arrayIterator=0; 
char yes_or_no;
std::string magicSquare, missingSums;

int main() {
    do {
        std::cout
            <<"Enter the 3 by 3 magic square: ";

        for (int i=0; i<9; i++)
        {
            std::cin
                >>arr[i];
        };
        

        int n1=arr[0],n2=arr[1],n3=arr[2],
            n4=arr[3],n5=arr[4],n6=arr[5],
            n7=arr[6],n8=arr[7],n9=arr[8];

        std::cout
            <<"Magic Square:\n"
            <<n1<<" "<<n2<<" "<<n3<<"\n"
            <<n4<<" "<<n5<<" "<<n6<<"\n"
            <<n7<<" "<<n8<<" "<<n9<<"\n";

        std::cout
            <<"Missing:  ";
        if (!checkSum(n1,n2,n3))
        {   std::cout <<"R1 ";};
        if (!checkSum(n4,n5,n6))
        {std::cout <<"R2 ";};
        if (!checkSum(n7,n8,n9))
        {std::cout <<"R3 ";};
        if (!checkSum(n1,n4,n7))
        {std::cout <<"C1 ";};
        if (!checkSum(n2,n5,n8))
        {std::cout <<"C2 ";};
        if (!checkSum(n3,n6,n9))
        {std::cout <<"C3 ";};
        if (!checkSum(n1,n5,n9))
        {std::cout <<"D1 ";};
        if (!checkSum(n3,n5,n7))
        {std::cout <<"D2 ";};

        runAgain(yes_or_no);

    } while (run == 1);

    return 0;
}

bool checkSum(int a, int b, int c)
{
    bool whetherTrue = 0;
    int sum = a + b + c;
    if (sum == 15)
    {
        whetherTrue = 1;
    }

    return whetherTrue;
}

void runAgain(char c)
{

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
            break;
        default:
            runAgain(c);       
    };
}

