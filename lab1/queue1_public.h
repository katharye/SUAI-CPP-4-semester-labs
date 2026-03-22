#ifndef QUEUE1_PUB_H
#define QUEUE1_PUB_H

#include "queue.h"

class Queue1_public : public Queue 
{
    private:
        double findHarmonicMean() const;
    public:
        Queue1_public();
        ~Queue1_public();

        int findElementsGreaterThanHarmonicMean() const;
        void printResult() const;
};

#endif