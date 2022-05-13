#include <cmath>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"

using namespace sf;

Vector2u GetCoordsFrom8x8GridIndex(int index)
{
    auto div = std::div(index, 8);
    
    uint x = div.rem;
    uint y = div.quot;
    
    return {x,y};
}

int Get8x8GridIndexFromCoords(sf::Vector2i coords)
{
    return coords.x + coords.y * 8;
}