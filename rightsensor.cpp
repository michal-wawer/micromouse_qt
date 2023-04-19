#include "rightsensor.h"

bool RightSensor::checkWall() {
    switch(this->robotDirection) {
        case Direction::UPPER:
            return this->currentCell->getRightWall();
            break;
        case Direction::RIGHT:
            return this->currentCell->getBottomWall();
            break;
        case Direction::BOTTOM:
            return this->currentCell->getLeftWall();
            break;
        case Direction::LEFT:
            return this->currentCell->getUpperWall();
            break;
    }

    return true;
}
