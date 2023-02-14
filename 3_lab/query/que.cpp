#ifndef CLION_PROGRAMMING_QUE_C
#define CLION_PROGRAMMING_QUE_C
#include <iostream>
#include "que.h"

void Que::add_number(int number) {
    if (this->len_que != 0 && (this->start % 100) == (this->end % 100)) {
        std::cout << "Очередь полностью заполнена, нельзя больше добавлять элементы" << "\n";
    } else {
        std::cout << "Добавлен элемент: " << number << "\n";
        this->que[end % 100] = number;
        this->end++;
        this->len_que++;
    }
}

void Que::pop_number() {
    if (this->len_que == 0) {
        std::cout << "Очередь пуста, нельзя удалить элемент" << "\n";
    } else {
        std::cout << "Удалён элемент: " << this->que[start % 100] << "\n";
        this->que[start % 100] = 0;
        this->start++;
        this->len_que--;
    }
}

void Que::print_que() {
    for (int i = this->start; i < this->end; i++) {
        std::cout << this->que[i] << " ";
    }
    std::cout << "\n" << "----------------------" << "\n";
}

void operator>>(Que& que, int number) {
    que.pop_number();
}

void operator<<(Que& que, int number) {
    que.add_number(number);
}

#endif //CLION_PROGRAMMING_QUE_C