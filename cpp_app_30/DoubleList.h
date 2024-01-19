#ifndef DoubleList_h
#define DoubleList_h

#include <iostream>
#include <string>

class DoubleList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };

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
