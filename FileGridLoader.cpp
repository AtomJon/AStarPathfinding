#include "FileGridLoader.hpp"

#include <cmath>
#include <random>

#include <filesystem>
#include <fstream>
#include <iostream>

#include "Utils.hpp"

#define MAX_ITERATIONS 255 // Just a arbitrary number, defining the limit for how many characters will be scanned in the file
#define FILE_NAME "Grid.csv" // The name for the file to load the data from.

namespace NeutronicPathfinding
{
    FileGridLoader::FileGridLoader()
    {
        char* fileName = FILE_NAME;

        std::ifstream gridFile(fileName);

        if (!gridFile)
        {
            char* errorMsg; 
            std::sprintf(errorMsg, "Grid data: \" %s cannot be found", fileName);
            std::cout << errorMsg;
            throw errorMsg;
            // TODO: FIX THIS MESS
        }
        
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
                std::cerr << "Grid data: \"" << FILE_NAME << "\" contains too many characters. Bad file?";
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