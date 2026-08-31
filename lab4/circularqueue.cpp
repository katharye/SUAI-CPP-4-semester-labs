#include "circularqueue.h"

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
CircularQueue<T>::CircularQueue() : head_index(0), tail_index(0), max_size(0), real_size(0), data(nullptr) {}
template <typename T>
CircularQueue<T>::CircularQueue(int size) : head_index(0), tail_index(0), max_size(size), real_size(0) {
    if (size <= 0) throw std::invalid_argument("Invalid size");
    data = new T[size];
}
template <typename T>
CircularQueue<T>::CircularQueue(const CircularQueue& other)
    : head_index(other.head_index),
      tail_index(other.tail_index),
      max_size(other.max_size),
      real_size(other.real_size) {
    this->data = new T[max_size];

    for (int i = 0; i < real_size; ++i) {
        int src_index = (other.head_index + i) % other.max_size;
        int dest_index = (this->head_index + i) % this->max_size;

        this->data[dest_index] = other.data[src_index];
    }
}

template <typename T>
CircularQueue<T>::~CircularQueue() {
    delete[] data;
}

template <typename T>
bool CircularQueue<T>::isFull() const {
    return max_size == real_size;
}
template <typename T>
bool CircularQueue<T>::operator!() const {
    return real_size == 0;
}
template <typename T>
void CircularQueue<T>::operator+(const T& val) {
    if (max_size == 0) throw std::logic_error("Queue is not initialized");
    if (isFull()) throw std::overflow_error("Queue is full");

    data[tail_index] = val;
    tail_index = (tail_index + 1) % max_size;
    real_size++;
}
template <typename T>
T CircularQueue<T>::operator-(int) {
    if (max_size == 0) throw std::logic_error("Queue is not initialized");
    if (real_size == 0) throw std::underflow_error("Queue is empty");

    T value = data[head_index];
    head_index = (head_index + 1) % max_size;
    real_size--;
    return value;
}

template <typename T>
void CircularQueue<T>::print() {
    for (int i = 0; i < real_size; i++) {
        std::cout << "[" << data[(head_index + i) % max_size] << "]";
        if (i < real_size - 1) {
            std::cout << " -> ";
        }
    }
}

template class CircularQueue<int>;
template class CircularQueue<char>;
template class CircularQueue<float>;
template class CircularQueue<double>;