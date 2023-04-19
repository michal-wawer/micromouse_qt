#ifndef LEFTSENSOR_H
#define LEFTSENSOR_H

#include "sensor.h"

class LeftSensor : public Sensor
{
public:
    LeftSensor(Cell* currentCell, Direction robotDirection) : Sensor(currentCell, robotDirection) {};
    bool checkWall() override;
};

#endif // LEFTSENSOR_H
