#ifndef DoubleList_h
#define DoubleList_h

#include <iostream>
#include <string>

class DoubleList {
private:
    class Node;

    Node* head;
    Node* tail;

public:
    DoubleList();
    ~DoubleList();

    void AddToHead(int value);
    void AddToTail(int value);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show();
};

#endif
