#include <iostream>
#include <math.h>
#include <cmath>
#include <random>

#include <SFML/Graphics.hpp>

#include "Algorithm.hpp"
#include "AlgorithmRenderer.hpp"

#ifndef STARTING_POSITION
#define STARTING_POSITION {1,4}
#endif

class Simulation
{
private:
    const sf::Color BROWN{127, 85, 57, 255};
    const sf::Color GRAY{128, 128, 128, 255};
    std::array<bool, 64> grid;
    
    Algorithm algorithm;
    AlgorithmRenderer algoRenderer{STARTING_POSITION};
    
    sf::RenderWindow* window;
    
    void RenderIndex(int);
    sf::Vector2u GetCoordsFromIndex(int);
    sf::VertexBuffer GetVerticesFromIndex(int);
public:
    Simulation(sf::RenderWindow*);
    ~Simulation();
    
    void Render();
    
    void RegenerateGrid();
    
    void CalculatePath();
};

Simulation::Simulation(sf::RenderWindow* win)
{
    window = win;
    
    RegenerateGrid();
}

Simulation::~Simulation()
{
}

void Simulation::RegenerateGrid()
{
    static std::random_device dev;
    static std::mt19937 rng(dev());
    static std::uniform_int_distribution<std::mt19937::result_type> dist2(0,1); // Distribution range
    
    for (size_t i = 0; i < 64; i++)
    {
        if (
            (i > 17 && i < 22) ||
            (i > 33 && i < 38) ||
            (i > 25 && i < 30) ||
            (i > 41 && i < 46)
        )
        {
            bool isWall = dist2(rng);
            grid[i] = isWall;
        }
    }
    
    // std::cout << "Nr. 64 is: " << (grid[64] ? "wall" : "not wall") << std::endl;
}

void Simulation::CalculatePath()
{
    auto moves = algorithm.Solve(grid, STARTING_POSITION);
    algoRenderer.ApplyMovements(moves);
}

void Simulation::Render()
{
    window->clear(sf::Color::Black);
    
    for (size_t i = 0; i < 64; i++)
    {
        RenderIndex(i);
    }
    
    window->draw(algoRenderer);
    
    window->display();
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
    auto coords = GetCoordsFromIndex(index);
    
    float offsetX = coords.x * 100;
    float offsetY = coords.y * 100;
    
    float size = 100;
    
    sf::VertexBuffer buffer{sf::PrimitiveType::Triangles};
    buffer.create(6);
    
    sf::Vector2f vertices[] {
        {0.f,1.f},
        {0.f,0.f},
        {1.f,0.f},
        
        {0.f,1.f},
        {1.f,0.f},
        {1.f,1.f}
    };
    
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

sf::Vector2u Simulation::GetCoordsFromIndex(int index)
{
    auto div = std::div(index, 8);
    
    uint x = div.rem;
    uint y = div.quot;
    
    return {x,y};
}