//Tyler Taormina
//tyler.taormina@oit.edu
//CST 126 Lab 6

#include "LinkedList.h"
#include <utility>
#ifndef LAB5_LINKED_H
#define LAB5_LINKED_H
LList::LList() : head(nullptr) {}

//Parameterized constructor.
LList::LList(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    this->head = temp;
}

//Copy constructor.
LList::LList(const LList& copy) : head(nullptr)
{
    Node *temp = copy.head;
    Node** current = &head;
    while (temp != nullptr)
    {
        Node* temp_this = new Node;
        temp_this->data = temp->data;
        temp_this->next = temp->next;
        *current = temp_this;
        current = &temp_this->next;
        temp = temp->next;
    }
}

//Copy assignment operator.
LList& LList::operator= (const LList& copy)
{
    if (this != &copy)
    {
        delete this->head;
        this->head = nullptr;

        Node* temp_list = copy.head;

        while (temp_list->next != nullptr)
        {
            pushBack(temp_list->data);
            temp_list = temp_list->next;

        }
        pushBack(temp_list->data);
    }
    return *this;
}

//Move constructor.
LList::LList(LList&& move)
{
    *this = move;
}

//Move assignment operator.
LList& LList::operator= (LList&& move)
{
    *this = move;
    return *this;
}

//Deconstructor.
LList::~LList()
{
    Node* traverse = head;
    if (head == nullptr)
    {
        delete head;
        return;
    }
    while(traverse->next != nullptr)
    {
        Node* temp = traverse;
        traverse = traverse->next;
        delete temp;
    }
    delete traverse;
    head = nullptr;
}

void LList::insertHead(int data)
{
    Node* temp = new Node;
    temp->data = data;

    //Empty case.
    if (head == nullptr)
    {
        head = temp;
        head->next = nullptr;
    }
    //Non-empty case. Replace head node.
    else
    {
        Node* current = head;
        head = temp;
        head->next = current;
    }
}

void LList::pushBack(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    //Empty case.
    if (head == nullptr)
    {
        head = temp;
    }
        //Non-empty case.
    else
    {
        Node* traverse = head;
        while(traverse->next != nullptr)
        {
            traverse = traverse->next;
        }
        traverse->next = temp;
    }
}

void LList::deleteNode(int data)
{
    if (head == nullptr)
    {
        std::cout << "No nodes to delete." << std::endl;
        return;
    }
    Node** head_ref = &head;
    Node* traverse = head;
    Node* prev = nullptr;
    //Head node contains data.
    if (traverse != nullptr && traverse->data == data)
    {
        *head_ref = traverse->next;
        delete traverse;
        return;
    }
    //Keep searching for the data in the linked list.
    else
    {
        while(traverse->next != nullptr &&  traverse->data !=  data)
        {
            prev = traverse;
            traverse = traverse->next;
        }
        if (traverse->data == data)
        {
            prev->next = traverse->next;
            delete traverse;
            return;
        }
        //Key is not present.
        std::cout << "Key is not present." << std::endl;
        return;
    }
}

void LList::deleteList()
{
    Node* current = head;
    Node* next = nullptr;
    while(current->next != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

void LList::printList()
{
    Node* temp = head;
    if (temp == nullptr)
    {
        std::cout << "No items." << std::endl;
    }
    else
    {
        while(temp != nullptr)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
}

int LList::getData()
{
    return head->data;
}

Node* LList::getNext()
{
    return head->next;
}

void LList::setData(int data)
{
    head->data = data;
}

std::ostream& operator <<(std::ostream& ostr, const LList& rhs)
{
    Node* current = rhs.head;
    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
    return ostr;
}
#endif //LAB5_LINKED_H

