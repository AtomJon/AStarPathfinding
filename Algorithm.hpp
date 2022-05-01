#include <array>
#include <list>

#include <SFML/Graphics.hpp>

const sf::Vector2i UP = {0,1}, DOWN = {0,-1}, LEFT = {-1,0}, RIGHT = {1,0};

typedef std::list<sf::Vector2i> MovesList;

class Algorithm : public sf::Drawable
{
private:
    sf::Vector2i position;
    
    std::list<sf::Vector2i> moves;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Algorithm(sf::Vector2i);
    ~Algorithm();
    
    MovesList Solve(std::array<bool, 64>);
    void ApplyMovements(MovesList);
    
    void Render(sf::RenderWindow);
};

Algorithm::Algorithm(sf::Vector2i startingPosition)
{
    position = startingPosition;
}

Algorithm::~Algorithm()
{
}

MovesList Algorithm::Solve(std::array<bool, 64> grid)
{
    moves = {RIGHT, RIGHT, RIGHT, RIGHT, RIGHT};
    
    return moves;
}

void Algorithm::ApplyMovements(MovesList moves)
{
    for (auto &&i : moves)
    {
        this->position += i;
    }
    
}

void Algorithm::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape shape{{50.f,50.f}};
    sf::Vector2f pos{position.x * 100.f + 25, position.y * 100.f + 25};
    
    shape.setFillColor(sf::Color::White);
    
    shape.setPosition(pos);
    
    target.draw(shape);
}