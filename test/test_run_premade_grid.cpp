#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>

#include "../Simulation.hpp"

#include "../AlgorithmRenderer.hpp"
#include "../PheromoneAlgorithm.hpp"

#include "../BaseGridLoader.hpp"
#include "../RandomGridLoader.hpp"
#include "../FileGridLoader.hpp"

#define GRID_FILE_NAME std::string("Grid.csv")

sf::RenderWindow window(sf::VideoMode({800, 800}), "A* Pathfinding");
    
NeutronicPathfinding::PheromoneAlgorithm algo{};
NeutronicPathfinding::AlgorithmRenderer algoRenderer{&algo};

NeutronicPathfinding::FileGridLoader gridLoader{(char *)GRID_FILE_NAME.c_str()};

NeutronicPathfinding::Simulation sim{
    &window,
    &algo,
    &algoRenderer,
    &gridLoader
};

bool RunSimulation()
{
    bool keepGoing = true;
    while (keepGoing)
    {
        if (sim.AlgorithmReachedTarget())
        {
            keepGoing = false;
        }

        sim.TickAndRender();
        
        if (!window.isOpen()) keepGoing = false;
    }
    
    return true;
}
    
int main()
{
    bool succeded = RunSimulation();
    
    if (succeded)
        std::cout << "Test passed" << std::endl;
    else
        std::cout << "Test failed" << std::endl;        
}