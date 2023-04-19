#ifndef MAZE_H
#define MAZE_H

#include <QGraphicsScene>
#include "cell.h"
#include <QGraphicsRectItem>

using namespace std;

/// Representation of virtual maze displayed by Qt graphics scene.
class Maze : public QGraphicsScene
{
public:
    Maze();

    /// Check if mouse is in center of maze, points (7,7), (7,8), (8,7), (8,8).
    /// \param x x-coordinate (column).
    /// \param y y-coordinate (row).
    /// \return return true if mouse is in center points.
    bool isInCenter(int x, int y);

    /// Return Cell data from given coordinates.
    /// \param x x-coordinate (column).
    /// \param y y-coordinate (row).
    /// \return Cell object.
    Cell* getCell(int x, int y);

private:
    /// 16x16 vector with all cells in the maze.
    vector<vector<Cell>> cells;

    /// Load maze from resources/example.txt file. Each line represents one Cell.
    void loadMazeFromFile();

    /// Print information about each cell in the maze. Only for debug purpose.
    void printMazeCells();

    /// Paint maze in the graphics scene.
    void paintMazeWalls();
};

#endif // MAZE_H
