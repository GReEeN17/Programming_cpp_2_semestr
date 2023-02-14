#include <iostream>
#include "que.h"

inline void test_que() {
    std::cout << "!!!!!!!!!!!!!!!!!!" << "\n";
    Que testing_que;
    testing_que.add_number(13);
    testing_que.print_que();
    testing_que.add_number(8);
    testing_que.print_que();
    testing_que.pop_number();
    testing_que.print_que();
    testing_que.pop_number();
    testing_que.print_que();
    testing_que.pop_number();
    testing_que.print_que();
    std::cout << "!!!!!!!!!!!!!!!!!!" << "\n";
    testing_que<<13;
    testing_que.print_que();
    testing_que<<8;
    testing_que.print_que();
    testing_que>>13;
    testing_que.print_que();
    testing_que>>8;
    testing_que.print_que();
    testing_que>>10;
    testing_que.print_que();
}
