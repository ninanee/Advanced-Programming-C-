//
// Created by Yun Ni on 2021-08-08.
//

#ifndef INC_5421A5_DOG_H
#define INC_5421A5_DOG_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <functional>


using std::string;

class Dog {
    string name;
    string breed;
    string age;
    string gender;
public:
    Dog() = default;
    virtual ~Dog() = default;
    Dog(const Dog&) = default;
    Dog(Dog&&) = default;
    Dog& operator=(const Dog&) = default;
    Dog& operator=(Dog&&) = default;

    Dog(string n, string b, string a, string g) :
     name(n), breed(b), age(a), gender(g) { }

    // accessors
    string getBreed() const { return breed; }
    string getName() const { return name; }
    string getAge() const { return age; }
    string getGender() const { return gender; }

    // mutators
    void setBreed(string breed) { this->breed = breed; }
    void setName(string name) { this->name = name; }
    void setAge(string age) { this->age = age; }
    void setGender(string gender){ this->gender = gender; }

    friend std::ostream& operator<<(std::ostream&, const Dog&); // done
    friend std::istream& operator>>(std::istream&, Dog&); // done

};

//task 1
void trim(string& str); // on your to-do list
using DogMap = std::multimap<std::string, Dog>; // Key type is std::string, mapped type is Dog

void load_DogMap(DogMap& dog_map, std::string cvsfilename);
//Insert --> operators for dogmaps
//task 1
std::ostream& operator<<(std::ostream& sout, const DogMap& dogmap);

//task 2
void load_DogMap_Using_For_Each(DogMap& dog_map, std::string cvsfilename);

//task 3
void load_DogMap_Using_Transform(DogMap& dog_map, std::string cvsfilename);

//task 4
using DogMapReversed = std::multimap<std::string, Dog, std::greater<std::string>>;
void load_DogMap_Reversed_Order(DogMapReversed& dog_map, std::string cvsfilename);

//Insert --> operators for dogmaps
//task 4
std::ostream& operator<<(std::ostream& sout, const DogMapReversed& dogmap);

//task 5
using DogMap = std::multimap<std::string, Dog>;
DogMap findBreedRange(const DogMap& source, std::string key_breed);
#endif //INC_5421A5_DOG_H
