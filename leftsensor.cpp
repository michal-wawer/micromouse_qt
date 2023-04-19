#include "leftsensor.h"

bool LeftSensor::checkWall() {
    switch(this->robotDirection) {
        case Direction::UPPER:
            return this->currentCell->getLeftWall();
            break;
        case Direction::RIGHT:
            return this->currentCell->getUpperWall();
            break;
        case Direction::BOTTOM:
            return this->currentCell->getRightWall();
            break;
        case Direction::LEFT:
            return this->currentCell->getBottomWall();
            break;
    }

    return true;
}
