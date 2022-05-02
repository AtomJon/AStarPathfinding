#ifndef ALGORITHM
#define ALGORITHM

#include <array>
#include <list>

#include <SFML/Graphics.hpp>

#include "AlgorithmRenderer.hpp"
#include "Utils.hpp"

class Algorithm
{
private:    
    std::list<sf::Vector2i> moves;
    
public:
    Algorithm();
    ~Algorithm();
    
    MovesList Solve(std::array<bool, 64> grid, sf::Vector2i position);
    
    void Render(sf::RenderWindow);
};

#endif