#include "Token.h"
#include <ostream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


Token::Token(string text, size_t linenum)
{
    for(char & i : text)
    {
        i = tolower(i);
    }
    theLineNumbers.push_back(linenum);
    theText = text;
    theFrequency = 1;
}

// comparison member function (returns -1, 0, +1, as in A1)
// case insensitive comparison
int Token::compareIgnoreCase(const Token& t) const
{
    size_t i = 0;
    while((i<this->theText.length()) && (i < t.theText.length())) {
        if (tolower(this->theText[i]) < tolower(t.theText[i])) {
            return -1;
        } else if (tolower(this->theText[i]) > tolower(t.theText[i])) {
            return 1;
        }
        i++;
    }
    if (this->theText.length() < t.theText.length()) {
        return -1;
    } else if (this->theText.length() > t.theText.length()) {
        return 1;
    }
    return 0;
}

string Token::getTheText() const{
    return theText;
}
vector<size_t> Token::getTheLineNumberList() const{
    return theLineNumbers;
}
size_t Token::getFrequency() const{
    return theFrequency;
}

size_t Token::getLineNumber(size_t index) const{
    return theLineNumbers[index-1];
}

// append the suppled line number
void Token::pushBackLineNumber(size_t lineNum){
    theLineNumbers.push_back(lineNum);
    theFrequency++;
}

// print this token to sout
void Token::print(std::ostream& sout) const{
    sout << theText << " (" << getFrequency() << ") ";
    for(unsigned long theLineNumber : theLineNumbers){
        sout << theLineNumber << " ";
    }
}

std::ostream& operator<<(std::ostream& sout, const Token& arr)
{
    arr.print(sout);
    return sout;
}

//order by frequency(increment)
//if the frequency is the same, order by Alphabet list;
bool compareByFrequency(const Token& t1, const Token& t2)
{
    if(t1.getFrequency() == t2.getFrequency()){
        return compareByAlphabet(t1, t2);
    } else{
        return (t1.getFrequency() < t2.getFrequency());
    }
}

//if the length is the same, order by Alphabet list;
//if the length is not the same, order by the length, increment
bool compareByLength(const Token& t1, const Token& t2)
{
    if(t1.getTheText().length() == t2.getTheText().length()){
        return compareByAlphabet(t1, t2);
    } else{
        return (t1.getTheText().length() < t2.getTheText().length());
    }
}

bool compareByAlphabet(const Token& t1, const Token& t2)
{
    if(t1.compareIgnoreCase(t2) == -1){
        return true;
    } else{
        return false;
    }
}

