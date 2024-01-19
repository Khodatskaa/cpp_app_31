#include "List.h"
#include <iostream>

int main() {
    List myList;

    myList.AddToHead(3);
    myList.AddToTail(5);
    myList.AddToHead(1);

    myList.Show(); 

    myList.InsertAtPosition(2, 2);
    myList.Show();

    myList.DeleteAtPosition(3);
    myList.Show(); 

    int searchResult = myList.SearchElement(2);
    if (searchResult != -1) {
        std::cout << "Element 2 found at position: " << searchResult << std::endl;
    }
    else {
        std::cout << "Element 2 not found\n";
    }

    int replaceCount = myList.ReplaceElement(5, 10);
    if (replaceCount != -1) {
        std::cout << "Replaced " << replaceCount << " occurrences of 5 with 10\n";
        myList.Show(); 
    }
    else {
        std::cout << "Failed to replace element\n";
    }

    myList.ReverseList();
    myList.Show();

    myList.DeleteAll();

    return 0;
}
