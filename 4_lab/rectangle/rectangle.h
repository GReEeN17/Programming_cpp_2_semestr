#ifndef CLION_PROGRAMMING_RECTANGLE_H
#define CLION_PROGRAMMING_RECTANGLE_H
#include "../basic_classes.h"

class RectangleClass : public IGeoFig, public IDialogInitiable, public IPhysObject, public IPrintable, public BaseCObject{
private:
    CVector2D fir_vert;
    CVector2D sec_vert;
    CVector2D thi_vert;
    CVector2D fth_vert;
    double fir_side;
    double sec_side;
public:
    RectangleClass(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3, double x_4, double y_4);

    void set_params(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3, double x_4, double y_4);

    void set_sides();

    double square();

    double perimeter();

    double mass();

    CVector2D position();

    bool operator== (const IPhysObject& ob ) const override;

    bool operator< ( const IPhysObject& ob ) const override;

    bool equal(RectangleClass& class_1, RectangleClass& class_2) const;

    bool less(RectangleClass& class_1, RectangleClass& class_2) const;

    void draw();

    void initFromDialog();

    const char* classname();

    unsigned int size();
};


#endif //CLION_PROGRAMMING_RECTANGLE_H
