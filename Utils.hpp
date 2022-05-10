#include <list>
#include <array>

#include <SFML/Graphics.hpp>

typedef std::list<sf::Vector2i> MovesList;
typedef std::array<bool, 64> Boolean8x8Grid;

sf::Vector2u GetCoordsFrom8x8GridIndex(int index);
int Get8x8GridIndexFromCoords(sf::Vector2u coords);

template <typename T>
float DistanceBetweenVectors(sf::Vector2<T> vectorX, sf::Vector2<T> vectorY);

#include "Utils.tcc"