#include "maze.h"

const int MAZE_WIDTH = 480; // change to dynamic
const int MAZE_HEIGHT = 480; // change to dynamic
const int MAZE_SIZE = 16; //sqrt(this->cells.size());

Maze::Maze()
{
    this->setBackgroundBrush(QColor(255, 255, 250, 255));

    loadMazeFromFile();

    // narysuj wszystkie komorki
    int cellSize = MAZE_WIDTH / MAZE_SIZE;
    for (int x=cellSize; x<MAZE_WIDTH; x+=cellSize)
        this->addLine(x,0,x,MAZE_HEIGHT, QPen(Qt::red));

    for (int y=cellSize; y<MAZE_HEIGHT; y+=cellSize)
        this->addLine(0,y,MAZE_WIDTH,y, QPen(Qt::green));


}

void Maze::loadMazeFromFile()
{
    // std::string filename = "example.txt"; TODO: dynamic path to file
    std::ifstream mazeFile;
    mazeFile.open("C:\\Users\\mwawe\\Documents\\micromouse_qt_project\\example.txt");

    if (!mazeFile.is_open())
        std::cout << "Failed to open file\n";
    else {
        std::stringstream ss;
        std::string line;
        std::string singleCellData;
        std::vector<int> cellData;

        while (std::getline(mazeFile, line)) {
            ss.str(line);
            while (ss >> singleCellData) {
                cellData.push_back(std::stoi(singleCellData));
            }

            this->cells.push_back(*new Cell(cellData));
            cellData.clear();
            ss.clear();
        }
    }

    mazeFile.close();
}
