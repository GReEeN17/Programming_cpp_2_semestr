#ifndef CLION_PROGRAMMING_MENU_4_LAB_C
#define CLION_PROGRAMMING_MENU_4_LAB_C
#include "menu_4_lab.h"
#include "circle/circle.h"
#include "rectangle/rectangle.h"

void Menu4::set_cc() {
    double x, y;
    int r;
    std::cout << "Введите координаты центра круга: " << "\n";
    std::cin >> x >> y;
    std::cout << "Введите радиус круга: " << "\n";
    std::cin >> r;
    //CircleClass* gap_cc = new CircleClass(x, y, r);
    CircleClass gap_cc(x, y, r);
    this->all_circles.insert(gap_cc);
}

void Menu4::set_rc() {
    double x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4;
    std::cout << "Введите координаты всех четырёх вершин: " << "\n";
    std::cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3 >> x_4 >> y_4;
    RectangleClass gap_rc(x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4);
    this->all_rect.insert(gap_rc);
}

void Menu4::draw_cc() {
    for (auto i: this->all_circles) {
        std::cout << "-------------------" << "\n";
        i.draw();
    }
}

void Menu4::draw_rc() {
    for (auto i: this->all_rect) {
        std::cout << "-------------------" << "\n";
        i.draw();
    }
}

void Menu4::per_cc() {
    double sum_p = 0;
    for (auto i: this->all_circles) {
        sum_p += i.perimeter();
    }
    std::cout << "Общий перриметр всей системы: " << sum_p << "\n";
}

void Menu4::per_rc() {
    double sum_p = 0;
    for (auto i: this->all_rect) {
        sum_p += i.perimeter();
    }
    std::cout << "Общий перриметр всей системы: " << sum_p << "\n";
}

void Menu4::sq_cc() {
    double sum_sq = 0;
    for (auto i: this->all_circles) {
        sum_sq += i.square();
    }
    std::cout << "Общая площадь всей системы: " << sum_sq << "\n";
}

void Menu4::sq_rc() {
    double sum_sq = 0;
    for (auto i: this->all_rect) {
        sum_sq += i.square();
    }
    std::cout << "Общая площадь всей системы: " << sum_sq << "\n";
}

void Menu4::cm_cc() {
    double x = 0, y = 0, p = 0;
    for (auto i: this->all_circles) {
        CVector2D pos = i.position();
        x += pos.x * i.mass();
        y += pos.y * i.mass();
        p += i.mass();
    }
    std::cout << "Центр масс всей системы: (" << x / p << ", " << y / p << ")\n";
}

void Menu4::cm_rc() {
    double x = 0, y = 0, p = 0;
    for (auto i: this->all_rect) {
        CVector2D gap_center = i.position();
        x += gap_center.x * i.mass();
        y += gap_center.y * i.mass();
        p += i.mass();
    }
    std::cout << "Центр масс всей системы: (" << x / p << ", " << y / p << ")\n";
}

void Menu4::sz_cc() {
    unsigned int sum_sz = 0;
    for (auto i: this->all_circles) {
        sum_sz += i.size();
    }
    std::cout << "Общий размер памяти, занимаемой системой: " << sum_sz << "\n";
}

void Menu4::sz_rc() {
    unsigned int sum_sz = 0;
    for (auto i: this->all_rect) {
        sum_sz += i.size();
    }
    std::cout << "Общий размер памяти, занимаемой системой: " << sum_sz << "\n";
}

#endif //CLION_PROGRAMMING_MENU_4_LAB_C