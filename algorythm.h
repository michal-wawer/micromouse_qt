#ifndef ALGORYTHM_H
#define ALGORYTHM_H

#include "mouse.h"

enum ALGORYTHM_TYPE {
    RIGHT_HAND,
    LEFT_HAND
};

/// Abstract class for implementing algorithms to solve the maze.
class Algorythm
{
public:
    Algorythm() {};

    /// \brief Method for implementation of specific algorithm.
    /// \param mouse Current mouse visible on the maze.
    virtual void run(Mouse* mouse) = 0;

    ~Algorythm() {};
};

#endif // ALGORYTHM_H
