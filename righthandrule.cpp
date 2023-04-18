#include "righthandrule.h"
#include <QSequentialAnimationGroup>

RightHandRule::RightHandRule()
{

}

void RightHandRule::run(Mouse* mouse)
{
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;

    while (!mouse->isFinished()) {
        if (!mouse->isWallOnRight()) {
            group->addAnimation(mouse->turnRight());
        } else {
            if (!mouse->isWallOnFront()) {

            } else {
                if (!mouse->isWallOnLeft()) {
                    group->addAnimation(mouse->turnLeft());
                } else {
                    group->addAnimation(mouse->turnBack());
                }
            }
        } // TODO: dodac checka na wyjscie poza plansze
        group->addAnimation(mouse->moveForward());
    }

    group->start(); // to odpalac od razu po dodaniu pierwszej animacji
}
