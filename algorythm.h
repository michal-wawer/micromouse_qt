#ifndef ALGORYTHM_H
#define ALGORYTHM_H

#include "mouse.h"

class Algorythm
{
public:
    Algorythm();
    virtual void run(Mouse* mouse) = 0;
    ~Algorythm() {}; // destruktory w innych klasach
};

#endif // ALGORYTHM_H
