#include <list>
#include <array>

#include <SFML/Graphics.hpp>

typedef sf::Vector2i GridCoords;
typedef sf::Vector2i GridMove;

typedef std::list<GridMove> MovesList;
typedef std::list<GridCoords> GridPositionsList;

typedef std::array<bool, 64> Boolean8x8Grid;