#include <iostream>
//#include "TokenizerApp.h"
using std::cout;
using std::endl;

#include<iostream>
#include<cassert>
#include "IntList.h"
#include "Token.h"
#include "TokenizerApp.h"


int main()
{
    const char* filename = "/Users/yunni/Desktop/Asg1/input_text_file.txt";
// this file is located in the visual studio storing
// all the .cpp and .h file for this project.
// or
    //const char* filename = "file:///Users/yunni/Desktop/2021Summer/COMP5421/Assignment/Asg2/Asg2/input_text_file.txt";
    TokenizerApp tokApp(filename);
    tokApp.print(cout);
    cout << endl;
    return 0;
}