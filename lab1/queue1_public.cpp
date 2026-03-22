#include "queue1_public.h"

#include <iostream>

#include "queue.h"

Queue1_public::Queue1_public() : Queue() {}
Queue1_public::~Queue1_public() {}

double Queue1_public::findHarmonicMean() const {
    int nominator = getSize();

    double denominator = 0;

    for (int i = 0; i < getSize(); i++) {
        denominator += 1.0 / getElementAt(i);
    }

    return nominator / denominator;
}

int Queue1_public::findElementsGreaterThanHarmonicMean() const {
    if (isEmpty()) {
        return -1;
    }
    for (int i = 0; i < getSize(); i++) {
        if (getElementAt(i) == 0) {
            return -1;
        }
    }

    double harmonicMean = findHarmonicMean();
    int count = 0;

    for (int i = 0; i < getSize(); i++) {
        if (harmonicMean < getElementAt(i)) count++;
    }

    return count;
}

void Queue1_public::printResult() const {
    std::cout << "Количество элементов, больших среднего гармонического: ";
    int result = findElementsGreaterThanHarmonicMean();
    if (result != -1) {
        std::cout << result << std::endl;
    } else {
        std::cout << "n/a" << std::endl;
    }
}