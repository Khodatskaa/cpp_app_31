#ifndef Node_h
#define Node_h

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value);
};

#endif
