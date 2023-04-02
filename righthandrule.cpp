#include "righthandrule.h"

RightHandRule::RightHandRule()
{

}

void RightHandRule::run(Mouse* mouse)
{
    mouse->moveForward();
    mouse->turnRight();
}
