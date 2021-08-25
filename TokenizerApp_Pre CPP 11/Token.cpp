#include "Token.h"
#include "cstring"
#include <string.h>
#include <ostream>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;


Token::Token(const char * cstr, int line_num){
    text = new char[strlen(cstr) + 1];
    strcpy(text, cstr);
    number_list = IntList();
    number_list.pushback(line_num);
}

//Default Constructor, creates an empty C-string
Token::Token(){
    text = new char[1];
    text[0] = '\0';
    number_list = IntList();
}

//Copy constructor
Token::Token(const Token& token){

    //cout<<"copy constructor"<<endl;

    number_list = token.number_list;
    text = new char[strlen(token.text) + 1];
    strcpy(text, token.text);

}

//Move constructor
Token::Token(Token&& token){
    //cout<<"move cons"<<endl;

    text = new char[strlen(token.text) +1];
    text = token.text;
    number_list = token.number_list;
    token.text = nullptr;
}
//Copy assignment operator
Token& Token::operator=(const Token& rhs){
    //cout<<"copy assign"<<endl;

    if(this != &rhs){
        delete [] this -> text;
        text = new char[strlen(rhs.text) + 1];
        strcpy(text, rhs.text);
        number_list = rhs.number_list;
    }
    return *this;
}

//Move assignment operator
Token& Token::operator=(Token&& rhs){
    //cout<<"move assign"<<endl;
    if(this != &rhs){
        delete [] this -> text;
        text = new char[strlen(rhs.text) + 1];

        for (size_t i{}; i < rhs.size(); ++i) {
            text[i] = rhs.text[i];
        }
        number_list = rhs.number_list;
        rhs.text = nullptr;

    }
    return *this;
}

Token:: ~Token(){
    delete [] text;
}

//Returns -1, 0, or 1 as "the" this token's text is less than, equal to, or grater than aToken's text.
int Token::compare(const Token& aToken){
    int compareToken = strcmp(text, aToken.text);
    if(compareToken == 0)
        return 0;
    else if(compareToken < 0)
        return -1;
    else
        return 1;

}

//Returns a constant pointer to this token's text
const char* Token::getText() {
    return text;
}

//Adds line num to the end of this token's number list
void Token::addLineNumber(int line_num){
    number_list.pushback(line_num);
}

//Returns the length of this token's text
int Token::size(){
    return strlen(text);
}

//Prints this token's text followed by its number list.
void Token::print(ostream& sout){
    cout<< text << "  "<< number_list << endl;
}
//Returns the k'th character (zero-based) of this token's
//text. Returns the null character (n0) if k is out-of-range
char Token::getChar(int k){
    if (k >= 0 && k < size()) {
        return text[k];
    }
    else {
        return '\0';
    }
}

//Returns this tokens line number, which is stored at position
//0 of this token's list of line numbers
//if number list is empty, should return -1
int Token::getLineNumber() const{
    int x = -1;
    number_list.get(0, x);
    return x;
}