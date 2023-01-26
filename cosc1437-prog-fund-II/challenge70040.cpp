// Challenge 70040

#include <iostream>
#include <iomanip>

class Payroll {
    private:
        double rate;
        double hrs;
    public:
        Payroll() {
            hrs = 0.0;
            rate = 0.0; }
        void setRate(double r) {
            rate = r; }
        void setHours(double h) {
            if (h>60)
                hrs = 60;
            else
                hrs = h; }
        double getHours() {
            return(hrs); }
        double getRate() {
            return(rate); }
        double getGross() {
            double gross = rate * hrs;
            return(gross); }
};

int main() {
    // set precision to 2 digits
    double number;
    std::cout
        <<"Creating 7 Payroll objects.\n";
    Payroll pay[7];
    for (int i = 0; i < 7; i++) {
        std::cout
            <<"Enter the # "
            <<i
            <<" employee's rate of pay per hour:";
        std::cin>>number;
        pay[i].setRate(number);
        std::cout
            <<"Enter the # "
            <<i
            <<" employee's hours worked for the week:";
        std::cin>>number;
        pay[i].setHours(number);
    }
    std::cout<<"\n\n"<<std::setprecision(2)<<std::showpoint<<std::fixed;
    for (int i = 0; i < 7; i++) {
        std::cout
            <<"Employee # "
            <<i
            <<" worked "
            <<pay[i].getHours()
            <<" hours at $"
            <<pay[i].getRate()
            <<"for a gross pay of $"
            <<pay[i].getGross()
            <<std::endl;
    }

return(0); }


/*
↵
↵
Employee·#·0·worked·22.00·hours·at·$12.22·for·a·gross·pay·of·$268.84↵
Employee·#·1·worked·36.00·hours·at·$99.99·for·a·gross·pay·of·$3599.64↵
Employee·#·2·worked·20.00·hours·at·$45.67·for·a·gross·pay·of·$913.40↵
Employee·#·3·worked·0.00·hours·at·$56.78·for·a·gross·pay·of·$0.00↵
Employee·#·4·worked·5.00·hours·at·$40.45·for·a·gross·pay·of·$202.25↵
Employee·#·5·worked·60.00·hours·at·$30.35·for·a·gross·pay·of·$1821.00↵
Employee·#·6·worked·45.00·hours·at·$30.33·for·a·gross·pay·of·$1364.85↵11. 

Payroll

Creating·7·Payroll·objects.↵
Enter·the·#·0·employee's·rate·of·pay·per·hour:12.22↵
Enter·the·#·0·employee's·hours·worked·for·the·week:22↵
Enter·the·#·1·employee's·rate·of·pay·per·hour:99.99↵
Enter·the·#·1·employee's·hours·worked·for·the·week:36↵
Enter·the·#·2·employee's·rate·of·pay·per·hour:45.67↵
Enter·the·#·2·employee's·hours·worked·for·the·week:20↵
Enter·the·#·3·employee's·rate·of·pay·per·hour:56.78↵
Enter·the·#·3·employee's·hours·worked·for·the·week:0↵
Enter·the·#·4·employee's·rate·of·pay·per·hour:40.45↵
Enter·the·#·4·employee's·hours·worked·for·the·week:5↵
Enter·the·#·5·employee's·rate·of·pay·per·hour:30.35↵
Enter·the·#·5·employee's·hours·worked·for·the·week:80↵
Enter·the·#·6·employee's·rate·of·pay·per·hour:30.33↵
Enter·the·#·6·employee's·hours·worked·for·the·week:45↵
Design a PayRoll class that has data members for an employee’s hourly pay rate, number of hours worked of type double. 
The default constructor will set the hours worked and pay rate to zero. 
The class must have a mutator function to set the pay rate for each employee and hours worked. 
The class should include accessors for both the hours worked and the rate of pay. 
The class should lastly have a getGross function that will return a double calculated by multiplying the hours worked by the rate
Write a program with an array of seven PayRoll objects. 
The program should ask the user for the rate of pay for each employee and the number of hours each employee has worked. 
Be sure to include an employee claiming to work more then 60 hours per week. 
Print out, the array number of the employee, the hours worked, the rate of pay, and the gross pay, of all the employee's each on their own line. 
Set the precision for printing the doubles to two decimal places.
Input Validation: Do not accept values greater than 60 for the number of hours worked, simply have the set function set number of hours worked to 60, the maximum allowed.
---------------------------------------Original Question-----------------------------------------------------------------
11. Payroll

Design a PayRoll class that has data members for an employee’s hourly pay rate, number of hours worked, and total pay for the week. Write a program with an array of seven PayRoll objects. The program should ask the user for the number of hours each employee has worked and will then display the amount of gross pay each has earned.

Input Validation: Do not accept values greater than 60 for the number of hours worked.

*/
