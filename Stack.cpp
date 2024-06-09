#include "Stack.h"
#include <iostream>
using namespace std;

// Default Constructor 
Stack::Stack(){
    top = nullptr;
}

// initialize the needed methods
Node* Stack::getTop(){
    return top;
}

bool Stack::isEmpty(){
    return(top == nullptr);
}

void Stack::Push(string item){
    Node* newNode = new Node(item);
    if(isEmpty()){
        top = newNode;
    }
    else{
        newNode->setPointer(top);
        top = newNode;
    }
}

void Stack::Push(char item){
    Node* newNode = new Node(item);
    if(isEmpty()){
        top = newNode;
    }
    else{
        newNode->setPointer(top);
        top = newNode;
    }
}

string Stack::Pop(){
    if(!isEmpty()){
    string storData = top->getData();
    Node* temp = top;
    top = top->getPointer();
    delete temp;
    return storData;
    }
    else{
        return "this stack is empty";
    }
}

void Stack::Display(){
    Node* temp = top;
    while(temp!=nullptr){
        cout<<temp->getData()<<"\n";
        temp = temp->getPointer();
    }
}

string Stack::Peek(){
    return top->getData();
}

int Stack::Nodes_Number(){
    int counter = 0;
    Node* temp = top;
    while(temp!=nullptr){
        counter++;
        temp = temp->getPointer();
    }
    return counter;
}