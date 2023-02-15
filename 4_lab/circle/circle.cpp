#ifndef CLION_PROGRAMMING_CIRCLE_C
#define CLION_PROGRAMMING_CIRCLE_C
#include "circle.h"
#include <cmath>
#include <iostream>

CircleClass::CircleClass(double x, double y, int radius) {
    this->set_params(x, y, radius);
}

void CircleClass::set_params(double x, double y, int radius) {
    this->center.x = x;
    this->center.y = y;
    this->radius = radius;
}

double CircleClass::square() {
    return M_PI * pow(this->radius, 2);
}

double CircleClass::perimeter() {
    return 2 * M_PI * this->radius;
}

double CircleClass::mass() {
    return this->square();
}

CVector2D CircleClass::position() {
    return this->center;
}

bool CircleClass::equal(CircleClass& class_1, CircleClass& class_2) const {
    return class_1.mass() == class_2.mass();
}

bool CircleClass::less(CircleClass& class_1, CircleClass& class_2) const{
    return class_1.mass() < class_2.mass();
}

bool CircleClass::operator== (const IPhysObject& ob) const {
    const CircleClass& CC = dynamic_cast<const CircleClass&>(ob);
    return equal(const_cast<CircleClass &>(*this), const_cast<CircleClass &>(CC));
}

bool CircleClass::operator< ( const IPhysObject& ob ) const {
    const CircleClass& CC = dynamic_cast<const CircleClass&>(ob);
    return less(const_cast<CircleClass &>(*this), const_cast<CircleClass &>(CC));
}

void CircleClass::draw() {
    std::cout << "Координаты центра круга: (" << this->center.x << ", " << this->center.y << ")\n";
    std::cout << "Радиус круга: " << this->radius << "\n";
    std::cout << "Периметр круга: " << this->perimeter() << "\n";
    std::cout << "Площадь круга: " << this->square() << "\n";
    std::cout << "Масса круга: " << this->mass() << "\n";
    CVector2D pos = this->position();
    std::cout << "Координаты центра масс: (" << pos.x << ", " << pos.y << ")\n";
}

void CircleClass::initFromDialog() {
    double x, y;
    int r;
    std::cout << "Введите координаты центра круга: " << "\n";
    std::cin >> x >> y;
    std::cout << "Введите радиус круга: " << "\n";
    std::cin >> r;
    this->set_params(x, y, r);
}

const char* CircleClass::classname() {
    return typeid(*this).name();
}

unsigned int CircleClass::size() {
    return sizeof(*this);
}

#endif //CLION_PROGRAMMING_CIRCLE_C