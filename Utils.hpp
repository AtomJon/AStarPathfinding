#include <list>
#include <array>

#include <SFML/Graphics.hpp>

typedef sf::Vector2i GridCoords;
typedef sf::Vector2i GridMove;

typedef std::list<GridMove> MovesList;
typedef std::list<GridCoords> GridPositionsList;

typedef std::array<bool, 64> Boolean8x8Grid;

GridCoords GetCoordsFrom8x8GridIndex(int index);
int Get8x8GridIndexFromCoords(GridCoords coords);

template <typename T>
float DistanceBetweenVectors(sf::Vector2<T> vectorX, sf::Vector2<T> vectorY);

#include "Utils.tcc"