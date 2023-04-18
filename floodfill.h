#ifndef FLOODFILL_H
#define FLOODFILL_H

#include "algorythm.h"
#include <queue>

struct MazeNode
{
    int x, y, val;
    MazeNode(int _x, int _y, int _val): x(_x), y(_y), val(_val)
    {

    };
    MazeNode(): x(0), y(0), val(0){};
};

class Floodfill : public Algorythm
{
public:
    Floodfill();
    void run(Mouse* mouse);

private:
    void updateMazeNode(MazeNode& e, MazeNode& n, std::queue<MazeNode>& q);
    vector<vector<int>> visitedCells;
    vector<vector<int>> floodfillCellsValues;
};

#endif // FLOODFILL_H
