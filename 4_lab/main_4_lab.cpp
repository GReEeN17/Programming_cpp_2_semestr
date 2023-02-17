#include <iostream>
#include "menu_4_lab.h"
#include "circle/circle.h"
#include "rectangle/rectangle.h"

inline void main_4_lab() {
    static std::set<CircleClass*> all_circles;
    static std::set<RectangleClass*> all_rect;
    CircleClass gap_cc(1, 2, 3);
    all_circles.insert(&gap_cc);
    CircleClass gap_cc_1(4, 5, 6);
    all_circles.insert(&gap_cc_1);
    CircleClass gap_cc_2(6, 7, 8);
    all_circles.insert(&gap_cc_2);
    std::string s;
    Menu4 menu;
    while(getline(std::cin, s)) {
        if (s == "/set_cc") {
            Menu4::set_cc(all_circles);
        } else if (s == "/set_rc") {
            Menu4::set_rc(all_rect);
        } else if (s == "/draw_cc") {
            Menu4::draw_cc(all_circles);
        } else if (s == "/draw_rc") {
            Menu4::draw_rc(all_rect);
        } else if (s == "/per_cc") {
            Menu4::per_cc(all_circles);
        } else if (s == "/per_rc") {
            Menu4::per_rc(all_rect);
        } else if (s == "/sq_cc") {
            Menu4::sq_cc(all_circles);
        } else if (s == "/sq_rc") {
            Menu4::sq_rc(all_rect);
        } else if (s == "/cm_cc") {
            Menu4::cm_cc(all_circles);
        } else if (s == "/cm_rc") {
            Menu4::cm_rc(all_rect);
        } else if (s == "/sz_cc") {
            Menu4::sz_cc(all_circles);
        } else if (s == "/sz_rc") {
            Menu4::sz_rc(all_rect);
        }
    }
}