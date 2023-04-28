#include <iostream>
#include "CircularBuffer.h"

using namespace std;

inline int mainLab7() {
    CircularBuffer<int> circularBuffer(3);

    auto iterator = CircularBuffer<int>::Iterator(circularBuffer.start());
    circularBuffer.pushFront(1);
    cout << *iterator << "\n";
    circularBuffer.pushFront(2);
    ++iterator;
    ++iterator;
    cout << *iterator << "\n";
    circularBuffer.pushFront(3);
    circularBuffer.print();
    circularBuffer.setCapacity(4);
    circularBuffer.print();
    circularBuffer.pushFront(4);
    circularBuffer.print();
    circularBuffer.pushFront(5);
    circularBuffer.print();
    circularBuffer.pushBack(6);
    circularBuffer.print();
    circularBuffer.pushBack(7);
    circularBuffer.print();
    circularBuffer.pushBack(8);
    circularBuffer.print();
    circularBuffer.pushBack(9);
    circularBuffer.print();
    circularBuffer.pushBack(10);
    circularBuffer.print();

    cout << circularBuffer.getCapacity() << "\n";
    cout << circularBuffer.getSize() << "\n";
    circularBuffer.popBack();
    circularBuffer.popFront();

    cout << *iterator << "\n";
    return 0;
}