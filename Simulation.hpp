#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <math.h>
#include <cmath>
#include <random>

#include <SFML/Graphics.hpp>

#include "AlgorithmRenderer.hpp"

#include "BaseGridLoader.hpp"

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

        void RegenerateGrid();
        
        void ClearWindow();
        void DisplayWindow();
    public:
        Simulation(BaseAlgorithm*, Boolean8x8Grid*);
        ~Simulation() {}
        
        void Tick();
        
        void Restart();
        
        bool DidAlgorithmReachedTarget();
    };
}

#endif