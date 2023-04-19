#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mouse.h"
#include "maze.h"
#include "algorythm.h"

/// Connector between maze, mouse and main window.
class Controller
{
public:
    Controller();

    ///
    /// \return Return current displayed maze.
    Maze* getMaze();

    ///
    /// \return Return current mouse.
    Mouse* getMouse();

    /// Run the selected algorithm after pressing the start button.
    void execute();

    /// Set active algorithm after selecting from the list of available algorithms.
    void setAlgorythm(ALGORYTHM_TYPE algo);

    /// Restart the maze, place the mouse in the start position.
    void reset();

private:
    Mouse* mouse;
    Maze* maze;
    Algorythm* algo;

};

#endif // CONTROLLER_H
