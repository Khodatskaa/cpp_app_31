#include "DoubleList.h"

int main() {
        DoubleList myList;

        myList.AddToHead(3);
        myList.AddToTail(5);
        myList.AddToHead(1);

        myList.Show();

        myList.DeleteFromHead();
        myList.DeleteFromTail();

        myList.Show();

        myList.DeleteAll();

        myList.Show();

        return 0;
}