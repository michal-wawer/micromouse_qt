#ifndef CELL_H
#define CELL_H

#include <vector>
#include <iostream>
#include "directions.h"

using namespace std;

class Cell
{
public:
    Cell();

    /// \brief Setup cell values: x-coordinate (column), y-coordinate (row), upper wall, right wall, bottom wall, left wall.
    /// \param values contains 6 configuration values for cell.
    Cell(vector<int> values);

    ///
    /// \return int x-coordinate of a cell.
    int getX();

    ///
    /// \return int y-coordinate of a cell.
    int getY();

    /// Get cell info, only for debugging purpose.
    /// \return String contains all information about cell.
    string toString();

    ///
    /// \return true if there is a wall in the cell on the north side
    bool getUpperWall();

    ///
    /// \return true if there is a wall in the cell on the south side
    bool getBottomWall();

    ///
    /// \return true if there is a wall in the cell on the east side
    bool getRightWall();

    ///
    /// \return true if there is a wall in the cell on the west side
    bool getLeftWall();

private:
    int x; // 0-15 (16x16)
    int y; // 0-15 (16x16)
    bool upperWall;
    bool bottomWall;
    bool leftWall;
    bool rightWall;
};

#endif // CELL_H
