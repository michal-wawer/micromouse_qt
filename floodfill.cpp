#include "floodfill.h"
#include <QSequentialAnimationGroup>
#include <queue>
#include "directions.h"
#include "cell.h"
#include <stack>

using namespace std;

Floodfill::Floodfill()
{
    this->visitedCells = vector<vector<int>>(16, vector<int>(16));
    this->floodfillCellsValues = vector<vector<int>>(16, vector<int>(16));
}

void Floodfill::updateMazeNode(MazeNode& e, MazeNode&n, std::queue<MazeNode>& q)
{
    this->visitedCells[e.x][e.y] = 1;
    q.push(e);
    this->floodfillCellsValues[e.x][e.y] = n.val + 1;
}

Cell getFrontCell(Mouse* &mouse) {
    switch(mouse->getCurrentDirection()) {
        case Direction::UPPER:
            return mouse->getCell(mouse->getX(), mouse->getY()-1); //yy -= 1;
            break;
        case Direction::RIGHT:
            return mouse->getCell(mouse->getX()+1, mouse->getY()); //xx += 1;
            break;
        case Direction::BOTTOM:
            return mouse->getCell(mouse->getX(), mouse->getY()+1); //yy += 1;
            break;
        case Direction::LEFT:
            return mouse->getCell(mouse->getX()-1, mouse->getY()); //xx -= 1;
            break;
    }
}
Cell &getLeftCell(Mouse* &mouse);
Cell &getRightCell(Mouse* &mouse);


string getDirectionString(Direction minDirection) {
    switch(minDirection) { // zadana pozycja myszy
        case Direction::UPPER:
            return "upper";
            break;
        case Direction::RIGHT:
            return "right";
            break;
        case Direction::BOTTOM:
            return "bottom";
            break;
        case Direction::LEFT:
            return "left";
            break;
    }
}

