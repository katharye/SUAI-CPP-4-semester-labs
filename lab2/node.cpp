#include "node"

Node::Node(int value) {
    data = value;
    next = nullptr;
}

Node::~Node() {}

int Node::getData() const { return data; }

Node* Node::getNext() const { return next; }

void Node::setData(int value) { data = value; }

void Node::setNext(Node* node) { next = node; }
