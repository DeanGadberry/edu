#include <iostream>
#include <string>
using namespace std;

class Numbers{

private:
int number;
static string lessThan20[20];
static string hundred;
static string thousand;
static string tens[8];

public:

Numbers(int num)
{
if(num < 0 && num>9999)
{
cout << "Error! Number is not in the range(0 - 9999)..(Please Try again)!!\n";
exit(0);
}
else
number = num;
}



void print(){

do
{
if(number/1000 > 0){
cout << lessThan20[number/1000] << " " << thousand << " ";

number = number % 1000;
}

else if(number/100 > 0)
{
cout << lessThan20[number/100] << " " << hundred << " ";

number = number % 100;
}

else if(number >= 20)
{
cout << tens[(number/10)-2] << " ";
number = number % 10;
}

else
{
cout << lessThan20[number];
break;
}
}
while (number > 0);
cout << "\n";
}
};


string Numbers::lessThan20[20] = {"zero", "one", "two", "three", "four",
"five", "six", "seven", "eight", "nine",
"ten", "eleven", "twelve", "thirteen", "fourteen",
"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";
string Numbers::tens[8] = {"twenty", "thirty", "forty", "fifty", "sixty",
"seventy", "eighty", "ninety"};

int main()
{
int inputNumber;
cout << "Enter an integer:";
cin >> inputNumber;

Numbers num(inputNumber);

num.print();

return 0;
}
