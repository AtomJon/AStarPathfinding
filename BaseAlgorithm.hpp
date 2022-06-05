#ifndef BASE_ALGO_H
#define BASE_ALGO_H

#include "Utils.hpp"

namespace NeutronicPathfinding
{
    class BaseAlgorithm
    {
    public:
        GridCoords position, targetPosition;

        virtual void Initiate(Boolean8x8Grid *grid, GridCoords startingPosition, GridCoords targetPosition) = 0;
        virtual void Tick() = 0;
    };
}

#endif