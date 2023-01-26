#include <iostream>
#include <string>
    
//using namespace std;

class Numbers{

    private:
        int number;
        static std::string teen[20];
        static std::string hundred;
        static std::string thousand;
        static std::string tens[8];
    
    public:
    
    Numbers(int num)
    {
        if (num < 0 && num>9999)
            {
                std::cout << "Error! Number is not in the range(0 - 9999)...(Please Try again)!!\n";
                exit(0);
            }
        else
            number = num;
    }
    
    
    
    void print()
    {
        do
        {
            if (number/1000 > 0)
            {
                std::cout << teen[number/1000] << " " << thousand << " ";
                number = number % 1000;
            }
            
            else if (number/100 > 0)
            {
                std::cout << teen[number/100] << " " << hundred << " ";
                number = number % 100;
            }
        
            else if (number >= 20)
            {
                std::cout << tens[(number/10)-2] << " ";
                number = number % 10;
            }
            
            else
            {
                std::cout << teen[number];
                break;
            }

        } while (number > 0);
        std::cout << "\n";
    }
};


std::string Numbers::teen[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
std::string Numbers::hundred = "hundred";
std::string Numbers::thousand = "thousand";
std::string Numbers::tens[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {

int inputNumber;
std::cout << "Enter an integer:";
std::cin >> inputNumber;

Numbers num(inputNumber);

num.print();

return 0; }
