//Tyler Taormina
//tyler.taormina@oit.edu
//CST 126 Lab 6

#ifndef LAB5_LINKEDLIST_H
#define LAB5_LINKEDLIST_H
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::swap;


struct Node {
    int data;
    Node* next;
};

class LList
{
private:
    Node* head;

public:
    //Constructors.
    LList();
    LList(int data);
    LList(const LList& copy);
    LList& operator= (const LList& copy);
    LList(LList&& move);
    LList& operator= (LList&& move);
    ~LList();
    void insertHead(int data);
    void pushBack(int data);
    int getData();
    Node* getNext();
    void setData(int data);
    void deleteNode(int data);
    void deleteList();
    void printList();
    friend std::ostream& operator <<(std::ostream& ostr, const LList& rhs);
};

#endif //LAB5_LINKEDLIST_H

