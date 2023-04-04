#include "righthandrule.h"
#include <QSequentialAnimationGroup>

RightHandRule::RightHandRule()
{

}

void RightHandRule::run(Mouse* mouse)
{
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;

    for (int i = 0; i < 1; i++) {
        group->addAnimation(mouse->moveForward());
        group->addAnimation(mouse->turnRight());
        group->addAnimation(mouse->moveForward());
    }
    group->start();
}
