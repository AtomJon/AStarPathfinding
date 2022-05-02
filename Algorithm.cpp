

#include "Algorithm.hpp"

#include <array>
#include <list>

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

MovesList Algorithm::Solve(std::array<bool, 64> grid, sf::Vector2i position)
{
    moves = {RIGHT, RIGHT, RIGHT, RIGHT, RIGHT};
    
    return moves;
}