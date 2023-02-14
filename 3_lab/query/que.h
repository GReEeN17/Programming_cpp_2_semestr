#ifndef CLION_PROGRAMMING_QUE_H
#define CLION_PROGRAMMING_QUE_H
#include <iostream>

class Que{
private:
    int que[100];
    int len_que=  0;
    int start = 0;
    int end = 0;
public:
    void add_number(int number);

    void pop_number(int number);

    friend void operator>>(Que& que, int number);

    friend void operator<<(Que& que, int number);
};

#endif //CLION_PROGRAMMING_QUE_H
