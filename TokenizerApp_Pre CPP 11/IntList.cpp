#include "IntList.h"
#include<iostream>
#include<cassert>
using std::cout;
using std::endl;
using std::cin;


//Default Constructor, a list of capacity 1, and used=0
IntList::IntList() {
    used = 0;
    capacity = 0;
    dynarray = new int[capacity];
}

//Copy constructor
IntList::IntList(const IntList& array){
    used = array.used;
    capacity = array.capacity;
    dynarray = new int[array.capacity];

    //cout<<"copy constructor"<<endl;
    for (int i = 0; i < used; i++)
        dynarray[i] = array.dynarray[i];
}

//Move constructor
IntList::IntList(IntList&& array){

    //cout<<"Move constructor"<<endl;

    used = array.used;
    capacity = array.capacity;
    dynarray = array.dynarray;

    array.used = 0;
    array.capacity = 0;
    array.dynarray = nullptr;
}

// copy assignment for cout to work obj
IntList& IntList::operator=(const IntList & rhs){
    if(this != &rhs){
        delete [] this -> dynarray;
        used = rhs.used;
        capacity = rhs.capacity;
        dynarray = new int[capacity];

        //cout<<"copy assignment"<<endl;

        for (size_t i{}; i < used; ++i) {
            dynarray[i] = rhs.dynarray[i];
        }
    }
    return *this;
}

//Move assignment operator
IntList& IntList::operator=(IntList&& rhs){

    //cout<<"Move assignment"<<endl;

    if(this != &rhs){
        delete [] this -> dynarray;
        used = rhs.used;
        capacity = rhs.capacity;
        dynarray = rhs.dynarray;

        rhs.dynarray = nullptr;
        rhs.capacity = 0;
        rhs.used = 0;
    }
    return *this;

}

//Destructor (and a virtual one in this example)
IntList::~IntList(){
    if(dynarray != nullptr){
        delete [] dynarray;
        capacity = 0;
        used = 0;
    }
}

//Double the current capacity of the list
//and copy the original array to an new resized array

void IntList::resize(){
    if(capacity == 0)
        capacity = 1;
    else if( used == capacity)
        capacity *= 2;

    int * temp = new int[capacity];
    for (size_t i{}; i < used; ++i) {
        temp[i] = dynarray[i];
    }

    delete[] dynarray;
    dynarray = temp;
}

//Determines whether used equals zero
bool IntList::empty(){
    if( used == 0 )
        return true;
    else
        return false;
}

//Determines whether used equals capacity
bool IntList::full(){
    if( used == capacity)
        return true;
    else
        return false;
}

//Returns used size
int IntList::size(){
    return used;
}

//Inserts x after the current last element in the list
void IntList::pushback(int x){
    if(used >= capacity){
        resize();
    }
    dynarray[used] = x;
    used++;

}

//Determines whether x occurs in the list
bool IntList::contains(int x){
    for(int i = 0; i < used; ++i){
        if( x == dynarray[i])
            return true;
    }
    return false;
}

bool IntList::get(int position, int& value) const{
    if(position >= capacity)
        return false;
    else
        value = dynarray[position];
        return true;

}

//Return the allocated capacity of this list
int IntList::getCapacity(){
    return capacity;
}

void IntList::print(ostream& sout){
    for(int i = 0; i < used; i++){
        sout << dynarray[i] << " ";
    }
}