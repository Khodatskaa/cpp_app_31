#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include "Node.h"

template <typename T>
class Array {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    int capacity;
    int grow;

public:
    Array() {
        head = nullptr;
        tail = nullptr;
        size = 0;
        capacity = 0;
        grow = 0;
    }

    int GetSize() const {
        return size;
    }

    int GetUpperBound() const {
        return size - 1;
    }

    void SetSize(int newSize, int newGrow = 1) {
        if (newSize == size) {
            return;
        }

        if (newSize < size) {
            Node<T>* current = tail;

            while (size > newSize) {
                Node<T>* prev = current->prev;
                delete current;
                current = prev;
                size--;
            }

            tail = current;
            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
        }
        else {
            int elementsToAdd = newSize - size;

            if (elementsToAdd > grow) {
                grow = elementsToAdd;  
            }

            for (int i = 0; i < elementsToAdd; ++i) {
                Add(T());  
            }
        }
    }


    void Add(const T& element) {
        if (size + 1 > capacity) {
            SetSize(size + grow);
        }

        Node<T>* newNode = new Node<T>;
        newNode->data = element;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail) {
            tail->next = newNode;
        }
        else {
            head = newNode;
        }

        tail = newNode;
        size++;
    }

    void Append(const Array<T>& other) {
        int newSize = size + other.GetSize();
        SetSize(newSize);

        Node<T>* current = other.head;

        while (current) {
            Add(current->data);
            current = current->next;
        }
    }

    void InsertAt(int index, const T& element) {
        if (index >= 0 && index < size) {
            if (size + 1 > capacity) {
                SetSize(size + grow);
            }

            Node<T>* current = head;

            for (int i = 0; i < index; ++i) {
                current = current->next;
            }

            Node<T>* newNode = new Node<T>;
            newNode->data = element;
            newNode->prev = current->prev;
            newNode->next = current;

            if (newNode->prev) {
                newNode->prev->next = newNode;
            }
            else {
                head = newNode;
            }

            current->prev = newNode;
            size++;
        }
    }

    void RemoveAt(int index) {
        if (index >= 0 && index < size) {
            if (index == 0) {
                Node<T>* oldHead = head;
                head = head->next;

                if (head) {
                    head->prev = nullptr;
                }

                delete oldHead;
            }
            else if (index == size - 1) {
                Node<T>* oldTail = tail;
                tail = tail->prev;

                if (tail) {
                    tail->next = nullptr;
                }

                delete oldTail;
            }
            else {
                Node<T>* current = head;

                for (int i = 0; i < index; ++i) {
                    current = current->next;
                }

                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }

            size--;
        }
        else {
        }
    }

    void FreeExtra() {
        if (size < capacity) {
            SetSize(size);
        }
    }

    void RemoveAll() {
        Node<T>* current = head;

        while (current) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
        capacity = 0;
    }


    void SetAt(int index, const T& value) {
        Node<T>* current = head;

        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->data = value;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    T GetAt(int index) const {
        if (index >= 0 && index < size) {
            Node<T>* current = head;

            for (int i = 0; i < index; ++i) {
                current = current->next;
            }

            return current->data;
        }
        else {
            return T();
        }
    }

    T* GetData() const {
        if (size == 0) {
            return nullptr; 
        }

        T* data = new T[size];
        Node<T>* current = head;
        for (int i = 0; i < size; ++i) {
            data[i] = current->data;
            current = current->next;
        }

        return data;
    }

    T& operator[](int index) {
        Node<T>* current = head;

        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->data;
    }

    const T& operator[](int index) const {
        Node<T>* current = head;

        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->data;
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            RemoveAll();

            Node<T>* current = other.head;

            while (current) {
                Add(current->data);
                current = current->next;
            }
        }

        return *this;
    }

    ~Array() {
        RemoveAll();
    }
};

#endif
