/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// royalOrderDG.cpp
// Dean Gadberry
// COSC 2436 0400
// Make Up Set, Problem 4
// References:
    // https://www.youtube.com/watch?v=ybFCmm8jKwQ
    // https://stackoverflow.com/questions/4092582/displaying-an-error-message-if-a-file-cant-be-opened-c
    // https://stackoverflow.com/questions/9438209/for-every-character-in-string

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct Person {
    std::string name;
    int birth_year;
    std::vector<Person*> daughters;
};

void parse_line(std::string line, std::map<std::string, Person*>& people_map);
void visit(Person* person, std::vector<std::string>& succession_order);

int main() 
{
    std::string filename;
    std::cout 
        <<"Enter file name: ";
    std::cin 
        >>filename;
    std::ifstream input_file(filename);
    if (!input_file.is_open()) 
    {
        std::cerr 
            <<"Error: could not open file " 
            <<filename 
            <<std::endl;
        return 1;
    }
    std::string queen_line;
    getline(input_file, queen_line);
    std::map<std::string, Person*> people_map;
    parse_line(queen_line, people_map);
    std::string line;
    while (getline(input_file, line)) 
    {
        parse_line(line, people_map);
    }
    input_file.close();
    Person* queen = people_map[queen_line.substr(0, queen_line.find(' '))];
    std::vector<std::string> succession_order;
    visit(queen, succession_order);
    sort(succession_order.begin(), succession_order.end());
    std::cout 
        <<std::endl
        <<"Succession Order:"
        <<std::endl
        <<std::endl;
    for (std::string name : succession_order) 
    {
        bool all_digits = true;
        for (char& c : name) 
        {
            if (!isdigit(c)) 
            {
                all_digits = false;
                break;
            }
        }
        if (all_digits)
            continue;
        std::cout 
            <<name 
            <<std::endl;
    }
    return 0;
}

void parse_line(std::string line, std::map<std::string, Person*>& people_map) 
{
    std::istringstream iss(line);
    std::string mother_name, daughter_name;
    int birth_year;
    iss 
        >>mother_name 
        >>daughter_name 
        >>birth_year;
    Person* mother = people_map[mother_name];
    if (mother == nullptr) 
    {
        mother = new Person{mother_name, -1, {}};
        people_map[mother_name] = mother;
    }
    Person* daughter = new Person{daughter_name, birth_year, {}};
    mother->daughters.push_back(daughter);
    people_map[daughter_name] = daughter;
}

void visit(Person* person, std::vector<std::string>& succession_order) 
{
    if (person != nullptr) 
    {
        succession_order.push_back(person->name);
        for (Person* daughter : person->daughters) 
        {
            visit(daughter, succession_order);
        }
    }
}
