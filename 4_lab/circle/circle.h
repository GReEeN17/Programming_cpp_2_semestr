#ifndef CLION_PROGRAMMING_CIRCLE_H
#define CLION_PROGRAMMING_CIRCLE_H
#include "../basic_classes.h"
#include <vector>
#include <iostream>
#include <set>

class CircleClass : public IGeoFig, public IDialogInitiable, public IPhysObject, public IPrintable, public BaseCObject{
private:
    static std::set<CircleClass*> all_circles;
    CVector2D center;
    int radius;
public:
    CircleClass(double x, double y, int radius);

    void set_params(double x, double y, int radius);

    static std::vector<CircleClass*> get_all_circles();

    double square();

    double perimeter();

    double mass();

    CVector2D position();

    bool operator== (const IPhysObject& ob ) const override;

    bool operator< ( const IPhysObject& ob ) const override;

    bool equal(CircleClass& class_1, CircleClass& class_2) const;

    bool less(CircleClass& class_1, CircleClass& class_2) const;

    void draw();

    void initFromDialog();

    const char* classname();

    unsigned int size();

    void init_class();

    void draw_all_circles();

    void summ_perimetr();

    void summ_square();

    void center_mass_all_circles();

    void summ_size();
};

#endif //CLION_PROGRAMMING_CIRCLE_H
