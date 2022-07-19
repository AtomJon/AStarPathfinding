#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <math.h>
#include <cmath>
#include <random>

#include <SFML/Graphics.hpp>

#include "GridTypes.hpp"

#include "BaseAlgorithm.hpp"

#ifndef STARTING_POSITION
#define STARTING_POSITION {1,4}
#endif

#ifndef TARGET_POSITION
#define TARGET_POSITION {6,4}
#endif

namespace NeutronicPathfinding
{
    class Simulation
    {
    private:        
        BaseAlgorithm* algorithm;

        Boolean8x8Grid* grid;
        
        sf::RenderWindow* window;
    public:
        Simulation(BaseAlgorithm*);
        ~Simulation() {}
        
        void Tick();
        
        void Restart(Boolean8x8Grid*);
        
        bool DidAlgorithmReachedTarget();
    };
}

#endif