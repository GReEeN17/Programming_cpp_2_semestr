#include <iostream>
#include "CircularBuffer.h"

using namespace std;

inline int mainLab7() {
    CircularBuffer<int> circularBuffer(3);

    auto iterator = CircularBuffer<int>::Iterator(circularBuffer.begin());
    circularBuffer.pushFront(1);
    circularBuffer.print();
    cout << *iterator << "\n";
    circularBuffer.pushFront(2);
    ++iterator;
    circularBuffer.print();
    circularBuffer.insert(iterator, 8);
    return 0;
}