// zdefiniowac w pliku naglowkowym
void getMinDistanceDirection(Mouse* &mouse, int &minDistance, Direction &minDirection)
{
    cout << "mysz patrzy w " << getDirectionString(mouse->getCurrentDirection()) << endl;
    vector<Direction> possDirect = mouse->possibleDirections();
    cout << "mozliwe ruchy: ";
    for (int i=0; i< possDirect.size(); i++) {
        cout << getDirectionString(possDirect[i]);
    }
    cout << endl; // TODO: possible directions zwraca miejsca ze scianami
    /// mysz ma jakas pozycje (patrzy w ktoras strone)
cout << mouse->getCell(mouse->getX(), mouse->getY()).toString() << endl;
    bool foundDirection = false;
    if (!mouse->isWallOnFront())
    {
        cout << "[x:" << mouse->getX() << ",y:" << mouse->getY() << "] Nie ma sciany z przodu" << endl;
        // jezeli nie ma sciany w przod to musimy pobrac cell ktory jest z przodu myszy
        // wiec na podstawie
        int xx = mouse->getX();
        int yy = mouse->getY();

        switch(mouse->getCurrentDirection()) {
            case Direction::UPPER:
                yy -= 1; // do gory
                break;
            case Direction::RIGHT:
                xx += 1; // w prawo
                break;
            case Direction::BOTTOM:
                yy += 1;
                break;
            case Direction::LEFT:
                xx -= 1;
                break;
        }

        Cell front = mouse->getCell(xx, yy);
        cout <<"IDZ DO KOMORKI [" << xx << "," << yy << "]" << endl;
  // dodalem tego if i >= cztery razy
        if (front.getVisited()) {
            minDistance++;
        }
        if (minDistance >= front.getFloodfillValue())
        {
            minDistance =front.getFloodfillValue();
            minDirection = mouse->getCurrentDirection();//Direction::UPPER;
            foundDirection = true;
        }
    }
    if (!mouse->isWallOnLeft())
    {
        cout << "[x:" << mouse->getX() << ",y:" << mouse->getY() << "] Nie ma sciany z lewej" << endl;
        // sprawdzamy czy ma scaine po swojej lewej jezeli nie ma to pobieramy Cell ktory jest po lewej stronie myszy
        int xx = mouse->getX();
        int yy = mouse->getY();

        switch(mouse->getCurrentDirection()) {
            case Direction::UPPER: // jezeli patrzy sie w gore to komrka za lewym przegiem bedzie po lewej czyli musi zrobi c rotacje i minDirection ustawic na left
                xx -= 1;
                break;
            case Direction::RIGHT: // tutaj min direction musi byc UP
                yy -= 1;
                break;
            case Direction::BOTTOM: // tutaj RIGHT
                xx += 1;
                break;
            case Direction::LEFT: // TUTAJ bottom
                yy += 1;
                break;
        }
        Cell left = mouse->getCell(xx, yy);
        cout << "IDZ DO KOMORKI [" << xx << "," << yy << "]" << endl;
        if (left.getVisited()) {
            minDistance++;
        }
        if (minDistance >= left.getFloodfillValue())
        {
            minDistance = left.getFloodfillValue();
            minDirection =  rotateLeftMap.at(mouse->getCurrentDirection()); //Direction::LEFT;
            foundDirection = true;
        }
    }
    if (!mouse->isWallOnRight())
    {
        cout << "[x:" << mouse->getX() << ",y:" << mouse->getY() << "] Nie ma sciany z prawej" << endl;
        int xx = mouse->getX();
        int yy = mouse->getY();
            cout << "nie ma scainy na dole a kierunek to " << getDirectionString(mouse->getCurrentDirection()) << endl;
        Direction minDirection2;
        switch(mouse->getCurrentDirection()) {
        /* nie ma sciany na prawo wiec skrecamy w prawo */
            case Direction::UPPER:
                minDirection2 = Direction::RIGHT;
                xx += 1; // w prawo
                break;
            case Direction::RIGHT:
                 minDirection2 = Direction::BOTTOM;
                yy += 1; // w dol
                break;
            case Direction::BOTTOM:
                minDirection2 = Direction::LEFT;
                xx -= 1; // w lewo
                break;
            case Direction::LEFT:
                minDirection2 = Direction::UPPER;
                yy -= 1; // w gore
                break;
        }
        Cell right = mouse->getCell(xx, yy);
        if (right.getVisited()) {
            minDistance++;
        }
        cout << "IDZ DO KOMORKI [" << xx << "," << yy << "]" << endl;
        if (minDistance >= right.getFloodfillValue())
        {
            minDistance = right.getFloodfillValue();
            minDirection = minDirection2;//rotateRightMap.at(mouse->getCurrentDirection());//Direction::RIGHT;
            foundDirection = true;
        }
    }
    if (mouse->getPrevVisitedCell() != nullptr && !foundDirection)
    {
        cout << "COFAM" << endl;
        Cell *back = mouse->getPrevVisitedCell();
        if (back->getVisited()) {
            minDistance++;
        }
        if (minDistance >= back->getFloodfillValue())
        {
            minDistance =back->getFloodfillValue();
            minDirection = rotateBackMap.at(mouse->getCurrentDirection());//Direction::BOTTOM;
        }
    }
}

bool isSafe(int X, int Y)
{
    if (X < 0 || X > 16 - 1)
        return false;
    if (Y < 0 || Y > 16 - 1)
        return false;
    return true;
}

// przeniesc powtorka z Maze
bool isInCenter(int x, int y)
{
//    int upperCenterPoint = MAZE_SIZE / 2;
//    int lowerCenterPoint = upperCenterPoint--;

    int x_min = 7;
    int x_max = 8;
    int y_min = 7;
    int y_max = 8;

    if (x >= x_min && x <= x_max
            && y >= y_min &&  y <= y_max) {
        return true;
    }

    return false;
}

