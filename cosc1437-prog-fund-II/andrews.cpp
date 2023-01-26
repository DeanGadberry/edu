#include <iostream>

using namespace std;

class circle
{
private:
double radius;
double pi=3.14159;
 
public:
circle() { radius=0.0; }
 
circle(double r) { setRadius(r); }
 
void setRadius(double r) { radius=r; }
 
double getRadius() { return radius; }

double getArea() { return (pi*radius*radius); }
 
double getDiameter() { return (radius*2); }
 
double getCircumference() { return (2*pi*radius); }

};

int main()
{
circle defaultCircle;
cout << "Calling default constructor: The circle's radius in the default Circle Object is: ";
cout << defaultCircle.getRadius() << endl << endl;

cout << "Calling setRadius(20) to change radius of default: " << endl;
defaultCircle.setRadius(20);
cout << "The circle's radius in the default Circle Object is Now: " << defaultCircle.getRadius() << endl << endl;

cout << "Creating Circle circle2(10): " << endl;
cout << "The circle2's radius in the circle2 Object is: ";
circle circle2(10);
cout << circle2.getRadius() << endl << endl;
cout << "The circle2's area is therefore: " << circle2.getArea() << endl;
cout << "The circle2's diameter is therefore: " << circle2.getDiameter() << endl;
cout << "The circle2's circumference is therefore: " << circle2.getCircumference() << endl;


system("pause");
return 0;
}
