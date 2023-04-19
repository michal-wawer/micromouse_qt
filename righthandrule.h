#ifndef RIGHTHANDRULE_H
#define RIGHTHANDRULE_H

#include "algorythm.h"

/// Implementation of right hand rule algorithm to solve maze.
class RightHandRule : public Algorythm
{
public:
    /// Implementation of right hand rule algorithm.
    /// \param mouse current mouse displayed on maze.
    void run(Mouse* mouse) override;
};

#endif // RIGHTHANDRULE_H
