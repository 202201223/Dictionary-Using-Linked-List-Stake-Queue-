#include "LinkedList.h"
#include "Node.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Methods Name 
bool Search_Function(LinkedList* list,string item);
bool StartWith_Function(LinkedList* list,string prefix [], int number);
bool EndWith_Function(LinkedList* list,string suffix[],int number);
bool Find_Function(LinkedList* list,string subString[], int size);


// Main Function
int main(){

    // Reading the File First Then take an object from the LinkedList class and insert the words in its data node.
    LinkedList* newList = new LinkedList();
    string item;
    fstream file;
    file.open("Project_Data_Set.txt",ios::in);
    if(file.is_open()){
         while(file>>item){      
            newList->insert(item);
            cout<<item<<"\n";
         }
    }
    file.close();
    // Test Functions that we wrote.
    // Search Function First
    cout<<Search_Function(newList,"mama");

    // Find Function Second
    string word[] = {"s","u","b"};
    int size = sizeof(word)/sizeof(word[0]);
    bool result = Find_Function(newList,word,size);
    if(result == true){
        cout<<result;
    }
    else{
        cout<<"not match"<<endl;
    }

    // Start With Function
    string prefix[] = {"m","a"};// size of array
    int count = sizeof(prefix) / sizeof(prefix[0]);
    bool result2 = StartWith_Function(newList,prefix,count);
    if(result2 == true){
        cout<<result2;
    }
    else{
        cout<<"not match"<<endl;
    }
    

    // End With Function 
    string suffix[] = {"am","le"};
    int count2 = sizeof(suffix) / sizeof(suffix[0]);
    bool result3 = EndWith_Function(newList,suffix,count);
    if(result3 == true){
        cout<<result3;
    }
    else{
        cout<<"not match"<<endl;
    }
    return 0;
}


// First The Implementation of Search Function 
// Take the list and the item that need to get it and loop on node->data
bool Search_Function(LinkedList* list,string item){
   Node* currentNode = list->getFirst();
   bool flage = false;
   while(currentNode != nullptr){
    if(currentNode->getData() == item){
        flage = true;
        currentNode = nullptr;
    } 
    else{
        currentNode = currentNode->getPointer();
        }
   }
   return flage;
}


// Second The Implementation of START WITH Function 
// Takes object from linked list that we are going to search in it, array of string as a prefix and there numbers
bool StartWith_Function(LinkedList* list,string prefix[], int number){
    LinkedList *newList = new LinkedList();
    Node* currentNode = list->getFirst();
    bool flag = false;
    while(currentNode != nullptr){
        Node* WordPtr = currentNode;
        for(int i =0; i<number ; i++){
              Node* CharPtr =  WordPtr;
            if(CharPtr->getData() == prefix[i]){
                flag = true;
                CharPtr=CharPtr->getPointer();
            }
            else{
                flag = false; 
                break; 
            }
            if(flag == true){
                newList->insert(WordPtr->getData());                       
            }   
            currentNode = currentNode->getPointer();
        }
    } 
    return flag;
}
    


// Third Implementation of END WITH Function
// Takes object from linkedlist that we are going to search in it, array of string as a suffix and there numbers
bool EndWith_Function(LinkedList* list,string suffix[],int number){
    LinkedList *newList = new LinkedList();
    Node* currentNode = list->getFirst();
    bool flag = false;
    while(currentNode != nullptr){
        string data = currentNode->getData();
        Stack* reversStack = new Stack();
        for(int i; i<data.size() ;i++){
            reversStack->Push(data[i]);
        }
        string* reversSuffix = new string[number];
        for(int i; i<number ; i++){
            reversSuffix[i] = suffix[number - 1 - i];
        }
        Node* StackTop = reversStack->getTop();
        for(int i=0 ; i<number ; i++){
            if(StackTop == nullptr || StackTop->getData() != reversSuffix[i]){
                flag = false;
                break;
            }
            StackTop = StackTop->getPointer();
        }
        if(flag == true){
            newList->insert(data);
        }
    currentNode = currentNode->getPointer();   
}
return !newList->isEmpty();
}


// Fourth Implementation For Find Function 
// Takes The list that going to search in it , sub string as an array and its size.
bool Find_Function(LinkedList* list,string subString[], int size){
    LinkedList* newList = new LinkedList();
    Node* firstPtr = list->getFirst() ;
    Node* secondPtr = nullptr ;
    Node* thirdPtr = nullptr;
    while(firstPtr != nullptr){
        secondPtr = firstPtr;
        for(int i = 0; i<size ; i++){
            thirdPtr = secondPtr;
        while(thirdPtr != nullptr && !subString[i].empty()){
            if(thirdPtr->getData() == subString[i]){
                thirdPtr = thirdPtr->getPointer();
                i++;
                if(subString[i] == " "){
                    newList->insert(firstPtr->getData());
                }
            }
            else
            {
                thirdPtr = thirdPtr->getPointer();
            }
        }
        if(subString[i].empty()){
            break;
        }
    }
    firstPtr = firstPtr->getPointer();
    }
    return !newList->isEmpty();
}
