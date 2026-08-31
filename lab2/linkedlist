#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node"

class LinkedList
{
private:
    int counter; 
    
    Node* head;
    Node* tail;

public:
    LinkedList();
    explicit LinkedList(int count);
    ~LinkedList();

    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    LinkedList& operator ++ ();
    LinkedList operator ++ (int);

    friend LinkedList& operator-- (LinkedList& list);
    friend LinkedList operator-- (LinkedList& list, int);

    bool isEmpty();
    void printLinkedList() const;
};

#endif