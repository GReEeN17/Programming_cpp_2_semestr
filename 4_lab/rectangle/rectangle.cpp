#ifndef CLION_PROGRAMMING_RECTANGLE_C
#define CLION_PROGRAMMING_RECTANGLE_C
#include "rectangle.h"
#include <iostream>
#include <cmath>

RectangleClass::RectangleClass(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3, double x_4, double y_4) {
    this->set_params(x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4);
}

void RectangleClass::set_params(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3, double x_4, double y_4) {
    this->fir_vert.x = x_1, this->fir_vert.y = y_1;
    this->sec_vert.x = x_2; this->sec_vert.y = y_2;
    this->thi_vert.x = x_3; this->thi_vert.y = y_3;
    this->fth_vert.x = x_4; this->fth_vert.y = y_4;
    this->set_sides();
}

void RectangleClass::set_sides() {
    this->fir_side = sqrt(pow(this->fir_vert.x - this->sec_vert.x, 2) + pow(this->fir_vert.y - this->sec_vert.y, 2));
    this->sec_side = sqrt(pow(this->fir_vert.x - this->fth_vert.x, 2) + pow(this->fir_vert.y - this->fth_vert.y, 2));
}

double RectangleClass::square() {
    return this->fir_side * this->sec_side;
}

double RectangleClass::perimeter() {
    return 2 * (this->fir_side + this->sec_side);
}

double RectangleClass::mass() {
    return this->square();
}

CVector2D RectangleClass::position() {
    CVector2D gap_pos{};
    gap_pos.x = (this->fir_vert.x + this->thi_vert.x) / 2;
    gap_pos.y = (this->fir_vert.y + this->thi_vert.y) / 2;
    return gap_pos;
}

bool RectangleClass::operator== (const IPhysObject& ob ) const {
    const auto& CC = dynamic_cast<const RectangleClass&>(ob);
    return equal(const_cast<RectangleClass &>(*this), const_cast<RectangleClass &>(CC));
}

bool RectangleClass::operator< ( const IPhysObject& ob ) const {
    const auto& CC = dynamic_cast<const RectangleClass&>(ob);
    return less(const_cast<RectangleClass &>(*this), const_cast<RectangleClass &>(CC));
}

bool RectangleClass::equal(RectangleClass& class_1, RectangleClass& class_2) {
    return class_1.mass() == class_2.mass();
}

bool RectangleClass::less(RectangleClass& class_1, RectangleClass& class_2) {
    return class_1.mass() < class_2.mass();
}

void RectangleClass::draw() {
    std::cout << "Длины сторон прямоугольника: " << this->fir_side << ", " << this->sec_side << "\n";
    std::cout << "Периметр прямоугольника: " << this->perimeter() << "\n";
    std::cout << "Площадь прямоугольника: " << this->square() << "\n";
    std::cout << "Масса прямоугольника: " << this->mass() << "\n";
    CVector2D center = this->position();
    std::cout << "Координаты центра массы прямоугольника: (" << center.x << ", " << center.y << ")\n";
    std::cout << "Класс прямоугольника" << this->classname() << "\n";
    std::cout << "Размер занимаемой памяти прямоугольником" << this->size() << "\n";
}

void RectangleClass::initFromDialog() {
    double x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4;
    std::cout << "Введите координаты всех четырёх вершин: " << "\n";
    std::cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3 >> x_4 >> y_4;
    set_params(x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4);
}

const char* RectangleClass::classname(){
    return typeid(*this).name();
}

unsigned int RectangleClass::size() {
    return sizeof(*this);
}

#endif //CLION_PROGRAMMING_RECTANGLE_C