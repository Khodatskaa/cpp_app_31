#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <string>	

template <class T>
class Queue{
private:
    class Node;

    Node* front;
    Node* back;

public:
    Queue();

    void queue(const T& value);
    void queue();
    T frontElement() const;
    bool isEmpty() const;

    ~Queue();
};

#endif 
