#ifndef CLION_PROGRAMMING_MENU_4_LAB_C
#define CLION_PROGRAMMING_MENU_4_LAB_C
#include "circle/circle.h"
#include "rectangle/rectangle.h"

void set_cc() {
    double x, y;
    int r;
    std::cout << "Введите координаты центра круга: " << "\n";
    std::cin >> x >> y;
    std::cout << "Введите радиус круга: " << "\n";
    std::cin >> r;
    CircleClass gap_cc(x, y, r);
}

void set_rc() {
    double x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4;
    std::cout << "Введите координаты всех четырёх вершин: " << "\n";
    std::cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3 >> x_4 >> y_4;
    RectangleClass gap_rc(x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4);
}

void draw_cc() {
    CircleClass::draw_all_circles();
}

void draw_rc() {
    RectangleClass::draw_all_rects();
}

void per_cc() {
    CircleClass::summ_perimetr();
}

void per_rc() {
    RectangleClass::summ_perimetr();
}

void sq_cc() {
    CircleClass::summ_square();
}

void sq_rc() {
    RectangleClass::summ_square();
}

void cm_cc() {
    CircleClass::center_mass_all_circles();
}

void cm_rc() {
    RectangleClass::center_mass_all_rects();
}

void sz_cc() {
    CircleClass::summ_size();
}

void sz_rc() {
    RectangleClass::summ_size();
}

#endif //CLION_PROGRAMMING_MENU_4_LAB_C