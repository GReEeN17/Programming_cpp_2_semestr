#ifndef CLION_PROGRAMMING_QUE_C
#define CLION_PROGRAMMING_QUE_C
#include <iostream>
#include "que.h"

void Que::add_number(int number) {
    if (this->len_que != 0 && this->start == this->end) {
        std::cout << "Очередь полностью заполнена, нельзя больше добавлять элементы" << "\n";
    } else {
        std::cout << "Добавлен элемент: " << number << "\n";
        this->que[end] = number;
        this->end++;
        this->len_que++;
    }
}

void Que::pop_number(int number) {
    if (this->len_que == 0) {
        std::cout << "Очередь пуста, нельзя удалить элемент" << "\n";
    } else {
        std::cout << "Удалён элемент: " << this->que[start] << "\n";
        this->que[start] = 0;
        this->start++;
        this->len_que--;
    }
}

void operator>>(Que& que, int number) {
    que.pop_number(number);
}

void operator<<(Que& que, int number) {
    que.add_number(number);
}

#endif //CLION_PROGRAMMING_QUE_C