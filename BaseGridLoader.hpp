#ifndef BASE_GRID_LOADER_H
#define BASE_GRID_LOADER_H

#include "Utils.hpp"

namespace NeutronicPathfinding
{
    class BaseGridLoader
    {
    public:
        virtual Boolean8x8Grid GenerateGrid() = 0;
    };
}

#endif