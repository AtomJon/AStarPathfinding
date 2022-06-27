#ifndef FILE_GRID_LOADER_H
#define FILE_GRID_LOADER_H

#include <cmath>
#include <random>

#include "Utils.hpp"
#include "BaseGridLoader.hpp"

namespace NeutronicPathfinding
{
    class FileGridLoader : public BaseGridLoader
    {
    private:
        Boolean8x8Grid grid;
    public:
        FileGridLoader(char* fileName) noexcept(false);
        ~FileGridLoader() {}

        virtual Boolean8x8Grid GenerateGrid();
    };
}

#endif