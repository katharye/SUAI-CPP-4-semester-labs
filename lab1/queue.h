#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

class Queue
{
    private:
      Node* head;
      Node* tail;
      int size;

    public:
        Queue();
        virtual ~Queue();

        void getInQueue(int value);
        int  getOutOfQueue();
        int getSize() const;
        Queue* copyQueue() const;

        bool isEmpty() const;
        void print() const;

        Queue* operator+(const Queue &Queue2);

    protected:
        int getElementAt(int index) const;
};

#endif