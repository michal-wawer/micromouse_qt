#include "lefthandrule.h"
#include <QSequentialAnimationGroup>

LeftHandRule::LeftHandRule()
{

}

void LeftHandRule::run(Mouse* mouse)
{
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;

//    for (int i = 0; i < 115; i++) {
    while (!mouse->isFinished()) {
        if (!mouse->isWallOnLeft()) {
            group->addAnimation(mouse->turnLeft());
        } else {
            if (!mouse->isWallOnFront()) {

            } else {
                if (!mouse->isWallOnRight()) {
                    group->addAnimation(mouse->turnRight());
                } else {
                    group->addAnimation(mouse->turnBack());
                }
            }
        } // TODO: dodac checka na wyjscie poza plansze
        group->addAnimation(mouse->moveForward());
    }

    group->start(); // to odpalac od razu po dodaniu pierwszej animacji
}