void floodOpenNeighbours(Mouse* mouse)
{
    int mazeSize = 16;
    std::stack<MazeNode> floodStack;
    int minDistance = mazeSize * 2;
    char minDirection;
    int cellX, cellY;
    MazeNode start(mouse->getX(), mouse->getY(), 0); // wywalic value
    floodStack.push(start);
    while (!floodStack.empty()) {
//    for (int ii=0; ii<6; ii++){
        cout << "WHILE floodOpenNeighbours size=" << floodStack.size() << endl;
        cellX = floodStack.top().x;
        cellY = floodStack.top().y;
        cout << "cell[" << cellX << "," << cellY << "]" <<endl;
        floodStack.pop();
        if (isInCenter(cellX, cellY))
            continue;

        Cell cell = mouse->getCell(cellX, cellY);
//        cout << "czy odwiedzona " << mouse->getCell(0, 0).getVisited() << endl;
        if (cell.getVisited())
        {

            minDistance = mazeSize * 2;
            int D1 = (!mouse->getCell(cellX, cellY).getBottomWall()) ? mouse->getCell(cellX, cellY+1).getFloodfillValue() : mazeSize * 2;
            int D2 = (!mouse->getCell(cellX, cellY).getUpperWall()) ? mouse->getCell(cellX, cellY-1).getFloodfillValue() : mazeSize * 2;
            int D3 = (!mouse->getCell(cellX, cellY).getLeftWall()) ? mouse->getCell(cellX-1, cellY).getFloodfillValue() : mazeSize * 2;
            int D4 = (!mouse->getCell(cellX, cellY).getRightWall()) ? mouse->getCell(cellX+1, cellY).getFloodfillValue() : mazeSize * 2;
            minDistance = std::min(D1, D2);
            minDistance = std::min(minDistance, D3);
            minDistance = std::min(minDistance, D4);
            //----------add to stack

            if (mouse->getCell(cellX, cellY).getFloodfillValue() != 1 + minDistance)
            {
                mouse->getCell(cellX, cellY).setFloodfillValue(1 + minDistance);

                if (!mouse->getCell(cellX, cellY).getUpperWall() && isSafe(cellX, cellY-1))
                {
                    MazeNode up(cellX, cellY-1, 0);
                    floodStack.push(up);
                }
                if (!mouse->getCell(cellX, cellY).getBottomWall() && isSafe(cellX, cellY+1))
                {
                    MazeNode bottom(cellX, cellY+1, 0);
                    floodStack.push(bottom);
                }
                if (!mouse->getCell(cellX, cellY).getLeftWall() && isSafe(cellX-1, cellY))
                {
                    MazeNode left(cellX-1, cellY, 0);
                    floodStack.push(left);
                }
                if (!mouse->getCell(cellX, cellY).getRightWall() && isSafe(cellX+1, cellY))
                {
                    MazeNode right(cellX+1, cellY, 0);
                    floodStack.push(right);
                }
            }
        }
        else
        {

            int minD = mazeSize * 2;
            // a cell that has not been explored has no walls so all neighbours are accessible

            int d1 = isSafe(cellX + 1, cellY) ? mouse->getCell(cellX+1, cellY).getFloodfillValue() : mazeSize * 2;
            int d2 = isSafe(cellX - 1, cellY) ? mouse->getCell(cellX-1, cellY).getFloodfillValue() : mazeSize * 2;
            int d3 = isSafe(cellX, cellY + 1) ? mouse->getCell(cellX, cellY+1).getFloodfillValue() : mazeSize * 2;
            int d4 = isSafe(cellX, cellY - 1) ? mouse->getCell(cellX, cellY-1).getFloodfillValue() : mazeSize * 2;
            minD = std::min(d1, d2);
            minD = std::min(minD, d3);
            minD = std::min(minD, d4);
            if (mouse->getCell(cellX, cellY).getFloodfillValue() != 1 + minD)
            {
                mouse->getCell(cellX, cellY).setFloodfillValue(1 + minD);

                if (isSafe(cellX + 1, cellY))
                {
                    cout << "a" << mouse->getX()+1 <<  mouse->getY() << endl;
                    MazeNode right(cellX + 1, cellY, 0);
                    floodStack.push(right);
                }
                if (isSafe(cellX - 1, cellY))
                {
                    cout << "b" << mouse->getX()-1 <<  mouse->getY() << endl;
                    MazeNode left(cellX-1, cellY, 0);
                    floodStack.push(left);
                }
                if (isSafe(cellX, cellY + 1))
                {
                    cout << "c" << mouse->getX() <<  mouse->getY()+1 << endl;
                    MazeNode bottom(cellX, cellY+1, 0);
                    floodStack.push(bottom);
                }
                if (isSafe(cellX, cellY - 1))
                {
                    cout << "d" << mouse->getX() <<  mouse->getY()-1 << endl;
                    MazeNode up(cellX, cellY-1, 0);
                    floodStack.push(up);
                }
            }
        }
    }
}



