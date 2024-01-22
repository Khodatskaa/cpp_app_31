#include <iostream>
#include "Array.h"

int main() {
    Array<int> intArray;
    intArray.SetSize(5);

    for (int i = 0; i < 5; ++i) {
        intArray.Add(i * 2);
    }


    std::cout << "First Array:" << std::endl;
    std::cout << "Elements: ";
    for (int i = 0; i < intArray.GetSize(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Size: " << intArray.GetSize() << std::endl;
    std::cout << "Upper Bound: " << intArray.GetUpperBound() << std::endl;
    std::cout << std::endl;

    Array<int> anotherIntArray;
    anotherIntArray.SetSize(3);
    for (int i = 0; i < anotherIntArray.GetSize(); ++i) {
        anotherIntArray[i] = i * 3;
    }

    std::cout << "Second Array:" << std::endl;
    std::cout << "Elements: ";
    for (int i = 0; i < anotherIntArray.GetSize(); ++i) {
        std::cout << anotherIntArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Size: " << anotherIntArray.GetSize() << std::endl;
    std::cout << "Upper Bound: " << anotherIntArray.GetUpperBound() << std::endl;
    std::cout << std::endl;

    anotherIntArray.SetSize(5);
    std::cout << "Updated Second Array:" << std::endl;
    std::cout << "Size: " << anotherIntArray.GetSize() << std::endl;
    std::cout << "Upper Bound: " << anotherIntArray.GetUpperBound() << std::endl;
    std::cout << std::endl;

    intArray.Append(anotherIntArray);
    std::cout << "Merged Arrays:" << std::endl;
    std::cout << "Elements: ";
    for (int i = 0; i < intArray.GetSize(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
