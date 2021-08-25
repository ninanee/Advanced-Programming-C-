#ifndef ASG1_TOKENIZERAPP_H
#define ASG1_TOKENIZERAPP_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "TList.h"
#include "TokenizerApp.h"
using std::cout;
using std::endl;
using std::cin;

class TokenizerApp {
private:
    TList tokenList{};

public:
    void loadTokenList(const char* filename);
    TokenizerApp(const char* filename);
    void print(ostream& sout)const;

};
#endif //ASG1_TOKENIZERAPP_H
