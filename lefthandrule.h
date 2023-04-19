#ifndef LEFTHANDRULE_H
#define LEFTHANDRULE_H

#include "algorythm.h"

/// Implementation of left hand rule algorithm to solve maze.
class LeftHandRule : public Algorythm
{
public:
    /// Implementation of left hand rule algorithm.
    /// \param mouse current mouse displayed on maze.
    void run(Mouse* mouse) override;
};

#endif // LEFTHANDRULE_H
