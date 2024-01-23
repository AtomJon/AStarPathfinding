#include "RandomGridLoader.hpp"

#include <cmath>
#include <random>

#include "Utils.hpp"

namespace NeutronicPathfinding
{
    RandomGridLoader::RandomGridLoader()
    {
        srand(time(NULL));
    }

    Boolean8x8Grid RandomGridLoader::GenerateGrid()
    {
        Boolean8x8Grid grid;
        grid.fill(0);

        for (size_t i = 0; i < 64; i++)
        {
            if (
                (i > 17 && i < 22) ||
                (i > 33 && i < 38) ||
                (i > 25 && i < 30) ||
                (i > 41 && i < 46))
            {
                bool isWall = (rand() % 2) == 0;
                grid[i] = isWall;
            }
        }

        return grid;
    }
}