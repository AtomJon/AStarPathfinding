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
    &grid
};

bool RunSimulation()
{
    bool keepGoing = true;
    while (keepGoing)
    {
        if (sim.DidAlgorithmReachedTarget())
        {
            keepGoing = false;
        }
            
        sim.Tick();
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