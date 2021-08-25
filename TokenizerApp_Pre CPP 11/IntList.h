#ifndef ASG1_INTLIST_H
#define ASG1_INTLIST_H
#include <ostream>
#include <iostream>
#include <fstream>
using std::ostream;

class IntList{
private:
    int* dynarray;                     //Pointer to a dynamically allocated array of integers
    int capacity;                      //Allocated capacity of the array above, starting at 1 and doubling the capacity when needed.
    int used;                          //Number of elements currently stored in the array

public:
    IntList();                           //Default Constructor, a list of capacity 1, and used=0

    // The "Big Five" ---------------------------------------------------
    IntList(const IntList& array);                 //Copy constructor
    IntList(IntList&& array);                      //Move constructor
    virtual ~IntList ();                           //Destructor (and a virtual one in this example)
    IntList& operator=(const IntList& rhs);        // copy assignment for cout to work
    IntList& operator=(IntList&& rhs);              //Move assignment operator
    // -------------------------------------------------------------------

    void resize();                     //Double the current capacity of the list
    bool empty() ;                           //Determines whether used equals zero
    bool full() ;                            //Determines whether used equals capacity
    int size();                             //Returns used size
    void pushback(int x);                         //Inserts x after the current last element in the list
    bool contains(int x);                         //Determines whether x occurs in the list
    bool get(int position, int& value) const;
    int getCapacity();                      //Return the allocated capacity of this list
    void print(ostream& sout);                  // Prints the numbers in the list to the sout stream, separating them by a comma followed by a space

    friend ostream& operator<<(std::ostream& os, const IntList& rhs){
        for(int i = 0; i < rhs.used; i ++){
            os << rhs.dynarray[i] << ",";
        }
        return os;
    }
};


#endif //ASG1_INTLIST_H
