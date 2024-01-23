#include <SFML/Graphics.hpp>

#include "GridTypes.hpp"

#define BROWN sf::Color{127, 85, 57, 255};
#define GRAY sf::Color{128, 128, 128, 255};

GridCoords GetCoordsFrom8x8GridIndex(int index);
int Get8x8GridIndexFromCoords(GridCoords coords);

template <typename T>
float DistanceBetweenVectors(sf::Vector2<T> vectorX, sf::Vector2<T> vectorY);

#include "Utils.tcc"