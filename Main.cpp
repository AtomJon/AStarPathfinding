#include <SFML/Graphics.hpp>
#include "Simulation.hpp"

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "A* Pathfinding");
    // sf::RectangleShape shape({100,100});
    // shape.setFillColor({127,85,57,255});
    // shape.setOutlineColor(sf::Color::Black);
    // shape.setOutlineThickness(4.F);
    
    Simulation sim{&window};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
                
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R)
                sim.RegenerateGrid();
        }

        sim.Render();
    }

    return 0;
}
