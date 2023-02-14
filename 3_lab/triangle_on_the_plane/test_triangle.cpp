#include "triangle.h"
#include <iostream>

inline void test_triangle() {
    Triangle tr_1(0, 0, 0, 4, 3, 0);
    Triangle tr_2(-1, -1, -1, -5, -4, -1);
    Triangle tr_3(1, 1, 1, 2, 2, 1);
    if (tr_1 == tr_2) std::cout << "Треугольники 1 и 2 равны" << "\n";
    if (tr_1 != tr_3) std::cout << "Треугольники 1 и 3 не равны" << "\n";
    if (tr_2 != tr_3) std::cout << "Треугольники 1 и 3 не равны" << "\n";
    if (tr_2 > tr_3) std::cout << "Треугольник 2 больше 3" << "\n";
    if (tr_1 > tr_3) std::cout << "Треугольник 1 больше 3" << "\n";
    if (tr_3 < tr_1) std::cout << "Треугольник 3 меньше 1" << "\n";
    if (tr_3 < tr_2) std::cout << "Треугольник 3 меньше 2" << "\n";
}