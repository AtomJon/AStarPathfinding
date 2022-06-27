#include "FileGridLoader.hpp"

#include <cmath>
#include <random>

#include <filesystem>
#include <fstream>
#include <iostream>

#include "Utils.hpp"

#define MAX_ITERATIONS 255 // Just a arbitrary number, defining the limit for how many characters will be scanned in the file

void error(const char* s, char* arg)
{
    char* errorMsg; 
    std::sprintf(errorMsg, s, arg);
    std::cout << errorMsg << std::endl;
    throw std::runtime_error(errorMsg);
}

namespace NeutronicPathfinding
{
    FileGridLoader::FileGridLoader(char* fileName)
    {
        if (!fileName)
            error("Parameter: filename is invalid", "");
        
        bool fileExists = std::filesystem::exists(fileName);
        if (!fileExists)
            error("The file \"%s\" does not exist.", fileName);
        
        std::ifstream gridFile(fileName);

        if (!gridFile)
            error("Grid data: \"%s\" cannot be accessed", fileName);
        
        int iterations = 0;
        int index = 0;
        char c;
        while (gridFile.get(c))
        {
            if (c == 'o' || c == 'x')
            {
                if (c == 'o')
                    grid[index] = false;
                if (c == 'x')
                    grid[index] = true;

                index++;

                if (index > 63) break;
            }

            iterations++;
            if (iterations > MAX_ITERATIONS) 
            {
                std::cerr << "Grid data: \"" << fileName << "\" contains too many characters. Bad file?";
                break; // Ignore error, continue with acceptable, but bad grid.
            }
        }

        gridFile.close();
    }

    Boolean8x8Grid FileGridLoader::GenerateGrid()
    {
        return grid;
    }
}