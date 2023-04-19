#ifndef RIGHTSENSOR_H
#define RIGHTSENSOR_H

#include "sensor.h"

/// Simulate wall detector sensor, mounted on the right side of a robot.
class RightSensor : public Sensor
{
public:
    RightSensor(Cell* currentCell, Direction robotDirection) : Sensor(currentCell, robotDirection) {};

    /// Check if there is a wall on the right side of the robot.
    /// \return true if there is a wall.
    bool checkWall() override;
};

#endif // RIGHTSENSOR_H
