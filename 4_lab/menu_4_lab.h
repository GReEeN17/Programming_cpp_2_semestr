#ifndef CLION_PROGRAMMING_MENU_4_LAB_H
#define CLION_PROGRAMMING_MENU_4_LAB_H
#include "circle/circle.h"
#include "rectangle/rectangle.h"

class Menu4 {
private:
    std::set<CircleClass> all_circles;
    std::set<RectangleClass> all_rect;
public:
    void set_cc();

    void set_rc();

    void draw_cc();

    void draw_rc();

    void per_cc();

    void per_rc();

    void sq_cc();

    void sq_rc();

    void cm_cc();

    void cm_rc();

    void sz_cc();

    void sz_rc();
};

#endif //CLION_PROGRAMMING_MENU_4_LAB_H
