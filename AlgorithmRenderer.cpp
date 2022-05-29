#include "AlgorithmRenderer.hpp"

#include <array>
#include <list>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"
#include "BaseAlgorithm.hpp"

const float sizeOfTileOnScreen = 100.;

const sf::Vector2f characterSize{50., 50.};
const sf::Color characterColor = sf::Color::White;

const sf::Vector2f pathMarkerSize{50., 20.};
const sf::Color pathMarkerColor = sf::Color::Blue;

sf::RectangleShape CreateRectangleFromGridPosAndSize(GridCoords gridPos, sf::Vector2f size, sf::Color color)
{
    float offsetX = (sizeOfTileOnScreen - size.x) / 2.;
    float offsetY = (sizeOfTileOnScreen - size.y) / 2.;
    
    sf::Vector2f posTranslatedToScreen{
        gridPos.x * sizeOfTileOnScreen + offsetX,
        gridPos.y * sizeOfTileOnScreen + offsetY
    };
    
    sf::RectangleShape shape{size};
    
    shape.setPosition(posTranslatedToScreen);
    shape.setFillColor(color);
    
    return shape;
}

void DrawCharacter(sf::RenderTarget& target, GridCoords position)
{
    auto shape = CreateRectangleFromGridPosAndSize(position, characterSize, characterColor);
    
    target.draw(shape);
}

void DrawPathMarker(sf::RenderTarget& target, GridCoords pos)
{
    auto shape = CreateRectangleFromGridPosAndSize(pos, pathMarkerSize, pathMarkerColor);
    
    target.draw(shape);
}

namespace NeutronicPathfinding
{
    AlgorithmRenderer::AlgorithmRenderer(BaseAlgorithm* algo)
    {
        algorithm = algo;
    }

    AlgorithmRenderer::~AlgorithmRenderer()
    {
    }

    void AlgorithmRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        GridCoords position = algorithm->position;
        
        DrawCharacter(target, position);
    }
}