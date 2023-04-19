#include "drive.h"

Drive::Drive()
{

}

void Drive::turnRight(int& currentRotation, Direction& direction) {
    currentRotation += 90.0;
    direction = rotateRightMap.at(direction);
}

void Drive::turnLeft(int& currentRotation, Direction& direction) {
    currentRotation -= 90.0;
    direction = rotateLeftMap.at(direction);
}

void Drive::turnBack(int& currentRotation, Direction& direction) {
    currentRotation -= 180.0;
    direction = rotateBackMap.at(direction);
}

void Drive::moveForward(int& x, int& y, Direction direction) {
    switch(direction) {
        case Direction::UPPER:
            y--; // -1 row
            break;
        case Direction::RIGHT:
            x++; // +1 column
            break;
        case Direction::BOTTOM:
            y++; // +1 row
            break;
        case Direction::LEFT:
            x--; // -1 column
            break;
    }
}
