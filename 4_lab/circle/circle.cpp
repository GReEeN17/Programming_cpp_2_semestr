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
    all_circles.push_back(this);
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
    std::cout << "Класс круга" << this->classname() << "\n";
    std::cout << "Размер занимаемой памяти кругом" << this->size() << "\n";
}

void CircleClass::initFromDialog() {
    double x, y;
    int r;
    std::cout << "Введите координаты центра круга: " << "\n";
    std::cin >> x >> y;
    std::cout << "Введите радиус круга: " << "\n";
    std::cin >> r;
    CircleClass CC(x, y, r);
    all_circles.push_back(&CC);
    len_all_classes++;
}

const char* CircleClass::classname() {
    return typeid(*this).name();
}

unsigned int CircleClass::size() {
    return sizeof(*this);
}

void CircleClass::init_class() {
    this->initFromDialog();
}

void CircleClass::draw_all_circles() {
    for (int i = 0; i < len_all_classes; i++) {
        std::cout << "-------------------" << "\n";
        all_circles[i]->draw();
    }
}

void CircleClass::summ_perimetr() {
    double sum_p = 0;
    for (int i = 0; i < len_all_classes; i++) {
        sum_p += all_circles[i]->perimeter();
    }
    std::cout << "Общий перриметр всей системы: " << sum_p << "\n";
}

void CircleClass::summ_square() {
    double sum_sq = 0;
    for (int i = 0; i < len_all_classes; i++) {
        sum_sq += all_circles[i]->square();
    }
    std::cout << "Общая площадь всей системы: " << sum_sq << "\n";
}

void CircleClass::center_mass_all_circles() {
    if (len_all_classes == 0) {
        std::cout << "Центра массы нет, так как нет объектов" << "\n";
    } else if (len_all_classes == 1) {
        std::cout << "Координаты центра массы: (" << all_circles[0]->center.x << ", " << all_circles[0]->center.y << ")\n";
    } else {
        CVector2D fir_center = all_circles[0]->position();
        CVector2D sec_center;
        for (int i = 1; i < len_all_classes; i++) {
            sec_center = all_circles[i]->position();
            fir_center.x = (fir_center.x + sec_center.x) / 2;
            fir_center.y = (fir_center.y + sec_center.y) / 2;
        }
        std::cout << "Координаты центра массы: (" << fir_center.x << ", " << fir_center.y << ")\n";
    }
}

void CircleClass::summ_size() {
    unsigned int sum_sz = 0;
    for (int i = 0; i < len_all_classes; i++) {
        sum_sz += all_circles[i]->size();
    }
    std::cout << "Общий размер памяти, занимаемой системой: " << sum_sz << "\n";
}

void sort_figures();

#endif //CLION_PROGRAMMING_CIRCLE_C