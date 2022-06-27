#include "Simulation.hpp"

#include <iostream>
#include <math.h>

#include <SFML/Graphics.hpp>

#include "AlgorithmRenderer.hpp"
#include "PheromoneAlgorithm.hpp"

namespace NeutronicPathfinding
{
    Simulation::Simulation(sf::RenderWindow *win)
    {
        window = win;

        Regenerate();
    }

    void Simulation::Regenerate()
    {
        RegenerateGrid();

        ClearWindow();
        RenderGrid();
        DisplayWindow();

        algorithm->Initiate(&grid, STARTING_POSITION, TARGET_POSITION);
    }

    void Simulation::TickAndRender()
    {
        ClearWindow();

        RenderGrid();

        algorithm->Tick();
        window->draw(algoRenderer);

        DisplayWindow();
    }

    void Simulation::ClearWindow() { window->clear(sf::Color::Black); }
    void Simulation::DisplayWindow() { window->display(); }

    void Simulation::RenderGrid()
    {
        // Render grid
        for (size_t i = 0; i < 64; i++)
        {
            RenderIndex(i);
        }
    }

    void Simulation::RegenerateGrid()
    {
        grid = gridLoader->GenerateGrid();
    }

    void Simulation::RenderIndex(int index)
    {
        auto isWall = grid[index];

        if (isWall == true)
        {
            auto vertices = GetVerticesFromIndex(index);

            window->draw(vertices);
        }
    }

    sf::VertexBuffer Simulation::GetVerticesFromIndex(int index)
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