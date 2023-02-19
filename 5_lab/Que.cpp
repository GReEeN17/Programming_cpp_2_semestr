#ifndef CLION_PROGRAMMING_QUE_C
#define CLION_PROGRAMMING_QUE_C
#include <iostream>
#include "Que.h"
#include "patterns_exceptions.h"

template <class Q>
Que<Q>::Que(int N) {
    array = new Q[N];
    start = 0;
    end = -1;
    len_q = 0;
    capacity = N;
}

template <class Q>
void Que<Q>::push(Q value) {
    if (is_full())
        throw QueException("ERROR. Que over flow");
    end = (end + 1) % capacity;
    array[end] = value;
    len_q++;
}

template <class Q>
void Que<Q>::pop() {
    if (is_empty())
        throw QueException("ERROR. Out of range");
    start = (start + 1) % capacity;
    len_q--;
}

template <class Q>
int Que<Q>::size() {
    return len_q;
}

template <class Q>
bool Que<Q>::is_empty() {
    return (size() == 0);
}

template <class Q>
bool Que<Q>::is_full() {
    return (size() == capacity);
}

template <class Q>
Q Que<Q>::max_elem() {
    if (is_empty())
        throw QueException("ERROR. Out of range");
    Q max = array[0];
    for (int i = 1; i < len_q; i++) {
        if (array[i] > max) max = array[i];
    }
    return max;
}

#endif //CLION_PROGRAMMING_QUE_C