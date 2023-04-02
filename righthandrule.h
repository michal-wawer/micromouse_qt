#ifndef RIGHTHANDRULE_H
#define RIGHTHANDRULE_H

#include "algorythm.h"
#include "mouse.h"

class RightHandRule : public Algorythm
{
public:
    RightHandRule();
    void run(Mouse* mouse);
};

#endif // RIGHTHANDRULE_H
