#ifndef ASG1_TOKEN_H
#define ASG1_TOKEN_H
#include "IntList.h"
#include "cstring"
#include <ostream>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;


class Token {
private:
    char* text;                                         //Pointer to a dynamically allocated array of characters
    IntList number_list;                                //Manages the list of numbers associated with this token

public:
    explicit Token(const char * cstr, int line_num);
    Token();

    Token(const Token& token);                         //Copy constructor
    Token(Token&& token);                              //Move constructor
    Token& operator=(const Token& rhs);                //Copy assignment operator
    Token& operator=(Token&& rhs);                     //Move assignment operator
    virtual ~Token();                                  //Destructor (and a virtual one in this example)

    int compare(const Token& aToken);                  //Returns -1, 0, or 1 as "the" this token's text is less than, equal to, or grater than aToken's text.

    const char* getText();                             //Returns a constant pointer to this token's text
    void addLineNumber(int line_num);                  //Adds line num to the end of this token's number list
    int size();
    void print(ostream& sout);
    char getChar(int k);
    int getLineNumber() const;

    friend ostream& operator<< (std::ostream& os, const Token& token)
    {
        os<< token.text << ", ";
        os<< token.number_list << endl;
        return os;
    }
};


#endif //ASG1_TOKEN_H
