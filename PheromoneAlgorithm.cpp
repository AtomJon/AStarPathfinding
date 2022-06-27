#include "PheromoneAlgorithm.hpp"

#include <array>
#include <list>
#include <math.h>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "AlgorithmRenderer.hpp"

#include "Utils.hpp"

using namespace sf;

const int IMPOSSIBLE_MOVE = INT32_MAX;
const int ATTEMPT_AVOID_MOVE = INT32_MAX - 1;
const int PREFER_AVOID_MOVE = INT32_MAX - 2;

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
        
        positionsAlreadyBeenTo.clear();
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

    bool PheromoneAlgorithm::HaveAlreadyBeenToPosition(GridCoords pos)
    {
        for (auto &&previousPos : positionsAlreadyBeenTo)
        {
            if (previousPos == pos)
            {
                return true;
            }
        }

        return false;
    }

    float PheromoneAlgorithm::GetScoreOfMove(GridMove move)
    {
        auto tempPosition = position + move;

        if (PositionIsWall(tempPosition))
        {
            return IMPOSSIBLE_MOVE; // Move goes into a wall, so discard it.
        }

        if (HaveAlreadyBeenToPosition(tempPosition))
        {
            return ATTEMPT_AVOID_MOVE;
        }

        float distance = GetDistanceToTarget(tempPosition);
        
        return distance;
    }

    GridMove PheromoneAlgorithm::ChooseBestMove()
    {
        float rightScore = GetScoreOfMove(RIGHT);
        float upScore = GetScoreOfMove(UP);
        float downScore = GetScoreOfMove(DOWN);
        float leftScore = GetScoreOfMove(LEFT);
        
        std::cout << ""
            << "Right: " << rightScore
            << "\nUp: " << upScore
            << "\nDown: " << downScore
            << "\nLeft: " << leftScore
            << std::endl << std::endl;
            
        if ((rightScore == ATTEMPT_AVOID_MOVE || rightScore == IMPOSSIBLE_MOVE) &&
            (upScore == ATTEMPT_AVOID_MOVE || upScore == IMPOSSIBLE_MOVE) &&
            (downScore == ATTEMPT_AVOID_MOVE || downScore == IMPOSSIBLE_MOVE))
        {
            return LEFT;
        }
        
        if (rightScore != IMPOSSIBLE_MOVE && rightScore <= upScore && rightScore <= downScore && rightScore <= leftScore)
            return RIGHT;
        else if (upScore != IMPOSSIBLE_MOVE && upScore <= rightScore && upScore <= downScore && upScore <= leftScore)
            return UP;
        else if (downScore != IMPOSSIBLE_MOVE && downScore <= rightScore && downScore <= upScore && downScore <= leftScore)
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