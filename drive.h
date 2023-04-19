#ifndef DRIVE_H
#define DRIVE_H
#include "directions.h"

/// Simulate mouse robot drive unit.
class Drive
{
public:
    Drive();

    /// Turn to the right by 90 degrees.
    /// \param currentRotation current mouse rotation.
    /// \param direction current mouse direction.
    void turnRight(int& currentRotation, Direction& direction);

    /// Turn to the left by 90 degrees.
    /// \param currentRotation current mouse rotation.
    /// \param direction current mouse direction.
    void turnLeft(int& currentRotation, Direction& direction);

    /// Turn by 180 degrees.
    /// \param currentRotation current mouse rotation.
    /// \param direction current mouse direction.
    void turnBack(int& currentRotation, Direction& direction);

    /// Move by one cell, to given coordinates.
    /// \param x column coordinate.
    /// \param y row coordinate.
    /// \param direction direction in which the movement will be made.
    void moveForward(int& x, int& y, Direction direction);
};

#endif // DRIVE_H
