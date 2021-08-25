
#include "TList.h"

//Default constructor, creates an list
TList::TList(){
    init();
}

//Copy constructor
TList::TList(const TList& list){
    headerPtr = new TNode();
    trailerPtr = new TNode{};

    headerPtr = list.headerPtr;
    trailerPtr = list.trailerPtr;
    theSize = list.theSize;

}

//Move constructor
TList::TList(TList&& list){
    //cout<<"move cons"<<endl;
    headerPtr = list.headerPtr;
    trailerPtr = list.trailerPtr;
    theSize = list.theSize;

    list.headerPtr = nullptr;
    list.trailerPtr = nullptr;
    list.theSize = 0;
}

//Copy assignment operator
TList& TList::operator= (const TList& rhs){
    if(this != &rhs){
        headerPtr = new TNode();
        trailerPtr = new TNode();
        headerPtr = rhs.headerPtr;
        trailerPtr = rhs.trailerPtr;
        theSize = rhs.theSize;
    }
    return *this;
}

//Move assignment operator
TList& TList::operator= (TList&& rhs) {
    if(this != &rhs){
        headerPtr = new TNode();
        trailerPtr = new TNode();

        headerPtr = rhs.headerPtr;
        trailerPtr = rhs.trailerPtr;
        theSize = rhs.theSize;

        rhs.headerPtr = nullptr;
        rhs.trailerPtr = nullptr;
        rhs.theSize = 0;
    }
    return *this;
}

//Destructor (and a virtual one in this example)
TList:: ~TList() {
    delete headerPtr;
    delete trailerPtr;
}

//Determines whether this list is empty
const bool TList::empty(){
    if (theSize == 0)
        return true;
    else
        return false;
}

//Retruns the token at the front of this list
const Token& TList::front(){
    return headerPtr->next->theToken;
}

//Retruns the token at the back of this list
const Token& TList::back(){
    return trailerPtr->prev->theToken;
}

//Adds aToken at its sorted position into the list so as to maintain the ascending order of the list
void TList::addSorted(const Token& aToken){
    TNode* nodePtr = lookup(aToken);
    if (nodePtr == trailerPtr)                    // aToken not on the list, greater than all the other tokens
    {
        addBefore(trailerPtr, aToken);
    }
    else if ((*nodePtr).theToken.compare(aToken) == 0) {
        int lineNum = aToken.getLineNumber();
        (nodePtr->theToken).addLineNumber(lineNum);
    }
    else {
        addBefore(nodePtr, aToken);
    }
    return;
}

//If the list is nonempty, removes the node at the front of the list and returns true; otherwise, returns false
bool TList::removeFront(){
    if (headerPtr->next == trailerPtr) {
        return false;
    }
    else {
        TNode* p = headerPtr->next;              //p indicate current
        headerPtr->next = p->next;
        p->next->prev = headerPtr;
        delete p;
        theSize--;
        return true;
    }
}

//If the list is nonempty, removes the node at the end of the list and returns true; otherwise, returns false
bool TList::removeBack(){
    if (headerPtr->next == trailerPtr) {
        return false;
    }
    else {
        TNode* p = trailerPtr->prev;            //p indicate current
        trailerPtr->prev = p->prev;
        p->prev->next = trailerPtr;
        delete p;
        theSize--;
        return true;
    }
}
const int TList::size(){
    return theSize;
}

//Prints the entire list
void TList::print(ostream& sout) const{
    TNode* p = headerPtr;
    while(p->next != trailerPtr){
        p = p->next;
        p->theToken.print(sout);
    }
}

//Determines whether aToken is in the list.
const bool TList::search(const Token& aToken){
    TNode* p = headerPtr;
    while(p->next != trailerPtr){
        p = p->next;
        if(p->theToken.compare(aToken) == 0){
            return true;
        }
    }
    return false;
}

TList::TNode* TList::lookup(const Token& aToken) const{
    TNode* head = this->headerPtr->next;
    while (head != this->trailerPtr){
        // compare the cstrings in the following two token objects;
        // =0 means equal, >0 means head->theToken > tok
        if (((head->theToken).compare(aToken)) >= 0)
            break;
        head = head->next;
    }
    return head;
}

//Initializes this list to an empty list at construction
void TList::init(){
    this -> theSize = 0;
    headerPtr = new TNode{};                 // headerPtr will always point to this allocated fixed header node
    trailerPtr = new TNode{};                  //trailerPtr will always point to this allocated fixed header node

    headerPtr->next = trailerPtr;              //header node's next points to the trailer node
    trailerPtr->prev = headerPtr;             // trailer node's prev points to the header node
}

//Removes the node nodePtr points to
void TList::remove(TNode* nodePtr){
    nodePtr->prev->next = nodePtr->next;
    nodePtr->next->prev = nodePtr->prev;
    delete nodePtr;
    theSize--;
}

void TList::addBefore(TNode* q, const Token& aToken){
    ++this->theSize;
    TNode* p = new TNode{ aToken };
    // link p between q->prev and q

    p->next = q;
    p->prev = q->prev;

    // now that p can see q->prev and q,
    // we let q->prev and q see p to complete the insertion
    q->prev = (q->prev)->next = p;
};