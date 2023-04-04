#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include <map>

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

const std::map<Direction, Direction> rotateRightMap = {
    {Direction::UPPER, Direction::RIGHT},
    {Direction::RIGHT, Direction::BOTTOM},
    {Direction::BOTTOM, Direction::LEFT},
    {Direction::LEFT, Direction::UPPER},
};

#endif // DIRECTIONS_H