void Floodfill::run(Mouse* mouse)
{
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;

    // https://github.com/PriyankaPrakashChand/Micromouse_E-Puck/blob/main/floodfill%20algorithm/Main.cpp
    vector<vector<Cell>> floodfillCells(16, vector<Cell>(16));
    int x = 0;
    int y = 0;

    bool destinationFound = false;
    int minDistance;
    Direction minDirection;

//    while (!destinationFound) {
    for (int ii=0; ii<1000; ii++){
        cout << "Poczatek iteracji getX/Y = [" << mouse->getX() << "," << mouse->getY() << "]" << endl;

        mouse->setCellAsVisited();
        minDistance = 16 * 2;

        if (mouse->isFinished())
            destinationFound = true;

        getMinDistanceDirection(mouse, minDistance, minDirection);

cout << "Pierwsze getMinDistanceDirection - minDirection:" << getDirectionString(minDirection) << endl;

        // check if reflooding is required
        if (mouse->getFloodfillValueForCurrentCell() != 1 + minDistance)
        {
            // reflood
            floodOpenNeighbours(mouse);

            // after reflooding get new min distance neighbours
            getMinDistanceDirection(mouse, minDistance, minDirection); //get neighbour with lowest distance

cout << "Drugie w Ifie - minDirection:" << getDirectionString(minDirection) << endl;
        }

cout << "Ostatecznie - minDirection:" << getDirectionString(minDirection) << endl;

//    switch(minDirection) { // zadana pozycja myszy
//        case Direction::UPPER:
////            group->addAnimation(mouse->turnLeft());
//            group->addAnimation(mouse->moveForward());
//            break;
//        case Direction::RIGHT:
//            group->addAnimation(mouse->turnRight());
//            group->addAnimation(mouse->moveForward());
//            break;
//        case Direction::BOTTOM:
//            group->addAnimation(mouse->turnBack());
////            group->addAnimation(mouse->turnRight());
//            group->addAnimation(mouse->moveForward());
//            break;
//        case Direction::LEFT:
//            group->addAnimation(mouse->turnLeft());
////            group->addAnimation(mouse->turnBack());
//            group->addAnimation(mouse->moveForward());
//            break;
//    }

        cout << "pozycja myszy: " << getDirectionString(mouse->getCurrentDirection()) << endl;
        switch(mouse->getCurrentDirection()) { // obecna pozycja myszy
            case Direction::UPPER:
                switch(minDirection) { // zadana pozycja myszy
                    case Direction::UPPER:
                        break;
                    case Direction::RIGHT:
                        group->addAnimation(mouse->turnRight());
                        break;
                    case Direction::BOTTOM:
                        group->addAnimation(mouse->turnBack());
                        break;
                    case Direction::LEFT:
                        group->addAnimation(mouse->turnLeft());
                        break;
                }
                break;
            case Direction::RIGHT:
                switch(minDirection) { // zadana pozycja myszy
                    case Direction::UPPER:
                        group->addAnimation(mouse->turnLeft());
                        break;
                    case Direction::RIGHT:
                        break;
                    case Direction::BOTTOM:
                        group->addAnimation(mouse->turnRight());
                        break;
                    case Direction::LEFT:
                        group->addAnimation(mouse->turnBack());
                        break;
                }
                break;
            case Direction::BOTTOM:
                switch(minDirection) { // zadana pozycja myszy
                    case Direction::UPPER:
                        group->addAnimation(mouse->turnBack());
                        break;
                    case Direction::RIGHT:
                        group->addAnimation(mouse->turnLeft());
                        break;
                    case Direction::BOTTOM:

                        break;
                    case Direction::LEFT:
                        group->addAnimation(mouse->turnRight());
                        break;
                }
                break;
            case Direction::LEFT:
                switch(minDirection) { // zadana pozycja myszy
                    case Direction::UPPER:
                        group->addAnimation(mouse->turnRight());
                        break;
                    case Direction::RIGHT:
                        group->addAnimation(mouse->turnBack());
                        break;
                    case Direction::BOTTOM:
                        group->addAnimation(mouse->turnLeft());
                        break;
                    case Direction::LEFT:

                        break;
                }
                break;
        }
  group->addAnimation(mouse->moveForward());
    cout << "---------------------------------------" << endl;

    }



//--------------------------------------------------------


//    vector<vector<int>> visitedCells(16, vector<int>(16));
//    vector<vector<int>> floodfillCellsValues(16, vector<int>(16));


//    std::queue<MazeNode> q;
//    MazeNode goal(7, 8, 0);
//    q.push(goal);

//    while (!q.empty()) {
//        MazeNode n = q.front();
//        q.pop();
//        visitedCells[n.x][n.y] = 1;
//        cout << n.x << ", " << n.y << endl;
//        bool nbrFound = false;

//        cout << mouse->getFrontWall(n.x, n.y) << endl;
//        if (!mouse->getFrontWall(n.x, n.y) && visitedCells[n.x][n.y-1] == 0)
//        {
//            cout << "1" << endl;
//            MazeNode e(n.x, n.y - 1, n.val + 1);
//            updateMazeNode(e, n, q);
//            nbrFound = true;
//        }
//        // Left Neighbor is accesible, and not visited
//         cout << mouse->getLeftWall(n.x, n.y) << endl;
//        if (!mouse->getLeftWall(n.x, n.y) && visitedCells[n.x - 1][n.y] == 0)
//        {
//            cout << "2" << endl;
//            MazeNode e(n.x - 1, n.y, n.val + 1);
//            updateMazeNode(e, n, q);
//            nbrFound = true;
//        }

//        // Bottom Neighbor is accesible, and not visited
//        cout << mouse->getBottomWall(n.x, n.y) << endl;
//        if (!mouse->getBottomWall(n.x, n.y) && visitedCells[n.x][n.y+1] == 0)
//        {
//            cout << "3" << endl;
//            MazeNode e(n.x, n.y + 1, n.val + 1);
//            updateMazeNode(e, n, q);
//            nbrFound = true;
//        }

//        // Right Neighbor is accesible, and not visited
//        cout << mouse->getRightWall(n.x, n.y) << endl;
//        if (!mouse->getRightWall(n.x, n.y) && visitedCells[n.x + 1][n.y] == 0)
//        {
//            cout << "4" << endl;
//            MazeNode e(n.x + 1, n.y, n.val + 1);
//            updateMazeNode(e, n, q);
//            nbrFound = true;
//        }

//        if(nbrFound==false)
//        {
//        }

//    }

//    for (int i = 0; i < this->floodfillCellsValues.size(); i++)
//    {
//        for (int j = 0; j < this->floodfillCellsValues[i].size(); j++)
//        {
//            cout << this->floodfillCellsValues[i][j] << " ";
//        }
//        cout << endl;
//    }


    //-----------------------------

//    while (!mouse->isFinished()) {
//        if (!mouse->isWallOnRight()) {
//            group->addAnimation(mouse->turnRight());
//        } else {
//            if (!mouse->isWallOnFront()) {

//            } else {
//                if (!mouse->isWallOnLeft()) {
//                    group->addAnimation(mouse->turnLeft());
//                } else {
//                    group->addAnimation(mouse->turnBack());
//                }
//            }
//        } // TODO: dodac checka na wyjscie poza plansze
//        group->addAnimation(mouse->moveForward());
//    }

    group->start(); // to odpalac od razu po dodaniu pierwszej animacji

}
