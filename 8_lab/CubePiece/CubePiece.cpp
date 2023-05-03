#include "CubePiece.h"
#include <iostream>
#include <utility>
using std::string;

CubePiece::CubePiece(string up_, string down_, string left_, string right_, string front_, string rear_)  {
    this->up = std::move(up_);
    this->down = std::move(down_);
    this->left = std::move(left_);
    this->right = std::move(right_);
    this->front = std::move(front_);
    this->rear = std::move(rear_);
}

string CubePiece::getUpColor() {return up;}

string CubePiece::getDownColor() {return down;}

string CubePiece::getLeftColor() {return left;}

string CubePiece::getRightColor() {return right;}

string CubePiece::getFrontColor() {return front;}

string CubePiece::getRearColor() {return rear;}

void CubePiece::setUpColor(std::string color) {this->up = std::move(color);}

void CubePiece::setDownColor(std::string color) {this->down = std::move(color);}

void CubePiece::setLeftColor(std::string color) {this->left = std::move(color);}

void CubePiece::setRightColor(std::string color) {this->right = std::move(color);}

void CubePiece::setFrontColor(std::string color) {this->front = std::move(color);}

void CubePiece::setRearColor(std::string color) {this->rear = std::move(color);}
