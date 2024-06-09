#include "Node.h"
#include <iostream>
using namespace std;

// initialize Default Constructor
Node::Node(){
    next = nullptr;
}

// initialize Parametrized Constructor
Node::Node(string data,Node* next){
    this->data = data;
    this->next =next;
}

Node::Node(string data){
    this->data = data;
}

Node::Node(char item){
    this->item = item;
}

// initialize Methods
void Node::setData(string Data){
    data = Data;
}
void Node::setItem(char Item){
    item = Item;
}
void Node::setPointer(Node* ptr){
    next = ptr;
}
string Node::getData(){
    return data;
}
char Node::getItem(){
    return item;
}
Node* Node::getPointer(){
    return next;
}