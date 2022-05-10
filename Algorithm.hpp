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
    sf::Vector2i position, targetPosition;
    Boolean8x8Grid *grid;
    
    void AddMove(sf::Vector2i move);
    bool IsPositionWall(sf::Vector2i pos);
    bool AttemptMove(sf::Vector2i pos);
    
    float GetDistanceOfMoveToTarget(sf::Vector2i);
    float GetScoreOfMove(sf::Vector2i);
    
    sf::Vector2i ChooseBestMove();
public:
    Algorithm();
    ~Algorithm();
    
    MovesList Solve(Boolean8x8Grid *grid, sf::Vector2i position, sf::Vector2i targetPosition);
    
    void Render(sf::RenderWindow);
};

#endif