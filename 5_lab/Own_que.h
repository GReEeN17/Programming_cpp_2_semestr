#ifndef CLION_PROGRAMMING_OWN_QUE_H
#define CLION_PROGRAMMING_OWN_QUE_H
#include <iostream>
#include "patterns_exceptions.h"

template <class Q>
class queue {
    int len_q;
    int start;
    int end;
    int capacity;
    Q *array;
public:
    queue(int N);
    void enqueue(Q value);
    void dequeue();
    int size();
    bool isEmpty();
    bool isFull();
    void printQueue();
    Q max_elem();
};

template <class Q>
queue<Q>::queue(int N) {
    array = new Q[N];
    start = 0;
    end = -1;
    len_q = 0;
    capacity = N;
}

template <class Q>
void queue<Q>::enqueue(Q value) {
    if (isFull())
        throw QueException("ERROR. Que over flow");
    std::cout << "Inserting " << value << "\n";
    end = (end + 1) % capacity;
    array[end] = value;
    len_q++;
}

template <class Q>
void queue<Q>::dequeue() {
    if (isEmpty())
        throw QueException("ERROR. Out of range");
    std::cout << "Removing " << array[start] << "\n";
    start = (start + 1) % capacity;
    len_q--;
}

template <class Q>
int queue<Q>::size() {
    return len_q;
}

template <class Q>
bool queue<Q>::isEmpty() {
    return (size() == 0);
}

template <class Q>
bool queue<Q>::isFull() {
    return (size() == capacity);
}

template <class Q>
void queue<Q>::printQueue() {
    for (int i = 0; i < len_q; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

template <class Q>
Q queue<Q>::max_elem() {
    if (isEmpty())
        throw QueException("ERROR. Out of range");
    Q max = array[0];
    for (int i = start; i < end; i++) {
        if (array[i] > max) max = array[i];
    }
    return max;
}

#endif //CLION_PROGRAMMING_OWN_QUE_H
