#ifndef ALGORYTHM_H
#define ALGORYTHM_H

#include "mouse.h"

enum ALGORYTHM_TYPE {
    RIGHT_HAND,
    LEFT_HAND
};

class Algorythm
{
public:
    Algorythm() {};
    virtual void run(Mouse* mouse) = 0;
    ~Algorythm() {};
};

#endif // ALGORYTHM_H
