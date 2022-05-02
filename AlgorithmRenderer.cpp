#include "AlgorithmRenderer.hpp"

#include <array>
#include <list>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"

AlgorithmRenderer::AlgorithmRenderer(sf::Vector2i startingPosition)
{
    position = startingPosition;
}

AlgorithmRenderer::~AlgorithmRenderer()
{
}

void AlgorithmRenderer::ApplyMovements(MovesList moves)
{
    for (auto &&i : moves)
    {
        this->position += i;
    }
    
}

void AlgorithmRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape shape{{50.f,50.f}};
    sf::Vector2f pos{position.x * 100.f + 25, position.y * 100.f + 25};
    
    shape.setFillColor(sf::Color::White);
    
    shape.setPosition(pos);
    
    target.draw(shape);
}