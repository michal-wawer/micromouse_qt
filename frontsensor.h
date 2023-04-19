#ifndef FRONTSENSOR_H
#define FRONTSENSOR_H

#include "sensor.h"

class FrontSensor : public Sensor
{
public:
    FrontSensor(Cell* currentCell, Direction robotDirection) : Sensor(currentCell, robotDirection) {};
    bool checkWall() override;
};

#endif // FRONTSENSOR_H
