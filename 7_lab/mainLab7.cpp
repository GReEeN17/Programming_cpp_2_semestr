#include <iostream>
#include "CircularBuffer.h"

using namespace std;

inline int mainLab7() {
    CircularBuffer<int> circularBuffer(3);
    circularBuffer.pushFront(1);
    circularBuffer.pushFront(2);
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
}