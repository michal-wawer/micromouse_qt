#include "maze.h"

const int MAZE_WIDTH = 480; // change to dynamic
const int MAZE_HEIGHT = 480; // change to dynamic
const int MAZE_SIZE = 16; //sqrt(this->cells.size());

Maze::Maze()
{
    this->setBackgroundBrush(QColor(255, 255, 250, 255));

    this->cells.resize(MAZE_SIZE, vector<Cell>(MAZE_SIZE));

    loadMazeFromFile();
//    printMazeCells();
    paintMazeWalls();
}

void Maze::loadMazeFromFile()
{
    // std::string filename = "example.txt"; TODO: dynamic path to file
    ifstream mazeFile;
    mazeFile.open("C:\\Users\\mwawe\\Documents\\micromouse_qt_project\\example.txt");

    if (!mazeFile.is_open())
        cout << "Failed to open file\n";
    else {
        stringstream ss;
        string line;
        string singleCellVariable;
        vector<int> cellData;
        int i = 0;
        int j = 0;
        while (getline(mazeFile, line)) {
            ss.str(line);
            while (ss >> singleCellVariable) {
                cellData.push_back(stoi(singleCellVariable));
            }

            this->cells[i][j] = (Cell(cellData));

            cellData.clear();
            ss.clear();

            j++;
            if (j % (MAZE_SIZE) == 0) {
                i++;
                j = 0;
            }

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
            cout << this->cells[i][j].toString() << " ";
        }
        cout << endl;
    }
}

void Maze::paintMazeWalls()
{
    // print 2d grid
    int cellSize = MAZE_WIDTH / MAZE_SIZE; // rozmiar jednego kwadratu
    for (int x=cellSize; x<MAZE_WIDTH; x+=cellSize)
        this->addLine(x, 0, x, MAZE_HEIGHT, QPen(Qt::red));

    for (int y=cellSize; y<MAZE_HEIGHT; y+=cellSize)
        this->addLine(0, y, MAZE_WIDTH, y, QPen(Qt::red)); // xSART, ySTART, xEND, yEND

    this->addLine(0, 0, MAZE_WIDTH, 0, QPen(Qt::black));
    this->addLine(0, 0, 0, MAZE_HEIGHT, QPen(Qt::black));
    this->addLine(0, MAZE_HEIGHT, MAZE_WIDTH, MAZE_HEIGHT, QPen(Qt::black));
    this->addLine(MAZE_WIDTH, 0, MAZE_WIDTH, MAZE_HEIGHT, QPen(Qt::black));

    int x = 0;
    int y = 0;
    QPen wall = QPen(Qt::black);
    wall.setWidth(2);

    for (int i = 0; i < this->cells.size(); i++)
    {
        for (int j = 0; j < this->cells[i].size(); j++)
        {

            if (this->cells[i][j].getUpperWall()) {
                this->addLine(x, y, x+cellSize, y, wall);
            }

            if (this->cells[i][j].getBottomWall()) {
                this->addLine(x, y+cellSize, x + cellSize, y+cellSize, wall);
            }

            if (this->cells[i][j].getLeftWall()) {
                this->addLine(x, y, x, y+cellSize, wall);
            }

            if (this->cells[i][j].getRightWall()) {
                this->addLine(x+cellSize, y, x+cellSize, y+cellSize, wall);
            }

            x += cellSize;

        }

        x = 0;
        y += cellSize;
    }
}

vector<vector<Cell>> Maze::getCells()
{
    return this->cells;
}
