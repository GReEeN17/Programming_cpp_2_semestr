#ifndef CLION_PROGRAMMING_CIRCLE_H
#define CLION_PROGRAMMING_CIRCLE_H
#include "../basic_classes.h"

class CircleClass : public IGeoFig, public IDialogInitiable, public IPhysObject, public IPrintable, public BaseCObject{
private:
    CVector2D center;
    int radius;
public:
    CircleClass(double x, double y, int radius);

    double square();

    double perimeter();

    double mass();

    CVector2D position();

    bool operator== ( const IPhysObject& ob ) const override;

    bool operator< ( const IPhysObject& ob ) const override;

    void draw();

    void initFromDialog();

    const char* classname();

    unsigned int size();
};

#endif //CLION_PROGRAMMING_CIRCLE_H
