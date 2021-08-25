#include <iostream>
#include <string>
#include "Token.h"
#include "Tokenizer.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    string fileName;
    string separatorCharacters;
    string keyword;
    char choice;

    cout << " Enter the name of an input file of text:" << endl;
    getline(cin,fileName);
    //input_text_file.txt
    cout << " Enter the separator characters:";
    //;. ,?!"=':
    getline(cin,separatorCharacters);

    cout << endl;
    cout << "   Menu  " << endl;
    cout << "==============" << endl;
    cout << "   A - Print all input lines " << endl;
    cout << "   P - Print indexed tokens " << endl;
    cout << "   F - Print tokens sorted on frequency " << endl;
    cout << "   L - Print tokens sorted on length " << endl;
    cout << "   S - Search " << endl;
    cout << "   X - Exit " << endl;
    cout << "==============" << endl;

    cout << "Enter your choice: " << endl;
    cin >> choice;

    Tokenizer tok(fileName, separatorCharacters);
    do{
        switch(tolower(choice))
        {
            case 'a':
                tok.printAllInputLines();
                choice = '+';
                break;
            case 'p':
                cout << tok << endl;
                choice = '+';
                break;
            case 'f':
                tok.sortOnFrequecy();
                choice = '+';
                break;
            case 'l':
                tok.sortOnTokenLength();
                choice = '+';
                break;
            case 's':
                cout << "Enter the text to search for: ";
                cin >> keyword;
                if(!tok.searchAndPrint(keyword)){
                    cout << "Token not found." << endl;
                }
                choice = '+';
                break;
            case 'x':
                cout << "Thank you for trying my program." << endl;
                cout << "Goodbye.";
                exit(0);
            case '+':
                cout << "Enter your choice: ";
                cin >> choice;
                break;
            default:
                cout << "The choice of yours might not valid, please enter again! " << endl;
                cout << "Enter your choice: ";
                cin >> choice;
        }
    } while (true); //the loop will never stop, till users press 'x' button.

}
