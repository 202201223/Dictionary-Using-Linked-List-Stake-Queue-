#ifndef _STACK
#define _STACK
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

class Stack{
    // Private Members
private:
    Node* top;

    // Public members
public:
    //Default Constructor
    Stack();

    // Needed Methods
    Node* getTop();
    void Push(string item);
    void Push(char item);
    string Pop();
    void Display();
    bool isEmpty();
    string Peek();
    int Nodes_Number();
};

#endif //_STACK