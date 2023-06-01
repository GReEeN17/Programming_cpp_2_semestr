#ifndef CLION_PROGRAMMING_TRIANGLE_C
#define CLION_PROGRAMMING_TRIANGLE_C
#include <iostream>
#include <cmath>
#include "triangle.h"

Triangle::Triangle(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3) {
    dot a(x_1, y_1);
    dot b(x_2, y_2);
    dot c(x_3, y_3);
    this->fir_vert = a;
    this->sec_vert = b;
    this->thi_vert = c;
    set_sides();
    set_square();
}

void Triangle::set_sides() {
    this->fir_side = sqrt(pow(this->fir_vert.x - this->sec_vert.x, 2) + pow(this->fir_vert.y - this->sec_vert.y, 2));
    this->sec_side = sqrt(pow(this->sec_vert.x - this->thi_vert.x, 2) + pow(this->sec_vert.y - this->thi_vert.y, 2));
    this->thi_side = sqrt(pow(this->thi_vert.x - this->fir_vert.x, 2) + pow(this->thi_vert.y - this->fir_vert.y, 2));
}

void Triangle::set_square() {
    double p = (this->fir_side + this->sec_side + this->thi_side) / 2;
    this->square = sqrt(p * (p - this->fir_side) * (p - this->sec_side) * (p - this->thi_side));
}

bool operator==(Triangle& first_tr, Triangle& second_tr) {
    return first_tr.square == second_tr.square;
}

bool operator!=(Triangle& first_tr, Triangle& second_tr) {
    return first_tr.square != second_tr.square;
}

bool operator<(Triangle& first_tr, Triangle& second_tr) {
    return first_tr.square < second_tr.square;
}

bool operator>(Triangle& first_tr, Triangle& second_tr) {
    return first_tr.square > second_tr.square;
}

void Triangle::add_vector(int x, int y) {
    this->fir_vert.x = this->fir_vert.x + x;
    this->fir_vert.y = this->fir_vert.y + y;
    this->sec_vert.x = this->sec_vert.x + x;
    this->sec_vert.y = this->sec_vert.y + y;
    this->thi_vert.x = this->thi_vert.x + x;
    this->thi_vert.y = this->thi_vert.y + y;
}



#endif //CLION_PROGRAMMING_TRIANGLE_C
