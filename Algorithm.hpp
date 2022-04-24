#include <array>
#include <list>

#include <SFML/Graphics.hpp>

const sf::Vector2i UP = {0,1}, DOWN = {0,-1}, LEFT = {-1,0}, RIGHT = {1,0};

class Algorithm : public sf::Drawable
{
private:
    sf::Vector2u position;
    
    std::list<sf::Vector2i> moves;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Algorithm(sf::Vector2u);
    ~Algorithm();
    
    void Solve(std::array<bool, 64>);
    void Render(sf::RenderWindow);
};

Algorithm::Algorithm(sf::Vector2u startingPosition)
{
    position = startingPosition;
}

Algorithm::~Algorithm()
{
}

void Algorithm::Solve(std::array<bool, 64> grid)
{
    moves = {RIGHT, RIGHT, RIGHT, RIGHT};
}

void Algorithm::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape shape{{50.f,50.f}};
    sf::Vector2f pos{position.x * 100.f + 25, position.y * 100.f + 25};
    
    shape.setFillColor(sf::Color::White);
    
    shape.setPosition(pos);
    
    target.draw(shape);
}