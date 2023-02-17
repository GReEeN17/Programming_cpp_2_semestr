#ifndef CLION_PROGRAMMING_MENU_4_LAB_H
#define CLION_PROGRAMMING_MENU_4_LAB_H
#include "circle/circle.h"
#include "rectangle/rectangle.h"

class Menu4 {
private:
    std::set<CircleClass*> all_circles;
    std::set<RectangleClass*> all_rect;
public:
    static void set_cc(std::set<CircleClass*> &all_circles);

    static void set_rc(std::set<RectangleClass*> &all_rect);

    static void draw_cc(std::set<CircleClass*> &all_circles);

    static void draw_rc(std::set<RectangleClass*> &all_rect);

    static void per_cc(std::set<CircleClass*> &all_circles);

    static void per_rc(std::set<RectangleClass*> &all_rect);

    static void sq_cc(std::set<CircleClass*> &all_circles);

    static void sq_rc(std::set<RectangleClass*> &all_rect);

    static void cm_cc(std::set<CircleClass*> &all_circles);

    static void cm_rc(std::set<RectangleClass*> &all_rect);

    static void sz_cc(std::set<CircleClass*> &all_circles);

    static void sz_rc(std::set<RectangleClass*> &all_rect);
};

#endif //CLION_PROGRAMMING_MENU_4_LAB_H
