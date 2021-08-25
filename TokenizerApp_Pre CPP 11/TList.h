
#ifndef ASG1_TLIST_H
#define ASG1_TLIST_H
#include "Token.h"

class TList {

    struct TNode{
        Token theToken = Token{ }; // node data
        TNode* prev; // previous node in list
        TNode* next; // next node in list
        TNode(const Token& token = Token{ }, TNode* p = nullptr,
        TNode* n = nullptr)
        :theToken{ token }, prev{ p }, next{ n }{}

        TNode(Token&& token, TNode* p = nullptr, TNode* n = nullptr)
        : theToken{ std::move(token) }, prev{ p }, next{ n }{}
        TNode& operator=(const TNode&) = delete; // copy assignment
        TNode& operator=(TNode&&) = delete; // move assignment
        ~TNode() = default;
    };
private:
    TNode* headerPtr;
    TNode* trailerPtr;
    int theSize;

    void addBefore(TNode* p, const Token& aToken);  //Inserts a new node before the node p points to

public:
    TList();                                           //Default constructor, creates an list
    TList(const TList& list);                          //Copy constructor
    TList(TList&& list);                               //Move constructor
    TList& operator= (const TList& rhs);               //Copy assignment operator
    TList& operator= (TList&& rhs);                    //Move assignment operator
    virtual ~TList();                                  //Destructor (and a virtual one in this example)

    const bool empty();                                //Determines whether this list is empty
    const Token& front();                              //Retruns the token at the front of this list
    const Token& back();                               //Retruns the token at the back of this list

    void addSorted(const Token& aToken);               //Adds aToken at its sorted position into the list so as to maintain the ascending order of the list
    bool removeFront();                                //
    bool removeBack();
    const int size();
    void print(ostream& sout) const;
    const bool search(const Token& aToken);
    TNode* lookup(const Token& aToken) const;
    void init();
    void remove(TNode* nodePtr);                      //Removes the node nodePtr points to

};


#endif //ASG1_TLIST_H
