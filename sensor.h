#ifndef SENSOR_H
#define SENSOR_H
#include "directions.h"
#include "cell.h"

/// Abstract class, for simulating wall detectors installed on the robot.
class Sensor
{
public:
    /// Set current cell on direction of the robot.
    /// \param currentCell current cell in which the robot is located.
    /// \param robotDirection current robot direction.
    Sensor(Cell* currentCell, Direction robotDirection) {
        this->currentCell = currentCell;
        this->robotDirection = robotDirection;
    };

    /// Update cell and direction after robot move.
    /// \param currentCell current cell in which the robot is located.
    /// \param robotDirection current robot direction.
    virtual void updatePositionAfterMove(Cell* currentCell, Direction robotDirection) {
        this->currentCell = currentCell;
        this->robotDirection = robotDirection;
    };

    /// Virtual method for implementation of wall detector logic.
    virtual bool checkWall() = 0;

    ~Sensor() {};
protected:
    Direction robotDirection;
    Cell* currentCell;
};

#endif // SENSOR_H
