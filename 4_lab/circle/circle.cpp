#ifndef CLION_PROGRAMMING_CIRCLE_C
#define CLION_PROGRAMMING_CIRCLE_C
#include "circle.h"
#include <cmath>

CircleClass::CircleClass(double x, double y, int radius) {
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

bool CircleClass::operator== ( const IPhysObject& ob) const {
    const CircleClass& CC = dynamic_cast<const CircleClass&>(ob);
}



#endif //CLION_PROGRAMMING_CIRCLE_C