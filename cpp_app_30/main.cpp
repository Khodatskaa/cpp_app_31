#include "Array.h"
#include <iostream>

int main() {
    Array<int> arr;

    arr.SetSize(5, 5);
    std::cout << "Array size: " << arr.GetSize() << std::endl;

    for (int i = 0; i < 10; ++i) {
        arr.Add(i);
    }

    std::cout << "Array size after adding 10 elements: " << arr.GetSize() << std::endl;
    std::cout << "Array contents: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    Array<int> arr2;
    arr2.SetSize(3, 3);
    for (int i = 100; i < 106; ++i) {
        arr2.Add(i);
    }

    std::cout << "Second array size: " << arr2.GetSize() << std::endl;
    std::cout << "Second array contents: ";
    for (int i = 0; i < arr2.GetSize(); ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    arr.Append(arr2);
    std::cout << "Array size after appending the second array: " << arr.GetSize() << std::endl;
    std::cout << "Array contents: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
