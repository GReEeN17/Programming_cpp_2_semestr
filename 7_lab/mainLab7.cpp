#include <iostream>
#include "CircularBuffer.h"

using namespace std;

inline int mainLab7() {
    CircularBuffer<int> circularBuffer(10);

    auto iterator = CircularBuffer<int>::Iterator(circularBuffer.begin());
    circularBuffer.pushBack(1);
    circularBuffer.print();
    cout << *iterator << "\n";
    circularBuffer.pushBack(3);
    ++iterator;
    circularBuffer.print();
    circularBuffer.insert(iterator, 2);
    circularBuffer.print();
    circularBuffer.insert(iterator, 5);
    circularBuffer.print();
    circularBuffer.remove(iterator);
    circularBuffer.print();
    --iterator;
    circularBuffer.remove(iterator);
    circularBuffer.print();
    circularBuffer.pushBack(8);
    circularBuffer.print();
    circularBuffer.pushFront(7);
    circularBuffer.print();
    circularBuffer.pushBack(9);
    circularBuffer.print();
    circularBuffer.pushFront(1);
    circularBuffer.print();
    circularBuffer.popFront();
    circularBuffer.print();
    circularBuffer.popBack();
    circularBuffer.print();
    cout << circularBuffer.getSize() << "\n";
    cout << circularBuffer.getCapacity() << "\n";
    cout << circularBuffer[1] << "\n";
    return 0;
}