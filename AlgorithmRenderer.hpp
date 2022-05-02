#ifndef ALGORITHMRENDERER_H
#define ALGORITHMRENDERER_H

#include <array>
#include <list>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"

class AlgorithmRenderer : public sf::Drawable
{
private:
    sf::Vector2i position;
    
    MovesList moves;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    AlgorithmRenderer(sf::Vector2i startingPosition);
    ~AlgorithmRenderer();
    
    void ApplyMovements(MovesList moves);
};

#endif