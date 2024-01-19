#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

template <class T>
class Queue{
private:
    Node<T>* front;
    Node<T>* back;

public:
    Queue();

    bool isEmpty() const;
    void enqueue(const T& value);
    void dequeue();
    T frontValue() const;
    void display() const;

    ~Queue();
};

#endif 
