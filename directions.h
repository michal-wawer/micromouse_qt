#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include <map>
#include <ostream>

using namespace std;

enum class Direction
{
    UPPER,
    RIGHT,
    BOTTOM,
    LEFT
};

const map<Direction, Direction> rotateLeftMap = {
    {Direction::UPPER, Direction::LEFT},
    {Direction::RIGHT, Direction::UPPER},
    {Direction::BOTTOM, Direction::RIGHT},
    {Direction::LEFT, Direction::BOTTOM},
};

const map<Direction, Direction> rotateRightMap = {
    {Direction::UPPER, Direction::RIGHT},
    {Direction::RIGHT, Direction::BOTTOM},
    {Direction::BOTTOM, Direction::LEFT},
    {Direction::LEFT, Direction::UPPER},
};

const map<Direction, Direction> rotateBackMap = {
    {Direction::UPPER, Direction::BOTTOM},
    {Direction::RIGHT, Direction::LEFT},
    {Direction::BOTTOM, Direction::UPPER},
    {Direction::LEFT, Direction::RIGHT},
};

#endif // DIRECTIONS_H
