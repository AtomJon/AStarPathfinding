#include "Utils.hpp"

namespace NeutronicPathfinding
{
    class GridRenderer
    {
    private:
        Boolean8x8Grid* grid;
    public:
        GridRenderer(Boolean8x8Grid* _grid);
        ~GridRenderer();
    };
    
}