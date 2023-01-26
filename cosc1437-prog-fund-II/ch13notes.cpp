// Chapter 13 notes

/*

Object oriented programming 

Object instead of procedure/function

    Parent->Object
    Child->Attributes ( Data )
    Child->Member Functions

Encapsulation 
    combining of data and code into a single object
Data Hiding 
    object's ability to hide data from code outside object

Class defines attributes and functions of object
Each object created is an instance of the class

Members are private by default

see::   */
double getWidth() const;
/*
const denotes that no data will be changed by this function.

Scope resolution operator  {{::}}
*/
double Rectangle::setwidth(double w);
    /*
Accessor (getter)
    member function that returns the value of a class' member variable but does not change it

Mutator (setter)
    changes the value of a class' member variable

instantiation
   */
className objectName;
/*

!!GARBAGE!!
    the value in memory at the time of instantiation ( random )

see pointers to objects: and dynamic allocation with it:
*/
Object *ptr;

ptr = new Object;

Object->func(10.0);
Object->func2(30.1);

delete ptr;
ptr = nullptr;
/*
   RAD!

Stale data is things like the multiplication of two variables stored in a variable. Better to do the operation when you are ready to serve the data.

uniqueptr requires <memory> header

#include "rectangle.h"
    use double quotes to include a file in your project folder

specification files need a preprocessor directive called a include guard to make sure that it is not included twice.

#ifndef RECTANGLE_H
#define RECTANGLE_H
entire file with class declaration;
#endif

then the .cpp file is made which includes this file. that's where the functions are created (their prototypes are in the specification file.

specification.h
implementation.cpp
    implementation.cpp is compiled into implementation.obj
    the code you write is compiled into file.obj.
    the two files are linked into an executable.

    inline funciton is defined int he declaration of a class

Constructor!!
    member function with same name as class...
        automatically called when object is created. 
    good for initialize variables

    Defaults can be defined in the function, and then you must use the default, but if the defaults are in the parameters, then one can put in their own initialization parameters. 

Destructors!!
    same name as class, prepend with ~
    called when an object is destroyed
    
*/




class Classname
{
    private:
        // declaration;
        // ... more declarations
    public:
        // declaration;
        // ... more declarations
};


