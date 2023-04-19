#include "lefthandrule.h"
#include <QSequentialAnimationGroup>

void LeftHandRule::run(Mouse* mouse)
{
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;

    while (!mouse->isFinished()) {
        if (mouse->checkForInfLoop()) {
            cout << "Infinite loop - maze can't be solved" << endl;
            break;
        }
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
