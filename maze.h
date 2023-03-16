#ifndef MAZE_H
#define MAZE_H

#include <QGraphicsScene>
#include "cell.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <QGraphicsRectItem>

class Maze : public QGraphicsScene
{
public:
    Maze();

private:
    std::vector<Cell> cells; // lepiej wektor wektorow tiles, wtedy kazdy rzad bedzie wektorem czyli bedzie 16 rzedow i w kazdym rzedzie 16 komórek
    void loadMazeFromFile();
};

#endif // MAZE_H
