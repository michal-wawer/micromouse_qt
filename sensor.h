#ifndef SENSOR_H
#define SENSOR_H
#include "directions.h"
#include "cell.h"

class Sensor
{
public:
    Sensor(Cell* currentCell, Direction robotDirection) {
        this->currentCell = currentCell;
        this->robotDirection = robotDirection;
    };
    virtual void updatePositionAfterMove(Cell* currentCell, Direction robotDirection) {
        this->currentCell = currentCell;
        this->robotDirection = robotDirection;
    };
    virtual bool checkWall() = 0;
    ~Sensor() {};
protected:
    Direction robotDirection;
    Cell* currentCell;
};

#endif // SENSOR_H
