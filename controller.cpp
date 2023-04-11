#include "controller.h"

Controller::Controller()
{
    this->maze = new Maze();

    this->mouse = new Mouse(maze);
    this->maze->addItem(this->mouse);
}

Maze* Controller::getMaze()
{
    return this->maze;
}

Mouse* Controller::getMouse()
{
    return this->mouse;
}

void Controller::setAlgorythm(ALGORYTHM_TYPE algo)
{
    switch (algo) {
        case ALGORYTHM_TYPE::RIGHT_HAND:
            this->algo = new RightHandRule();
            cout << "RightHand algo set" << endl;
            break;

       case ALGORYTHM_TYPE::LEFT_HAND:
            this->algo = new LeftHandRule();
            cout << "LeftHand algo set" << endl;
            break;
    }
}

void Controller::execute()
{
    cout << "run animation" << endl;
    this->algo->run(this->mouse);
}

void Controller::reset()
{
    this->maze->removeItem(this->mouse);
    this->mouse = new Mouse(maze);
    this->maze->addItem(this->mouse);
}
