// chapter 14 notes
/*

STATIC
    A static variable is accessible by all instances of a class. 
    A static function may be caled without any instances.

Static vmember functions do not operate on instance variables. 
Instead, they can operate only on static member variables. 

*/
// External Definition of static variable required
int Tree::objectCount = 0;
/*

Static Member Variables and Functions are defined outside of the class definition.

Static Member functions called with the scope resolution operator
   */
Budget::mainOffice(amount);
/*
    
   friend function has access to a class' private members

Memberwise assignment (when an object is copied to another object (this changes all of the private variables at once)

A copy constructor is a constructor with the same name as the class, which accepts an instance of the class as an argument. 
After a copy constructor is defined, the = operator can be used, and the copy constructor will be called.
    The copy constructor is especially useful for arrays (to be sure to not have two class instances which point to the same memory address for a given array.)
    Best to use const when defining a copy constructor's parameter list, because you do not want to change the data of the instance being copied. 
    */
StudentTestScores(const StudentTestScores &obj)
    /*

Overload operators
Operator functions allow you to redefine how an operator works with an object.
*/
void operator = (const studentTestScores &right)
    /*
"this" is a pointer that references the object which calls it

only operators that can not be overloaded in c++ are
    ?: . .* :: sizeof


   */
Pet Pet::operator = (const Pet &right);
dog = cat.operator=();
//use of a dummy parameter in a function indicates that the overloaded operator is a postfix operator
/*

