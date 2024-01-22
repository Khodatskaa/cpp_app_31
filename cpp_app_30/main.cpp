#include "Queue.h"

int main() {
    Queue<int> queue1;
    Queue<int> queue2;

    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);

    cout << "Queue 1: ";
    queue1.display();

    queue2.enqueue(2);
    queue2.enqueue(3);
    queue2.enqueue(4);

    cout << "Queue 2: ";
    queue2.display();

    Queue<int>* clonedQueue = queue1.clone();
    cout << "Cloned Queue: ";
    clonedQueue->display();

    Queue<int>* mergedQueue = queue1 + queue2;
    cout << "Merged Queue: ";
    mergedQueue->display();

    Queue<int>* commonQueue = queue1 * queue2;
    cout << "Common Queue: ";
    commonQueue->display();

    delete clonedQueue;
    delete mergedQueue;
    delete commonQueue;

    return 0;
}
