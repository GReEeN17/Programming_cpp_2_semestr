#ifndef CLION_PROGRAMMING_RECTANGLE_C
#define CLION_PROGRAMMING_RECTANGLE_C
#include "rectangle.h"
#include <iostream>

RectangleClass::RectangleClass(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3, double x_4, double y_4) {}

void RectangleClass::set_params(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3, double x_4, double y_4) {}

void RectangleClass::set_sides() {}

double RectangleClass::square() {}

double RectangleClass::perimeter() {}

double RectangleClass::mass() {}

CVector2D RectangleClass::position() {}

bool RectangleClass::operator== (const IPhysObject& ob ) const {}

bool RectangleClass::operator< ( const IPhysObject& ob ) const {}

bool RectangleClass::equal(RectangleClass& class_1, RectangleClass& class_2) const {}

bool RectangleClass::less(RectangleClass& class_1, RectangleClass& class_2) const {}

void RectangleClass::draw() {}

void RectangleClass::initFromDialog() {}

const char* RectangleClass::classname(){}

unsigned int RectangleClass::size() {}


#endif //CLION_PROGRAMMING_RECTANGLE_C