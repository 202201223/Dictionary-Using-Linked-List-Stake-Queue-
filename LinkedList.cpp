#include "LinkedList.h"
#include <iostream>
using namespace std;

// Default Constructor
LinkedList::LinkedList(){
    first = nullptr;
}

// initialize the needed methods
Node* LinkedList::getFirst(){
    return first;
}

bool LinkedList::isEmpty(){
    return(first == nullptr);
}

void LinkedList::insert(string item){
    Node* newNode = new Node(item);
    if(isEmpty()){
        first = newNode;
    }
    else{
        newNode->setPointer(first);
        first = newNode;
    }
}

void LinkedList::DisPlay(){
    Node* tail = first;
    while(tail!=nullptr){
        cout<<tail->getData()<<"\n";
        tail = tail->getPointer();
    }
}

int LinkedList::Nodes_Number(){
    int counter = 0;
     Node* tail = first;
    while(tail!=nullptr){
        counter++;
        tail = tail->getPointer();
    }
    return counter;
}
