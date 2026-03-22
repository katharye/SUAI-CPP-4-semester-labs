#include "queue.h"

#include <iostream>

Queue::Queue() {
    tail = head = nullptr;
    size = 0;
}
Queue::~Queue() {
    while (head != nullptr) {
        getOutOfQueue();
    }
}

void Queue::getInQueue(int value) {
    Node* tmp = new Node(value);

    if (head == nullptr) {
        tail = head = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
    size++;
}
// Проверка в main
int Queue::getOutOfQueue() {
    int out = 0;

    Node* tmp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }

    out = tmp->data;
    delete tmp;

    size--;

    return out;
}

bool Queue::isEmpty() const { return head == nullptr; }
int Queue::getSize() const { return size; }

Queue* Queue::copyQueue() const {
    Queue* copy = new Queue;
    Node* tmp = head;

    for (int i = 0; i < size; i++) {
        copy->getInQueue(tmp->data);
        tmp = tmp->next;
    }

    return copy;
}

void Queue::print() const {
    std::cout << "Текущая очередь:" << std::endl;

    if (isEmpty()) {
        std::cout << "Очередь пуста..." << std::endl;
        return;
    }

    Node* tmp = head;

    for (int i = 1; i <= size; i++) {
        if (i == size) {
            std::cout << tmp->data << std::endl;
        } else {
            std::cout << tmp->data << "->";
        }
        tmp = tmp->next;
    }
}

// Проверка в main
int Queue::getElementAt(int index) const {
    int currentPos = 0;
    Node* tmp = head;

    while (currentPos != index) {
        tmp = tmp->next;
        currentPos++;
    }

    return tmp->data;
}

Queue* Queue::operator+(const Queue& Queue2) {
    Queue* merged = new Queue;

    Node* tmp = head;
    while (tmp != nullptr) {
        merged->getInQueue(tmp->data);
        tmp = tmp->next;
    }

    tmp = Queue2.head;
    while (tmp != nullptr) {
        merged->getInQueue(tmp->data);
        tmp = tmp->next;
    }

    return merged;
}