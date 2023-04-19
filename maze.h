#ifndef MAZE_H
#define MAZE_H

#include <QGraphicsScene>
#include "cell.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <QGraphicsRectItem>

using namespace std;

class Maze : public QGraphicsScene
{
public:
    Maze();
    vector<vector<Cell>> getCells();
    bool isInCenter(int x, int y);
    Cell* getCell(int x, int y);

private:
    vector<vector<Cell>> cells; // beter 2d matrix (vector of cells inside vector) - 16 x rows and 16 cells in each row
    void loadMazeFromFile();
    void printMazeCells();
    void paintMazeWalls();
};

#endif // MAZE_H
