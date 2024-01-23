#include <cmath>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"

using namespace sf;

GridCoords GetCoordsFrom8x8GridIndex(int index)
{
    auto div = std::div(index, 8);
    
    int x = div.rem;
    int y = div.quot;
    
    return {x,y};
}

int Get8x8GridIndexFromCoords(GridCoords coords)
{
    return coords.x + coords.y * 8;
}