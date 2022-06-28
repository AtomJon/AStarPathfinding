#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>

#include "Simulation.hpp"

#include "AlgorithmRenderer.hpp"
#include "PheromoneAlgorithm.hpp"

#include "BaseGridLoader.hpp"
#include "RandomGridLoader.hpp"
#include "FileGridLoader.hpp"

#include "SimulationRenderer.hpp"

int main()
{
    try
    {
        sf::RenderWindow window(sf::VideoMode({800, 800}), "A* Pathfinding");
        
        NeutronicPathfinding::PheromoneAlgorithm algo{};
        NeutronicPathfinding::FileGridLoader gridLoader{"Grid.csv"};
        
        Boolean8x8Grid grid = gridLoader.GenerateGrid();
        
        NeutronicPathfinding::SimulationRenderer simRenderer{&window, &algo, &grid};

        NeutronicPathfinding::Simulation sim{
            &algo,
            &grid
        };
        
        sim.Restart();
        simRenderer.Render();

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::KeyReleased)
                {
                    const auto keyCode = event.key.code;
                    switch (keyCode)
                    {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::R:
                        grid = gridLoader.GenerateGrid();
                        sim.Restart();
                        break;
                    case sf::Keyboard::Space:
                        sim.Tick();
                        simRenderer.Render();
                        break;
                    }
                }
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
