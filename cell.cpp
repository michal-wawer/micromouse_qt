#include "cell.h"

Cell::Cell(){}

Cell::Cell(vector<int> values) {
    this->x = values.at(0);
    this->y = values.at(1);
    this->upperWall = values.at(2);
    this->rightWall = values.at(3);
    this->bottomWall = values.at(4);
    this->leftWall = values.at(5);
}

int Cell::getX() {
    return this->x;
}

int Cell::getY() {
    return this->y;
}

string Cell::toString()
{
    return '[' + to_string(this->x) + ", " + to_string(this->y)
            + "](up:" + to_string(this->getUpperWall())
            + ", right:" + to_string(this->getRightWall())
            + ", bottom:" + to_string(this->getBottomWall())
            + ", left:" + to_string(this->getLeftWall()) + ")";
}

bool Cell::getUpperWall()
{
    return this->upperWall;
}

bool Cell::getBottomWall()
{
    return this->bottomWall;
}

bool Cell::getRightWall()
{
    return this->rightWall;
}

bool Cell::getLeftWall()
{
    return this->leftWall;
}
