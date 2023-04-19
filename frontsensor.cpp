#include "frontsensor.h"

bool FrontSensor::checkWall() {
    switch(this->robotDirection) {
        case Direction::UPPER:
            return this->currentCell->getUpperWall();
            break;
        case Direction::RIGHT:
            return this->currentCell->getRightWall();
            break;
        case Direction::BOTTOM:
            return this->currentCell->getBottomWall();
            break;
        case Direction::LEFT:;
            return this->currentCell->getLeftWall();
            break;
    }

    return true;
}
