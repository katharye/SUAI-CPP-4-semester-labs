#ifndef QUEUE1_PRIV_H
#define QUEUE1_PRIV_H

#include "queue.h"

class Queue1_private : protected Queue 
{
    private:
        double findHarmonicMean() const;
    public:
        Queue1_private();
        ~Queue1_private();

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