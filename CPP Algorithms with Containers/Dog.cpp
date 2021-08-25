//
// Created by Yun Ni on 2021-08-08.
//

#include "Dog.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <map>
#include <utility>
#include <algorithm>
#include <iterator>

using std::string;
using std::size_t;
using std::cin;
using std::cout;
using std::endl;


std::ostream &operator<<(std::ostream &sout, const Dog &dog) {
    sout << dog.name << "," << dog.breed << "," << dog.age << "," << dog.gender;
    return sout;
}

std::istream& operator>>(std::istream& sin, Dog& d) {
    bool ok = false;
    if (std::getline(sin, d.name, ',')) {trim(d.name);
        if (std::getline(sin, d.breed, ',')) {trim(d.breed);
            if (std::getline(sin, d.age, ',')) {trim(d.age);
                if (std::getline(sin, d.gender)) {trim(d.gender);
                    ok = true;
                }
            }
        }
    }
    if (!ok && !sin.eof()) {
        throw std::runtime_error("Invalid input line ");
    }
    return sin;
}



//-----------------------task 1
void trim(std::string& str)
{
    // trim leading and trailing whitespaces in str
    std::string whitespaces(" \t\f\v\n\r");

    //Erase the found leading whitespaces
    size_t found_leading = str.find_first_not_of(whitespaces);
    if (found_leading == std::string::npos)
    {
        str = "";
    } else{
        str = str.substr(found_leading);
    }

    //Erase the found trailing whitespaces
    size_t found_trailing = str.find_last_not_of(whitespaces);
    if (found_trailing == std::string::npos){
        str = "";
    }
    else{
        str = str.substr(0, found_trailing + 1);
    }

    return;

 }

//-----------------------task 1
void load_DogMap(DogMap& dog_map, std::string cvsfilename)
{
    std::ifstream my_file_stream(cvsfilename); // Create an input file stream
    if (!my_file_stream.is_open()) {
        cout << "Could not open file " + cvsfilename << endl;
        throw std::runtime_error("Could not open file " + cvsfilename);
    }

    std::string line;
    while (std::getline(my_file_stream, line)) { // read a line
        std::stringstream my_line_stream(line); // turn the line into a string stream
        Dog dog{}; // create a Dog object, and
        my_line_stream >> dog; // initialize it using Dog's extraction operator>>
        dog_map.emplace(dog.getBreed(), dog); // insert dog into dog_map
    }
    my_file_stream.close(); // close the file stream
}

//-----------------------task 2

void load_DogMap_Using_For_Each(DogMap& dog_map, std::string cvsfilename)
{
    std::ifstream input_file_stream(cvsfilename); // Create an input file stream

    if (!input_file_stream.is_open()) { // Check that the file is open
        cout << "Could not open file " + cvsfilename << endl;
        throw std::runtime_error("Could not open file " + cvsfilename);
    }

    // Get input stream and end of stream iterators
    std::istream_iterator<Dog> input_stream_begin{ input_file_stream };
    std::istream_iterator<Dog> input_stream_end{};

   // Copy Dog elements from [input_stream_begin, input_stream_end)
   // to dog_map using for_each function
   // fill in the blank
    std::for_each(input_stream_begin,input_stream_end,
                  [& dog_map] (const Dog &dog){return dog_map.emplace(dog.getBreed(), dog);});

    input_file_stream.close(); // close the file stream
    return;
}

//-----------------------task 3

void load_DogMap_Using_Transform(DogMap& dog_map, std::string cvsfilename)
{
    std::ifstream input_file_stream(cvsfilename); // Create an input file stream

    if (!input_file_stream.is_open()) { // Check that the file is open
        cout << "Could not open file " + cvsfilename << endl;
        throw std::runtime_error("Could not open file " + cvsfilename);
    }

    // Get input stream and end of stream iterators
    std::istream_iterator<Dog> input_stream_begin{ input_file_stream };
    std::istream_iterator<Dog> input_stream_end{};

    // Copy Dog elements from [input_stream_begin, input_stream_end)
    // to dog_map using std::transform
    // fill in the blank
    std::transform(input_stream_begin,input_stream_end,std::inserter(dog_map, dog_map.begin()),
                   [] (const Dog &dog){return std::pair <std::string, Dog>(dog.getBreed(), dog);});

    input_file_stream.close(); // close the file stream
    return;
}

//-----------------------task 4
void load_DogMap_Reversed_Order(DogMapReversed& dog_map, std::string cvsfilename)
{
    std::ifstream my_file_stream(cvsfilename); // Create an input file stream
    if (!my_file_stream.is_open()) {
        cout << "Could not open file " + cvsfilename << endl;
        throw std::runtime_error("Could not open file " + cvsfilename);
    }

    std::string line;
    while (std::getline(my_file_stream, line)) { // read a line
        std::stringstream my_line_stream(line); // turn the line into a string stream
        Dog dog{}; // create a Dog object, and
        my_line_stream >> dog; // initialize it using Dog's extraction operator>>
        dog_map.emplace(dog.getBreed(), dog); // insert dog into dog_map
    }
    my_file_stream.close(); // close the file stream
}

//-----------------------task 4
std::ostream& operator<<(std::ostream& sout, const DogMapReversed& dogmap)
{
    for (DogMapReversed::const_iterator it = dogmap.begin(); it != dogmap.end(); it++) {
        std::cout << std::setw(25) << it->first << " --> " << it->second << std::endl;
    }
    return sout;
}


//Insert --> operators for dogmaps:  //task 1
std::ostream& operator<<(std::ostream& sout, const DogMap& dogmap) {
    for (DogMap::const_iterator it = dogmap.begin(); it != dogmap.end(); it++) {
        std::cout << std::setw(25) << it->first << " --> " << it->second << std::endl;
    }
    return sout;
}

// -----------------------task 5
DogMap findBreedRange(const DogMap & source, std::string key_breed)
{
    trim(key_breed);

    DogMap results{};

    auto target = source.multimap::equal_range(key_breed);

    for (auto it = target.first; it!= target.second; it++) {
        results.emplace(it->first, it->second);
    }

    return results;

}