#ifndef _NODE
#define _NODE
#include <iostream>
using namespace std;

class Node{

    // Private Members
private:
    string data;
    char item;
    Node* next;

    // Public Members
public:
    // Default constructor 
    Node();

    // Parametrized constructor 
    Node(string data, Node* next);
    Node(string data);
    Node(char item);
    
    // Setter Methods
    void setData(string Data);
    void setPointer(Node *ptr);
    void setItem(char Item);

    // Getter Methods
    string getData();
    char getItem();
    Node* getPointer();
};

#endif //_NODE