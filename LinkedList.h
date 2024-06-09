#ifndef _LINKEDLIST
#define _LINKEDLIST
#include "Node.h"
class LinkedList{
    // private members
private:
    Node* first;

    // public members
public:
    // Default Constructor
    LinkedList();

    // needed methods
    Node* getFirst();
    bool isEmpty();
    void insert(string item);
    void DisPlay();
    int Nodes_Number();

};

#endif //LINKEDlIST