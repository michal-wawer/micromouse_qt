#include "maze.h"
#include <QCoreApplication>
#include <QFile>

const int MAZE_WIDTH = 480;
const int MAZE_HEIGHT = 480;
const int MAZE_SIZE = 16;

Maze::Maze()
{
    this->cells.resize(MAZE_SIZE, vector<Cell>(MAZE_SIZE));

    loadMazeFromFile();
//    printMazeCells();
    paintMazeWalls();
}


void Maze::loadMazeFromFile()
{
    QFile mazeFile(":/resources/example.txt");

    if (!mazeFile.open(QIODevice::ReadOnly))
        cout << "Failed to open maze file" << endl;
    else {
        QString line;
        QStringList list;
        string singleCellVariable;
        vector<int> cellData;

        QTextStream in(&mazeFile);

        while (!in.atEnd()) {
            line = in.readLine();
            list = line.split(" ");

            for (const QString& i : list) {
                cellData.push_back(i.toInt());
            }

            this->cells[cellData.at(0)][cellData.at(1)] = (Cell(cellData));

            cellData.clear();
            list.clear();
        }
    }

    mazeFile.close();
}

void Maze::printMazeCells()
{
    for (int i = 0; i < this->cells.size(); i++)
    {
        for (int j = 0; j < this->cells[i].size(); j++)
        {
            cout << this->cells[j][i].toString() << " ";
        }
        cout << endl;
    }
}

void Maze::paintMazeWalls()
{
    int cellSize = MAZE_WIDTH / MAZE_SIZE;

    // print red lines to show each cell
//    for (int x=cellSize; x<MAZE_WIDTH; x+=cellSize)
//        this->addLine(x, 0, x, MAZE_HEIGHT, QPen(Qt::red));

//    for (int y=cellSize; y<MAZE_HEIGHT; y+=cellSize)
//        this->addLine(0, y, MAZE_WIDTH, y, QPen(Qt::red));

    // print green circle at the center of maze
    this->addEllipse(230, 230, 20, 20, QPen(Qt::green), QBrush(Qt::green));

    int x = 0;
    int y = 0;
    QPen wall = QPen(Qt::black);
    wall.setWidth(2);

    for (int i = 0; i < this->cells.size(); i++)
    {
        for (int j = 0; j < this->cells[i].size(); j++)
        {

            if (this->cells[j][i].getUpperWall()) {
                this->addLine(x, y, x+cellSize, y, wall);
            }

            if (this->cells[j][i].getBottomWall()) {
                this->addLine(x, y+cellSize, x + cellSize, y+cellSize, wall);
            }

            if (this->cells[j][i].getLeftWall()) {
                this->addLine(x, y, x, y+cellSize, wall);
            }

            if (this->cells[j][i].getRightWall()) {
                this->addLine(x+cellSize, y, x+cellSize, y+cellSize, wall);
            }

            x += cellSize;
        }

        x = 0;
        y += cellSize;
    }
}

bool Maze::isInCenter(int x, int y)
{
    int upperCenterPoint = MAZE_SIZE / 2;
    int lowerCenterPoint = upperCenterPoint-1;

    if (x >= lowerCenterPoint && x <= upperCenterPoint
            && y >= lowerCenterPoint &&  y <= upperCenterPoint) {
        return true;
    }

    return false;
}

Cell* Maze::getCell(int x, int y) {
    if (x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE)
        return &this->cells[x][y];
    else
        throw new out_of_range("Index out of range");
}
