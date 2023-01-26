#include <iostream>

using namespace std;

const double PI = 3.14159;

// class interface (definition)
class Circle 
{
public:
// constructors
Circle(); // default constructor
Circle(double r); // copy constructor
void SetRadius(double r); // modifier that sets new radius
double Radius();
double Area();
double Circumference();
double Diameter();

private:
// member variables (data)
double radius; // circle's radius
};

int main() {
    cout <<"Calling default constructor: " <<endl;
    Circle circle;
    cout <<"The circle's radius in the default Circle Object is: " <<circle.Radius() <<endl <<endl;
    circle.SetRadius(20);
    cout <<"Calling setRadius(20) to change radius of default:" <<endl <<"The circle's radius in the default Circle Object is Now: " <<circle.Radius() <<endl <<endl;
    cout <<"Creating Circle circle2(10): " <<endl;
    Circle circle2(10);
    cout <<"The circle2's radius in the circle2 Object is: " <<circle2.Radius() <<endl <<endl;
    cout <<"The circle2's area is therefore: " <<circle2.Area() <<endl <<"The circle2's diameter is therefore: " <<circle2.Diameter() <<endl <<"The circle2's circumference is therefore: " <<circle2.Circumference() <<endl;

    return(0);
}
// class implementation

// default constructor
Circle::Circle()
{
radius = 0.0;
}

// copy constructor
Circle::Circle(double r)
{
radius = r;
}

// sets the radius of the circle
void Circle::SetRadius(double r)
{
radius = r;
}

// computes the area of the circle
double Circle::Area()
{
return(radius * radius * PI);
}
// 
double Circle::Circumference()
{
return(radius * 2 * PI);
}

// returns radius
double Circle::Radius()
{
return(radius);
}

// find diameter
double Circle::Diameter()
{
return(radius*2);
}
