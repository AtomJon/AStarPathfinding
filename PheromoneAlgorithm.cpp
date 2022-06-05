#include "PheromoneAlgorithm.hpp"

#include <array>
#include <list>
#include <math.h>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "AlgorithmRenderer.hpp"

#include "Utils.hpp"

using namespace sf;

const GridCoords UP = {0, 1}, DOWN = {0, -1}, LEFT = {-1, 0}, RIGHT = {1, 0};

float lengthOfVector(const Vector2f &source)
{
    return std::sqrt((source.x * source.x) + (source.y * source.y));
}

Vector2f normalize(const Vector2f &source)
{
    float length = lengthOfVector(source);
    if (length != 0)
        return Vector2f(source.x / length, source.y / length);
    else
        return source;
}

namespace NeutronicPathfinding
{
    void PheromoneAlgorithm::Initiate(Boolean8x8Grid *_grid, GridCoords _position, GridCoords _targetPosition)
    {
        grid = _grid;
        position = _position;
        targetPosition = _targetPosition;
    }

    GridMove PheromoneAlgorithm::GetLastMove()
    {
        return moves.back();
    }

    void PheromoneAlgorithm::PerformMove(GridMove move)
    {
        if (lengthOfVector({(float)move.x, (float)move.y}) > 1.)
        {
            std::cout << "Illegal move attempted. Crashing" << std::endl;
            std::exit(-1);
        }

        positionsAlreadyBeenTo.push_front(position);

        position += move;
        moves.emplace_back(move);
    }

    bool PheromoneAlgorithm::PositionIsWall(GridCoords pos)
    {
        int index = Get8x8GridIndexFromCoords({pos.x, pos.y});
        return (*grid)[index];
    }

    float PheromoneAlgorithm::GetDistanceToTarget(GridCoords tempPosition)
    {
        float distanceToTarget = DistanceBetweenVectors<int>(tempPosition, targetPosition);
        return distanceToTarget;
    }

    float PheromoneAlgorithm::GetScoreOfMove(GridMove move)
    {
        // Avoid current move, if move converses last move
        auto lastMove = GetLastMove();
        auto intermediateAbs = abs(DistanceBetweenVectors(lastMove, move));
        if (intermediateAbs == 2)
        {
            return INFINITY;
        }

        auto tempPosition = position + move;

        if (PositionIsWall(tempPosition))
        {
            return INFINITY; // Move goes into a wall, so discard it.
        }

        float distance = GetDistanceToTarget(tempPosition);
        return distance;
    }

    GridCoords PheromoneAlgorithm::ChooseBestMove()
    {
        float rightScore = GetScoreOfMove(RIGHT);
        float upScore = GetScoreOfMove(UP);
        float downScore = GetScoreOfMove(DOWN);

        if (rightScore <= upScore && rightScore <= downScore)
            return RIGHT;
        else if (upScore <= rightScore && upScore <= downScore)
            return UP;
        else if (downScore <= rightScore && downScore <= upScore)
            return DOWN;
        else
            return LEFT;
    }

    void PheromoneAlgorithm::Tick()
    {
        if (position == targetPosition)
        {
            // Reached target position, no need for more moves.
            return;
        }

        auto move = ChooseBestMove();

        PerformMove(move);
    }
}