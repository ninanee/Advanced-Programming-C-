#ifndef INC_5421A2_TOKENIZER_H
#define INC_5421A2_TOKENIZER_H
#include "Token.h"
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;

class Tokenizer
{
private:
    const string theSeparators; // the separator characters in a std::string
    list<Token> theTokenList; // the list of tokens managed by this tokenizer
    vector<string> theLines; // the lines in the input file

    void ProcessTokensInLine(const string& line, size_t linenum);
    vector<string> splitLineIntoTokens(const string& line) const;
    void insert(string text, size_t linenum);
    vector<size_t> search(const string& str)const;
    void printSomeInputLines(const vector<size_t>& vec)const;

public:
    Tokenizer() = delete;      // disable default constructor
    Tokenizer(const string& filename, const string& separators);
    ~Tokenizer() = default; // dtor
    Tokenizer(const Tokenizer&) = default; // copy ctor
    Tokenizer(Tokenizer&&) = default; // move ctor
    Tokenizer& operator=(const Tokenizer&) = default; // copy op=
    Tokenizer& operator=(Tokenizer&&) = default; // move op=

    bool searchAndPrint(string& str) const;
    void printAllInputLines() const;
    void print(std::ostream& sout) const;
    void sortOnFrequecy() const;
    void sortOnTokenLength() const;

};

#endif //INC_5421A2_TOKENIZER_H
std::ostream& operator<<(std::ostream& sout, const Tokenizer& tokenizer);
