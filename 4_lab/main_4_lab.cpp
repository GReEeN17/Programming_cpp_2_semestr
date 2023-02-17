#include <iostream>
#include "menu_4_lab.h"
#include "circle/circle.h"
#include "rectangle/rectangle.h"

inline void main_4_lab() {
    std::string s;
    Menu4 menu;
    while(getline(std::cin, s)) {
        if (s == "/set_cc") {
            menu.set_cc();
        } else if (s == "/set_rc") {
            menu.set_rc();
        } else if (s == "/draw_cc") {
            menu.draw_cc();
        } else if (s == "/draw_rc") {
            menu.draw_rc();
        } else if (s == "/per_cc") {
            menu.per_cc();
        } else if (s == "/per_rc") {
            menu.per_rc();
        } else if (s == "/sq_cc") {
            menu.sq_cc();
        } else if (s == "/sq_rc") {
            menu.sq_rc();
        } else if (s == "/cm_cc") {
            menu.cm_cc();
        } else if (s == "/cm_rc") {
            menu.cm_rc();
        } else if (s == "/sz_cc") {
            menu.sz_cc();
        } else if (s == "/sz_rc") {
            menu.sz_rc();
        }
    }
}