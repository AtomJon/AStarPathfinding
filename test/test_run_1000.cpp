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
    
NeutronicPathfinding::PheromoneAlgorithm algo{};
NeutronicPathfinding::RandomGridLoader gridLoader{};

Boolean8x8Grid grid = gridLoader.GenerateGrid();

NeutronicPathfinding::Simulation sim{
    &algo,
};

bool RunSimulation()
{
    grid = gridLoader.GenerateGrid(); // TODO: Check if this properly updates sim
    sim.Restart(&grid);
    
    static std::chrono::high_resolution_clock clock{};
    std::chrono::steady_clock::time_point startedPoint = clock.now();
    
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