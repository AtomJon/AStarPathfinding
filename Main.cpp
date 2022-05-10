#include <SFML/Graphics.hpp>
#include "Simulation.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "A* Pathfinding");
    
    Simulation sim{&window};
    
    sim.CalculatePath();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
                
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R)
                sim.Regenerate();
        }

        sim.Render();
    }

    return 0;
}
