#include "Queue.h"

template <typename T>
Queue<T>::Queue() : front(nullptr), back(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    Node<T>* newNode = new Node<T>(value);

    if (isEmpty()) {
        front = back = newNode;
    }
    else {
        back->next = newNode;
        newNode->prev = back;
        back = newNode;
    }
}

template <typename T>
void Queue<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }

    Node<T>* temp = front;
    front = front->next;

    if (front != nullptr) {
        front->prev = nullptr;
    }
    else {
        back = nullptr;
    }

    delete temp;
}

template <typename T>
T Queue<T>::frontValue() const {
    if (isEmpty()) {
        std::cout << "Queue is empty. No front value.\n";
        exit;
    }

    return front->data;
}

template <typename T>
void Queue<T>::display() const {
    Node<T>* current = front;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

template class Queue<int>;
