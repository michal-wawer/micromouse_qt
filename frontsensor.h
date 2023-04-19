#ifndef FRONTSENSOR_H
#define FRONTSENSOR_H

#include "sensor.h"

/// Simulate wall detector sensor, mounted on the front of a robot.
class FrontSensor : public Sensor
{
public:
    FrontSensor(Cell* currentCell, Direction robotDirection) : Sensor(currentCell, robotDirection) {};

    /// Check if there is a wall on the front of the robot.
    /// \return true if there is a wall.
    bool checkWall() override;
};

#endif // FRONTSENSOR_H
