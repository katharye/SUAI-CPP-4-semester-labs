#ifndef NODE_H
#define NODE_H

typedef struct Node
{
    int data;
    Node* next;

    Node(int val) 
    {
        data = val;
        next = nullptr;
    }

} Node;

#endif