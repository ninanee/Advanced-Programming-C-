
#include "Tokenizer.h"
#include <ostream>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <forward_list>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::forward_list;

//this constructor extracts the lines from the input file one line at at a time
//delegating the pro-cess of extracting the tokens in a line and keeping track of the associated line numbers
//to ProcessTokensInLine(text, line number),
Tokenizer::Tokenizer(const string& filename, const string& separators) : theSeparators{separators}
{
    std::ifstream inFile(filename);
    if(!inFile){
        cout << "Sorry, can not open the file! " << filename << endl;
    }

    int linenum = 1;
    string line;

    while(!inFile.eof()){
        getline(inFile,line);
        theLines.push_back(line);
        ProcessTokensInLine(line, linenum);
        linenum++;
    }
    inFile.close();
}


//Outsources the process of extracting the tokens in line and inserting them each into the
//token list
void Tokenizer::ProcessTokensInLine(const string& line, size_t linenum)
{
    vector<string> vec = splitLineIntoTokens(line);
    for (const string& str : vec){
        insert(str, linenum);
    }
}

//it splits the given line of text into string tokens, storing and
//returning them all in a std::vector of std::strings.
vector<string> Tokenizer::splitLineIntoTokens(const string& line) const
{
    vector<string> tList{};
    size_t a{},b{};
    while ( b != string::npos){
        b = line.find_first_of(theSeparators, a);
        if ( a == b ){
            a++;
        } else if( b == string::npos) {
            if (a == line.length())
                return tList;
            tList.push_back(line.substr(a));
        } else {
            tList.push_back(line.substr(a, b - a));
            a = b + 1;
        }
    }
    return tList;
}


//it creates a Token object using the supplied text and line number;
//it then compares that object against the Token objects in the token list, which are already sorted
//in ascending order; if found, it updates the number list of that object; otherwise, it inserts
//the newly created Token object into the token list.
void Tokenizer::insert(string text, size_t linenum)
{
    Token token{std::move(text), linenum};
    list<Token>::iterator it;
    if(theTokenList.empty()){
        theTokenList.push_back(token);
        return;
    }

    for(it = theTokenList.begin(); it != theTokenList.end(); it++){
        if(token.compareIgnoreCase(*it) == 0) {
            it->pushBackLineNumber(linenum);
            return;
        } else if(token.compareIgnoreCase(*it) > 0){
            continue;
        } else{
            theTokenList.insert(it, token);
            return;
        }
    }
    theTokenList.insert(it, token);
}


//Searches the token list for a token object whose text is equal (case insensitive) to that of
//the given string str. If found, it returns a copy of that object's line number list; otherwise,
//it returns an empty number list.
vector<size_t> Tokenizer::search(const string& str)const
{
    list<Token>::const_iterator it;
    for(it = theTokenList.begin(); it != theTokenList.end(); it++){
        if ((*it).getTheText() == str) {
            return it->getTheLineNumberList();
        }
    }
    return vector<size_t>{};
}


//Given a std::vector of line numbers, prints the input lines corresponding to those line numbers.
void Tokenizer::printSomeInputLines(const vector<size_t>& vec)const
{
    vector<size_t>::const_iterator it;
    for(it = vec.begin(); it != vec.end(); it++){
        cout << theLines[*it - 1] << endl;
    }
}

//bool function
//Searches the token list for a token object whose text is the same as the given string str;
//if found, it prints the input lines that contain str
bool Tokenizer::searchAndPrint(string& str) const
{
    auto v = search(str);
    if (v.empty()){
        return false;
    }else{
        printSomeInputLines(v);
        return true;
    }
}

//Prints all input lines.
void Tokenizer::printAllInputLines() const
{
    vector<string>::const_iterator it;
    for(it = theLines.begin(); it != theLines.end(); it++){
        cout << *it << endl;
    }
}

//Prints the token list to the given output stream sout.
void Tokenizer::print(std::ostream& sout) const
{
    list<Token>::const_iterator it;
    for(it = theTokenList.begin(); it != theTokenList.end(); it++){
        sout << *it << endl;
    }
}


//Prints the token list sorted on frequencies of the tokens in the input
//add the bool function as parameters
void Tokenizer::sortOnFrequecy() const
{
    list<Token>::const_iterator it;
    forward_list<Token>::const_iterator forList_it;
    forward_list<Token> for_list {};

    for(it = theTokenList.begin(); it != theTokenList.end(); it++){
        for_list.push_front(*it);
    }
    for_list.sort(compareByFrequency);

    for(forList_it = for_list.begin(); forList_it != for_list.end(); forList_it++){
        cout << *forList_it << endl;
    }
}

//Prints the token list sorted on the text of the tokens..
void Tokenizer::sortOnTokenLength() const
{
    list<Token>::const_iterator it;
    forward_list<Token>::const_iterator forList_it;
    forward_list<Token> for_list {};

    for(it = theTokenList.begin(); it != theTokenList.end(); it++){
        for_list.push_front(*it);
    }
    for_list.sort(compareByLength);

    for(forList_it = for_list.begin(); forList_it != for_list.end(); forList_it++){
        cout << *forList_it << endl;
    }
}

std::ostream& operator<<(std::ostream& sout, const Tokenizer& tokenizer){
    tokenizer.print(sout);
    return sout;
}
