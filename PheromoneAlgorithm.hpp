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
    
        GridCoords GetLastMove();
        void PerformMove(GridCoords move);
        bool PositionIsWall(GridCoords pos);
        bool AttemptMove(GridCoords pos);
        
        float GetDistanceToTarget(GridCoords);
        float GetScoreOfMove(GridCoords);
        
        GridCoords ChooseBestMove();
    public:
        PheromoneAlgorithm() {}
        ~PheromoneAlgorithm() {}
        
        virtual void Initiate(Boolean8x8Grid *grid, GridCoords position, GridCoords targetPosition);
        virtual void Tick();
    };
}

#endif