#include "AlgorithmRenderer.hpp"

#include <array>
#include <list>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"

const float sizeOfTileOnScreen = 100.;

const sf::Vector2f characterSize{50., 50.};
const sf::Color characterColor = sf::Color::White;

const sf::Vector2f pathMarkerSize{50., 20.};
const sf::Color pathMarkerColor = sf::Color::Blue;

sf::RectangleShape CreateRectangleFromGridPosAndSize(sf::Vector2i gridPos, sf::Vector2f size, sf::Color color)
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

void DrawCharacter(sf::RenderTarget& target, sf::Vector2i position)
{
    auto shape = CreateRectangleFromGridPosAndSize(position, characterSize, characterColor);
    
    target.draw(shape);
}

void DrawPathMarker(sf::RenderTarget& target, sf::Vector2i pos)
{
    auto shape = CreateRectangleFromGridPosAndSize(pos, pathMarkerSize, pathMarkerColor);
    
    target.draw(shape);
}

AlgorithmRenderer::AlgorithmRenderer(sf::Vector2i pos)
{
    entryOnGrid = pos;
}

AlgorithmRenderer::~AlgorithmRenderer()
{
}

void AlgorithmRenderer::ApplyMovements(MovesList _moves)
{
    this->moves = _moves;
}

void AlgorithmRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Vector2i position{entryOnGrid};
    
    for (auto &&currentMove : moves)
    {        
        DrawPathMarker(target, position);
        position += currentMove;
    }    
    
    DrawCharacter(target, position);
}