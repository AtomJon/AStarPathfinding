

#include "Algorithm.hpp"

#include <array>
#include <list>
#include <math.h>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "AlgorithmRenderer.hpp"

#include "Utils.hpp"

const sf::Vector2i UP = {0,1}, DOWN = {0,-1}, LEFT = {-1,0}, RIGHT = {1,0};

Algorithm::Algorithm()
{
    
}

Algorithm::~Algorithm()
{
}

using namespace sf;

float lengthOfVector(const Vector2f& source)
{
    return std::sqrt((source.x * source.x) + (source.y * source.y));
}

Vector2f normalize(const Vector2f& source)
{
    float length = lengthOfVector(source);
    if (length != 0)
        return Vector2f(source.x / length, source.y / length);
    else
        return source;
}

void Algorithm::AddMove(sf::Vector2i move)
{
    if (lengthOfVector({move.x, move.y}) > 1.)
    {
        std::cout << "Illegal move attempted. Crashing" << std::endl;
        std::exit(-1);
    }
    
    position += move;
    moves.emplace_back(move);
}

bool Algorithm::IsPositionWall(Vector2i pos)
{
    int index = Get8x8GridIndexFromCoords({pos.x, pos.y});
    return (*grid)[index];
}

float Algorithm::GetDistanceOfMoveToTarget(sf::Vector2i move)
{
    auto tempPosition = position + move;
    float distanceToTarget = DistanceBetweenVectors<int>(tempPosition, targetPosition);
    return distanceToTarget;
}

float Algorithm::GetScoreOfMove(sf::Vector2i move)
{    
    // Discard moves that aren't possible
    
    return GetDistanceOfMoveToTarget(move);
}

Vector2i Algorithm::ChooseBestMove()
{
    float rightScore = GetScoreOfMove(RIGHT);
    float upScore = GetScoreOfMove(UP);
    float downScore = GetScoreOfMove(DOWN);
    
    if      (rightScore <= upScore && rightScore <= downScore)    return RIGHT;
    else if (upScore <= rightScore && upScore <= downScore)       return UP;
    else if (downScore <= rightScore && downScore <= upScore)     return DOWN;
    else                                                        return LEFT;
}

MovesList Algorithm::Solve(Boolean8x8Grid *_grid, sf::Vector2i _position, sf::Vector2i _targetPosition)
{
    grid = _grid;
    position = _position;
    moves.clear();
    targetPosition = _targetPosition;
    
    while (true)
    {       
        if (position == targetPosition)
        {
            break;
        }
        
        auto move = ChooseBestMove();
        AddMove(move);
    }
    
    std::cout << moves.size() << std::endl;
    
    return moves;
}