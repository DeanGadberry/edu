// Challenge 70038

#include <iostream>

class Circle
{
	private:
		double radius;
		double pi = 3.14159;
	public:
	Circle(double rad = 0.0){
		radius = rad; }
	void setRadius(double rad) {
		radius = rad; }
	double getRadius() const {
		return(radius); }
	double getArea() const {
        double area = pi * radius * radius;
        return(area); }
    double getDiameter() const {
        double diam = radius * 2;
        return(diam); }
    double getCircumference() const {
        double circ = 2 * pi * radius; 
        return(circ); }
};

int main() {
    std::cout
        <<"Calling default constructor: "
        <<std::endl;
    Circle cir;
    std::cout
        <<"The circle's radius in the default Circle Object is: "
        <<cir.getRadius()
        <<std::endl
        <<std::endl;
    std::cout
        <<"Calling setRadius(20) to change radius of default:\n"
        <<"The circle's radius in the default Circle Object is Now: "
        <<std::endl
        <<std::endl;
        cir.setRadius(20);
    std::cout
        <<"Creating Circle circle2(10): \n";
    Circle cir2(10);
    std::cout
        <<"The circle2's radius in the circle2 Object is: "
        <<cir2.getRadius()
        <<std::endl
        <<std::endl;
    std::cout
        <<"The circle2's area is therefore: "
        <<cir2.getArea()
        <<std::endl
        <<"The circle2's diameter is therefore: "
        <<cir2.getDiameter()
        <<std::endl
        <<"The circle2's circumference is therefore: "
        <<cir2.getCircumference()
        <<std::endl;

return(0);}
/*

Calling·default·constructor:·The·circle's·radius·in·the·default·Circle·Object·is:·0↵
↵
Calling·setRadius(20)·to·change·radius·of·default:↵
The·circle's·radius·in·the·default·Circle·Object·is·Now:·20↵
↵
Creating·Circle·circle2(10):·↵
The·circle2's·radius·in·the·circle2·Object·is:·10↵
↵
The·circle2's·area·is·therefore:·314.159↵
The·circle2's·diameter·is·therefore:·20↵
The·circle2's·circumference·is·therefore:·62.8318↵

 Default Constructor. A default constructor that sets radius to 0.0.
• Constructor. Accepts the radius of the circle as an argument.
• setRadius. A mutator function for the radius variable.
• getRadius. An accessor function for the radius variable.
• getArea. Returns the area of the circle, which is calculated as area = pi * radius * radius
• getDiameter. Returns the diameter of the circle, which is calculated as diameter = radius * 2
• getCircumference. Returns the circumference of the circle, which is calculated as circumference = 2 * pi * radius
	
	Write a program that demonstrates the Circle class by asking the user for the circle’s radius, creating a Circle object, and then reporting the circle’s area, diameter, and circumference.

*/
