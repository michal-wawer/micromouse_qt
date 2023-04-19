#ifndef DRIVE_H
#define DRIVE_H
#include "directions.h"

class Drive
{
public:
    Drive();
    void turnRight(int& currentRotation, Direction& direction);
    void turnLeft(int& currentRotation, Direction& direction);
    void turnBack(int& currentRotation, Direction& direction);
    void moveForward(int& x, int& y, Direction direction);
};

#endif // DRIVE_H
