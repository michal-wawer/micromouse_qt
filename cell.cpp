#include "cell.h"

Cell::Cell(std::vector<int> values) {
    this->x = values.at(0);
    this->y = values.at(1);
    this->upperWall = values.at(2);
    this->rightWall = values.at(3);
    this->bottomWall = values.at(4);
    this->leftWall = values.at(5);
}

int Cell::getX() {
    return x;
}

int Cell::getY() {
    return y;
}
