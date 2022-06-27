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
        const sf::Color BROWN{127, 85, 57, 255};
        const sf::Color GRAY{128, 128, 128, 255};

        Boolean8x8Grid grid;
        
        BaseAlgorithm* algorithm;
        AlgorithmRenderer* algorithmRenderer;

        BaseGridLoader* gridLoader;
        
        sf::RenderWindow* window;
        
        void RenderIndex(int);
        void RenderGrid();

        void RegenerateGrid();
        
        sf::VertexBuffer GetVerticesFromIndex(int);
        
        void ClearWindow();
        void DisplayWindow();
    public:
        Simulation(sf::RenderWindow*, BaseAlgorithm*, AlgorithmRenderer*, BaseGridLoader*);
        ~Simulation() {}
        
        void TickAndRender();
        
        void Regenerate();
        
        void Initiate();
    };
}