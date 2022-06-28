#include "GridRenderer.hpp"

#include <SFML/Window.hpp>

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
    
    void GridRenderer::Render(RenderWindow* window)
    {
        currentWindow = window;
        
        // Render grid
        for (size_t i = 0; i < 64; i++)
        {
            RenderIndex(i);
        }
        
        currentWindow = nullptr;
    }

    void GridRenderer::RenderIndex(int index)
    {
        bool isWall = grid[index];

        if (isWall == true)
        {
            auto vertices = GetVerticesFromIndex(index);

            currentWindow->draw(vertices);
        }
    }

    sf::VertexBuffer GridRenderer::GetVerticesFromIndex(int index)
    {
        auto coords = GetCoordsFrom8x8GridIndex(index);

        float offsetX = coords.x * 100.f;
        float offsetY = coords.y * 100.f;

        float size = 100;

        sf::VertexBuffer buffer{sf::PrimitiveType::Triangles};
        buffer.create(6);

        sf::Vector2f vertices[]{
            {0.f, 1.f},
            {0.f, 0.f},
            {1.f, 0.f},

            {0.f, 1.f},
            {1.f, 0.f},
            {1.f, 1.f}};

        sf::Vertex updatedVertices[6];

        for (size_t i = 0; i < 6; i++)
        {
            auto vert = vertices[i];

            float x = vert.x * size + offsetX;
            float y = vert.y * size + offsetY;

            sf::Vertex vertex{{x, y}};

            vertex.color = GRAY;

            updatedVertices[i] = vertex;
        }

        buffer.update(updatedVertices);

        return buffer;
    }
}