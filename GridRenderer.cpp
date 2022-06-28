#include "GridRenderer.hpp"

#include "Utils.hpp"

namespace NeutronicPathfinding
{    
    GridRenderer::GridRenderer(Boolean8x8Grid* _grid)
    {
        grid = _grid;
    }
    
    GridRenderer::~GridRenderer()
    {
    }
}