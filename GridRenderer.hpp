#ifndef GRID_RENDER_H
#define GRID_RENDER_H

#include "Utils.hpp"

#include <SFML/Window.hpp>

namespace NeutronicPathfinding
{
    class GridRenderer
    {
    private:
        Boolean8x8Grid* grid;
        
        RenderWindow* currentWindow;
    public:
        GridRenderer(Boolean8x8Grid* _grid);
        ~GridRenderer();
        
        void Render(RenderWindow* window);
        
        void RenderIndex(int);
        
        sf::VertexBuffer GetVerticesFromIndex(int);
    };
    
}

#endif