#include "linkedlist"

#include <iostream>

LinkedList::LinkedList() {
    counter = 0;
    head = tail = nullptr;
}

LinkedList::LinkedList(int count) {
    head = tail = nullptr;
    counter = 0;

    for (int i = 0; i < count; i++) {
        Node* tmp = new Node(i + 1);
        tmp->setNext(nullptr);

        if (head == nullptr) {
            head = tmp;
            tail = tmp;
        } else {
            tail->setNext(tmp);
            tail = tmp;
        }

        counter++;
    }
}

LinkedList::LinkedList(const LinkedList& other) {
    this->head = nullptr;
    this->tail = nullptr;
    this->counter = 0;

    if (other.head == nullptr) {
        return;
    } else {
        Node* tmp = other.head;

        while (tmp != nullptr) {
            if (this->head == nullptr) {
                this->head = new Node(tmp->getData());
                this->tail = this->head;
            } else {
                this->tail->setNext(new Node(tmp->getData()));
                this->tail = this->tail->getNext();
            }

            this->counter++;
            tmp = tmp->getNext();
        }
    }
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* tmp = head;
        head = head->getNext();
        delete tmp;
    }
    tail = nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) return *this;

    Node* tmp;
    while (this->head != nullptr) {
        tmp = this->head->getNext();
        delete head;
        head = tmp;
    }

    this->head = nullptr;
    this->tail = nullptr;
    this->counter = other.counter;

    if (other.head == nullptr) {
        return *this;
    } else {
        Node* tmp = other.head;

        while (tmp != nullptr) {
            if (this->head == nullptr) {
                this->head = new Node(tmp->getData());
                this->tail = this->head;
            } else {
                this->tail->setNext(new Node(tmp->getData()));
                this->tail = this->tail->getNext();
            }

            tmp = tmp->getNext();
        }
    }
    return *this;
}

LinkedList& LinkedList::operator++() {
    if (head == nullptr) {
        counter++;
        head = tail = new Node(counter);
    } else {
        counter++;
        Node* tmp = new Node(counter);

        tmp->setNext(head);
        head = tmp;
    }

    return *this;
}

LinkedList LinkedList::operator++(int) {
    LinkedList temp = *this;

    if (head == nullptr) {
        counter++;
        head = tail = new Node(counter);
    } else {
        counter++;
        tail->setNext(new Node(counter));
        tail = tail->getNext();
    }

    return temp;
}

LinkedList& operator--(LinkedList& list) {
    if (list.head == nullptr) {
        return list;
    } else {
        Node* tmp = list.head;
        list.head = list.head->getNext();

        delete tmp;
        if (list.head == nullptr) list.tail = nullptr;
    }

    return list;
}

LinkedList operator--(LinkedList& list, int) {
    LinkedList temp = list;
    if (list.head == nullptr) {
        return temp;
    } else if (list.head == list.tail) {
        delete list.head;
        list.head = nullptr;
        list.tail = nullptr;
    } else {
        Node* tmp = list.head;
        while (tmp->getNext() != list.tail) tmp = tmp->getNext();
        list.tail = tmp;

        delete tmp->getNext();
        list.tail->setNext(nullptr);
    }

    return temp;
}

void LinkedList::printLinkedList() const {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* tmp = head;
    while (tmp->getNext() != nullptr) {
        std::cout << "[" << tmp->getData() << "]" << " <- ";
        tmp = tmp->getNext();
    }
    std::cout << "[" << tmp->getData() << "]" << std::endl;
}

bool LinkedList::isEmpty() { return head == nullptr; }