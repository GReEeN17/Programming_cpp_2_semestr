#ifndef CLION_PROGRAMMING_CUBEPIECE_H
#define CLION_PROGRAMMING_CUBEPIECE_H
#include <iostream>
#include <utility>
using std::string;


class CubePiece {
private:
    //Если какую-то грань детали мы не будем видеть, то она останется чёрной
    string up = "black";
    string down = "black";
    string left = "black";
    string right = "black";
    string front = "black";
    string rear = "black";
public:
    //Конструкторы
    CubePiece() = default;

    explicit CubePiece (string up_, string down_, string left_, string right_, string front_, string rear_);

    //Геттеры

    string getUpColor();

    string getDownColor();

    string getLeftColor();

    string getRightColor();

    string getFrontColor();

    string getRearColor();

    //Сеттеры

    void setUpColor(string color);

    void setDownColor(string color);

    void setLeftColor(string color);

    void setRightColor(string color);

    void setFrontColor(string color);

    void setRearColor(string color);
};


#endif //CLION_PROGRAMMING_CUBEPIECE_H
