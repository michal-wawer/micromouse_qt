#ifndef LEFTSENSOR_H
#define LEFTSENSOR_H

#include "sensor.h"

/// Simulate wall detector sensor, mounted on the left side of a robot.
class LeftSensor : public Sensor
{
public:
    LeftSensor(Cell* currentCell, Direction robotDirection) : Sensor(currentCell, robotDirection) {};

    /// Check if there is a wall on the left side of the robot.
    /// \return true if there is a wall.
    bool checkWall() override;
};

#endif // LEFTSENSOR_H
