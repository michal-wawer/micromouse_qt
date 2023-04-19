#include "righthandrule.h"
#include <QSequentialAnimationGroup>

void RightHandRule::run(Mouse* mouse)
{
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;

    while (!mouse->isFinished()) {
        if (mouse->checkForInfLoop()) {
            cout << "Infinite loop - maze can't be solved" << endl;
            break;
        }
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
        }
        group->addAnimation(mouse->moveForward());
    }

    group->start();
}
