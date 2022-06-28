#include "SimulationRenderer.hpp"

#include "Utils.hpp"

#include <SFML/Window.hpp>

#include "BaseAlgorithm.hpp"
#include "AlgorithmRenderer.hpp"
#include "GridRenderer.hpp"

namespace NeutronicPathfinding
{
    SimulationRenderer::SimulationRenderer(RenderWindow* window, BaseAlgorithm *algo, Boolean8x8Grid *grid)
    {
        algoRenderer = AlgorithmRenderer{algo};
        gridRenderer = GridRenderer{grid};
        
        window = window;
    }

    SimulationRenderer::~SimulationRenderer()
    {
    }

    void SimulationRenderer::Render()
    {
        ClearWindow();
        
        window->draw(algoRenderer);
        gridRenderer.Render(window);
        
        DisplayWindow();
    }
    
    void SimulationRenderer::ClearWindow() { window->clear(sf::Color::Black); }
    void SimulationRenderer::DisplayWindow() { window->display(); }
}