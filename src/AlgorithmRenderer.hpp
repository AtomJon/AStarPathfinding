#ifndef ALGORITHMRENDERER_H
#define ALGORITHMRENDERER_H

#include <array>
#include <list>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"
#include "BaseAlgorithm.hpp"

namespace NeutronicPathfinding
{
    class AlgorithmRenderer : public sf::Drawable
    {
    private:
        BaseAlgorithm* algorithm;
    public:
        AlgorithmRenderer(BaseAlgorithm* algorithm);
        ~AlgorithmRenderer();
        
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}

#endif