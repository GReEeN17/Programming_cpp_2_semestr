#ifndef CLION_PROGRAMMING_CIRCLE_H
#define CLION_PROGRAMMING_CIRCLE_H
#include "../basic_classes.h"
#include <vector>
#include <iostream>
#include <set>

class CircleClass : public IGeoFig, public IDialogInitiable, public IPhysObject, public IPrintable, public BaseCObject{
private:
    CVector2D center;
    int radius;
public:
    static std::set<CircleClass*> all_circles;

    CircleClass(double x, double y, int radius);

    void set_params(double x, double y, int radius);

    double square() override;

    double perimeter() override;

    double mass() override;

    CVector2D position() override;

    bool operator== (const IPhysObject& ob ) const override;

    bool operator< ( const IPhysObject& ob ) const override;

    bool equal(CircleClass& class_1, CircleClass& class_2) const;

    bool less(CircleClass& class_1, CircleClass& class_2) const;

    void draw() override;

    void initFromDialog() override;

    const char* classname() override;

    unsigned int size() override;

    static void draw_all_circles();

    static void summ_perimetr();

    static void summ_square();

    static void center_mass_all_circles();

    static void summ_size();
};

#endif //CLION_PROGRAMMING_CIRCLE_H
