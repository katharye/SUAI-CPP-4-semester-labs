#ifndef QUEUE1_PROT_H
#define QUEUE1_PROT_H

#include "queue.h"

class Queue1_protected : protected Queue 
{
    private:
        double findHarmonicMean() const;
    public:
        Queue1_protected();
        ~Queue1_protected();

        using Queue::getInQueue;
        using Queue::getOutOfQueue;
        using Queue::getSize;
        using Queue::copyQueue;
        using Queue::isEmpty;
        using Queue::print;
        using Queue::operator+;


        int findElementsGreaterThanHarmonicMean() const;
        void printResult() const;
};

#endif