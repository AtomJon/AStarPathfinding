#ifndef PHEROMONE_ALGO_H
#define PHEROMONE_ALGO_H

#include "BaseAlgorithm.hpp"

#include <array>
#include <list>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"

using namespace sf;

namespace NeutronicPathfinding
{
    class PheromoneAlgorithm : public BaseAlgorithm
    {
    private:
        Boolean8x8Grid *grid;

        GridPositionsList positionsAlreadyBeenTo;

        GridMove GetLastMove();
        bool HaveAlreadyBeenToPosition(GridCoords pos);
        void PerformMove(GridMove move);
        bool PositionIsWall(GridCoords pos);
        bool PositionIsOffGrid(GridCoords pos);
        bool AttemptMove(GridCoords pos);

        float GetDistanceToTarget(GridCoords pos);
        float GetScoreOfMove(GridMove move);

        GridMove ChooseBestMove();

    public:
        PheromoneAlgorithm() {}
        ~PheromoneAlgorithm() {}

        virtual void Initiate(Boolean8x8Grid *grid, GridCoords position, GridCoords targetPosition);
        virtual void Tick();
        virtual bool ReachedTargetPosition();
    };
}

#endif