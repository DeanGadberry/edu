#include <iostream> /*for input & output stream */
#include <iomanip> /* for using precision and fixed */
using namespace std;
/* PayRoll Class*/
class payRoll
{
	/* attributes and methods */
	private:
	    int workedHours;
	    double rateofpay;
	public:
	    payRoll ();
	    payRoll (int, double);
	    void setmyHours (int) ;
	    void setrateofpay(double);
	    int getmyHours () const;
	    double getrateofpay() const;
	    double getmyGross () const;
};
/*constructor with no arguments */
payRoll::payRoll()
{
	workedHours = 0;
	rateofpay = 0.0;
}
/* constructor */
payRoll::payRoll (int hrs, double rop)
{
	rateofpay = rop;
	workedHours = hrs;
}
/* set method for hours worked */
void payRoll::setmyHours (int hrs)
{
	workedHours = hrs;
}
/* set method for rate of pay */
void payRoll::setrateofpay (double srop)
{
	rateofpay = srop;
}
/* get method for hours worked */
int payRoll::getmyHours () const
{
	return workedHours;
}
/* get method for rate of pay */
double payRoll::getrateofpay() const
{
	return rateofpay;
}
/* get method for grosspay */
double payRoll::getmyGross() const
{
	double myGross = static_cast<double> (workedHours)* rateofpay;
	return myGross;
}

/* main method */
int main()
{
	/* variable declarations */
	const int NoOfEmployee = 7;
	payRoll emp[NoOfEmployee];
	double myrop;
	int myhrs;
	int a;
	double mygrossPay;
	cout<<endl<<"Creating 7 Payroll objects"<<endl;
	/* loop to get the employees details */

	
	for ( a = 0; a < NoOfEmployee; a++)
	{	
		cout << "Enter the # " << (a) << " employee's rate of pay per hour : ";
		cin >> myrop;
		cout << "Enter the # " << (a) << " employee's hours worked for the week: ";
		cin >> myhrs;
		emp[a].setrateofpay(myrop) ;
		emp[a].setmyHours (myhrs) ;
}
/* output */
cout << "\n\nGrossPay for every employee:\n";
cout << fixed << showpoint << setprecision (2) ;
    for (int i = 0; i < 7; i++) {
        cout <<"employee # " <<i <<" worked " <<emp[i].getmyHours() <<" hours at $" <<emp[i].getrateofpay() <<"for a gross pay of $" <<emp[i].getmyGross() <<endl;
    }

return 0;
}
