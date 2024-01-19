#include "Queue.h"

int main() {
    Queue<int> myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Queue Front: " << myQueue.frontValue() << "\n";
    myQueue.display();

    myQueue.dequeue();
    std::cout << "Queue Front after dequeue: " << myQueue.frontValue() << "\n";
    myQueue.display();

    return 0;
}
