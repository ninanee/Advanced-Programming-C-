#include "TokenizerApp.h"
#include <ostream>
#include <fstream>
#include <sstream>
#include "TList.h"
#include "IntList.h"
using namespace std;


void TokenizerApp::loadTokenList(const char* filename)
{
    ifstream fin(filename);
    if (!fin)
    {
        cout << "could not open input file: " << filename << endl;
        exit(1);
    }
    int linenum = 0;
    string line;
    getline(fin, line); // attempt to read a line
    while (fin)
    {
        ++linenum;
        istringstream sin(line); // convert the line just read into an input stream
        string word;
        while (sin >> word) // extract the tokens and add them to tokenList
        {
            tokenList. addSorted (Token(word.c_str(), linenum));
        }
        getline(fin, line);
    }
    fin.close();
}
TokenizerApp::TokenizerApp(const char* filename)
{
    loadTokenList(filename);
}
void TokenizerApp::print(ostream& sout)const
{
    tokenList.print(sout);
}