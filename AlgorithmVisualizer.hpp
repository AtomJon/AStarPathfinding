#ifndef ALGORITHMVISUALIZER
#define ALGORITHMVISUALIZER

#include <array>
#include <list>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"

class AlgorithmVisualizer : public sf::Drawable
{
private:
    sf::Vector2i position;
    
    MovesList moves;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    AlgorithmVisualizer(sf::Vector2i startingPosition);
    ~AlgorithmVisualizer();
    
    void ApplyMovements(MovesList moves);
};

#endif