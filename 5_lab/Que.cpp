#ifndef CLION_PROGRAMMING_QUE_C
#define CLION_PROGRAMMING_QUE_C
#include <iostream>
#include "Que.h"
#include "patterns_exceptions.h"

template <size_t N, typename Q>
Que<N, Q>::Que() {
    this->array = new Q[N];
    this->start = 0;
    this->end = 0;
    this->len_q = 0;
}

template <size_t N, typename Q>
Que<N, Q>::~Que() {
    delete[] this->array;
}

template <size_t N, typename Q>
void Que<N, Q>::push(const Q &value) {
    if (this->len_q == N) {
        throw QueException("ERROR. Que over flow");
    } else {
        this->array[end] = value;
        this->end++;
        this->len_q++;
    }
}

template <size_t N, typename Q>
void Que<N, Q>::pop() {
    if (this->len_q == 0) {
        throw QueException("ERROR. Out of range");
    } else {
        this->array[this->start++];
    }
}

template<typename Q>
Q Max(Q* array) {
    Q max = array[0];
    for (size_t i = 1; i < sizeof(array); i++) {
        if (array[i] > max) max = array[i];
    }
    return max;
}

#endif //CLION_PROGRAMMING_QUE_C