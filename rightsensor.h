#ifndef RIGHTSENSOR_H
#define RIGHTSENSOR_H

#include "sensor.h"

class RightSensor : public Sensor
{
public:
    RightSensor(Cell* currentCell, Direction robotDirection) : Sensor(currentCell, robotDirection) {};
    bool checkWall() override;
};

#endif // RIGHTSENSOR_H
