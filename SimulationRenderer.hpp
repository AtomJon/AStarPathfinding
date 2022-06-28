#include "Utils.hpp"

#include <SFML/Window.hpp>

#include "BaseAlgorithm.hpp"
#include "AlgorithmRenderer.hpp"
#include "GridRenderer.hpp"

namespace NeutronicPathfinding
{
    class SimulationRenderer
    {
    private:
        AlgorithmRenderer algoRenderer;
        GridRenderer gridRenderer;
        
        RenderWindow* window;
        
        void ClearWindow();
        void DisplayWindow();
    public:
        SimulationRenderer(RenderWindow*, BaseAlgorithm*, Boolean8x8Grid*);
        ~SimulationRenderer();
        
        void Render();
    };
}