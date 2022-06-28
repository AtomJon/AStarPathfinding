#include "Simulation.hpp"

#include <iostream>
#include <math.h>

#include <SFML/Graphics.hpp>

#include "AlgorithmRenderer.hpp"
#include "PheromoneAlgorithm.hpp"

namespace NeutronicPathfinding
{
    Simulation::Simulation(BaseAlgorithm *algo, Boolean8x8Grid *grid)
    {        
        algorithm = algo;
        grid = grid;
    }

    void Simulation::Tick()
    {
        algorithm->Tick();
    }

    void Simulation::Restart()
    {
        algorithm->Initiate(grid, STARTING_POSITION, TARGET_POSITION);
    }
    
    bool Simulation::DidAlgorithmReachedTarget()
    {
        return algorithm->ReachedTargetPosition();
    }
}