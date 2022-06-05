#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>

#include "Simulation.hpp"

int main()
{
    try
    {
        sf::RenderWindow window(sf::VideoMode({800, 800}), "A* Pathfinding");

        NeutronicPathfinding::Simulation sim{&window};

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
                        sim.Regenerate();
                        break;
                    case sf::Keyboard::Space:
                        sim.TickAndRender();
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
