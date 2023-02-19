#ifndef CLION_PROGRAMMING_QUE_H
#define CLION_PROGRAMMING_QUE_H
#include <iostream>

template <class Q>
class Que {
    int len_q;
    int start;
    int end;
    int capacity;
    Q* array;
public:
    Que(int N);
    void push(Q value);
    void pop();
    int size();
    bool is_empty();
    bool is_full();
    Q max_elem();
};

#endif //CLION_PROGRAMMING_QUE_H
