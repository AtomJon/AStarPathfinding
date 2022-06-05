#ifndef RNG_GRID_LOADER_H
#define RNG_GRID_LOADER_H

#include <cmath>
#include <random>

#include "Utils.hpp"
#include "BaseGridLoader.hpp"

namespace NeutronicPathfinding
{
    class RandomGridLoader : public BaseGridLoader
    {
    public:
        RandomGridLoader();
        ~RandomGridLoader() {}

        Boolean8x8Grid GenerateGrid();
    };
}

#endif