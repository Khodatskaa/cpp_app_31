#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

template <class T>
class Queue {
private:
    Node<T>* front;
    Node<T>* back;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        }
        else {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node<T>* temp = front;
        front = front->next;
        delete temp;
    }

    T frontValue() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T(); 
        }
        else {
            return front->data;
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        }
        else {
            Node<T>* temp = front;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    Queue<T>* clone() const {
        Queue<T>* newList = new Queue<T>();

        Node<T>* temp = front;
        while (temp != nullptr) {
            newList->enqueue(temp->data);
            temp = temp->next;
        }

        return newList;
    }

    Queue<T>* operator+(const Queue<T>& other) const {
        Queue<T>* newQueue = clone();

        Node<T>* temp = other.front;
        while (temp != nullptr) {
            newQueue->enqueue(temp->data);
            temp = temp->next;
        }

        return newQueue;
    }

    Queue<T>* operator*(const Queue<T>& other) const {
        Queue<T>* newQueue = new Queue<T>();

        Node<T>* temp = front;
        while (temp != nullptr) {
            Node<T>* temp2 = other.front;
            while (temp2 != nullptr) {
                if (temp->data == temp2->data) {
                    newQueue->enqueue(temp->data);
                    break;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        return newQueue;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

#endif
