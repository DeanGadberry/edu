// programming challenge #24 PROMPT:
// Write a program that plays a word game with the user. 
// The program should ask the user to enter the following:
// • His or her name
// • His or her age
// • The name of a city
// • The name of a college
// • A profession
// • A type of animal
// • A pet’s name
// After the user has entered these items, 
// the program should display the following story, 
// inserting the user’s input into the appropriate locations:
// There once was a person named NAME who lived in CITY. At the age of AGE, NAME went to college at COLLEGE. NAME graduated and went to work as a PROFESSION. Then, NAME adopted a(n) ANIMAL named PETNAME. They both lived happily ever after!
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    string name, age, city, college, profession, animal, pet;
    
    cout << "Let's play a game." << endl
        << "Name: ";
    getline(cin, name);
    cout << "Age: ";
    getline(cin, age);
    cout << "Name of a City: ";
    getline(cin, city);
    cout << "Name of a College: ";
    getline(cin, college);
    cout << "Profession: ";
    getline(cin, profession);
    cout << "Type of Animal: ";
    getline(cin, animal);
    cout << "Pet-Name: ";
    getline(cin, pet);
    cout << endl << "There once was a person named "
        << name << " who lived in "
        << city << ". At the age of "
        << endl
        << age << ", "
        << name << " went to college at "
        << college << ". "
        << name << " graduated and went to work \nas a "
        << profession << ". Then, "
        << name << " adopted a(n) "
        << animal << " named "
        << pet << ". They \nboth lived happily ever after!"
        << endl;
    return 0;
}

