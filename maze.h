#ifndef MAZE_H
#define MAZE_H

#include <QGraphicsScene>
#include "cell.h"
#include <QGraphicsRectItem>

using namespace std;

class Maze : public QGraphicsScene
{
public:
    Maze();
    bool isInCenter(int x, int y);
    Cell* getCell(int x, int y);

private:
    vector<vector<Cell>> cells;
    void loadMazeFromFile();
    void printMazeCells();
    void paintMazeWalls();
};

#endif // MAZE_H
