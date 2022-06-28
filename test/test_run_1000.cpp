#include <chrono>

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>

#include "../Simulation.hpp"

#include "../AlgorithmRenderer.hpp"
#include "../PheromoneAlgorithm.hpp"

#include "../BaseGridLoader.hpp"
#include "../RandomGridLoader.hpp"
#include "../FileGridLoader.hpp"


sf::RenderWindow window(sf::VideoMode({800, 800}), "A* Pathfinding");
    
NeutronicPathfinding::PheromoneAlgorithm algo{};
NeutronicPathfinding::AlgorithmRenderer algoRenderer{&algo};

NeutronicPathfinding::RandomGridLoader gridLoader{};

NeutronicPathfinding::Simulation sim{
    &window,
    &algo,
    &algoRenderer,
    &gridLoader
};

bool RunSimulation()
{
    sim.Regenerate();
    
    static std::chrono::high_resolution_clock clock{};
    std::chrono::_V2::system_clock::time_point startedPoint = clock.now();
    
    bool keepGoing = true;
    while (keepGoing)
    {
        if (sim.DidAlgorithmReachedTarget())
        {
            keepGoing = false;
        }
        
        if ((startedPoint - clock.now()) > std::chrono::seconds(2))
        {
            return false;
        }

        sim.Tick();
        
        if (!window.isOpen()) keepGoing = false;
    }
    
    return true;
}
    
int main()
{
    for (size_t i = 0; i < 1000; i++)
    {        
        bool succeded = RunSimulation();
        if (!succeded)
        {
            std::cout << "Test failed" << std::endl;
        }
    }
    
    std::cout << "Test passed" << std::endl;
}