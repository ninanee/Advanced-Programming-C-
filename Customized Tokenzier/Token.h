#ifndef INC_5421A2_TOKEN_H
#define INC_5421A2_TOKEN_H
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;


class Token {
private:
    string theText{};
    vector<size_t> theLineNumbers{};
    size_t theFrequency{ 1 };

public:
    Token(string text, size_t linenum);                // a normal constructor
    Token() = delete;

    Token& operator=(const Token& rhs) = default;      // copy op=
    Token& operator=(Token&& rhs) = default;           // move op=
    Token(const Token& source) = default;              // copy ctor
    Token(Token&& source) = default;                   // move ctor
    ~Token() = default;                                // dtor

    // comparison member function (returns -1, 0, +1, as in A1)
    int compareIgnoreCase(const Token& t) const;       // case insensitive comparison

    string getTheText() const;
    vector<size_t> getTheLineNumberList() const;
    size_t getFrequency() const;
    size_t getLineNumber(size_t i = 1) const;

    void pushBackLineNumber(size_t lineNum);
    void print(std::ostream& sout) const;

};

#endif //INC_5421A2_TOKEN_H
std::ostream& operator<<(std::ostream& sout, const Token& arr);
bool compareByFrequency(const Token& t1, const Token& t2);
bool compareByLength(const Token& t1, const Token& t2);
bool compareByAlphabet(const Token& t1, const Token& t2);