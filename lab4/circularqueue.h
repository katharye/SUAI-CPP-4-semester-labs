#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

template <typename T>
class CircularQueue
{
private:
    T* data;
    int head_index;
    int tail_index;

    int max_size;
    int real_size;
public:
    CircularQueue();
    CircularQueue(int size);
    CircularQueue(const CircularQueue& other);

    ~CircularQueue();


    bool isFull() const;
    bool operator!() const;
    void operator+(const T& val);
    
    T operator-(int);
    
    void print();
};

#endif