#ifndef CLION_PROGRAMMING_QUE_H
#define CLION_PROGRAMMING_QUE_H
#include <iostream>

template <size_t N, typename Q>
class Que {
public:
    Que();
    ~Que();
    void push(const Q& value);
    void pop();
private:
    int len_q;
    int start;
    int end;
    Q* array;
};

#endif //CLION_PROGRAMMING_QUE_H
