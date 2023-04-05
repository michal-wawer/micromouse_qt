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
    Cell(vector<int> values);
    int getX();
    int getY();
    string toString();
    bool getUpperWall();
    bool getBottomWall();
    bool getRightWall();
    bool getLeftWall();

private:
    int x; // 0-15 (16x16) or 0-31 (32x32)
    int y; // 0-15 (16x16) or 0-31 (32x32)
    bool upperWall;
    bool bottomWall;
    bool leftWall;
    bool rightWall;
};

#endif // CELL_H
