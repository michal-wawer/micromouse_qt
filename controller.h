#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mouse.h"
#include "maze.h"
#include "algorythm.h"
#include "righthandrule.h"
#include "lefthandrule.h"

class Controller
{
public:
    Controller();
    Maze* getMaze();
    Mouse* getMouse();
    void execute();
    void setAlgorythm(ALGORYTHM_TYPE algo);
    void reset();

private:
    Mouse* mouse;
    Maze* maze;
    Algorythm* algo;

};

#endif // CONTROLLER_H
