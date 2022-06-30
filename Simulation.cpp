#include "Simulation.hpp"

#include <iostream>
#include <math.h>

#include <SFML/Graphics.hpp>

#include "AlgorithmRenderer.hpp"
#include "PheromoneAlgorithm.hpp"

namespace NeutronicPathfinding
{
    Simulation::Simulation(BaseAlgorithm *algo)
    {        
        algorithm = algo;
    }

    void Simulation::Tick()
    {
        algorithm->Tick();
    }

    void Simulation::Restart(Boolean8x8Grid *_grid)
    {
        grid = _grid;
        
        algorithm->Initiate(grid, STARTING_POSITION, TARGET_POSITION);
    }
    
    bool Simulation::DidAlgorithmReachedTarget()
    {
        return algorithm->ReachedTargetPosition();
    }
}