#ifndef UTILS_TCC
#define UTILS_TCC

#include <cmath>

#include <SFML/Graphics.hpp>

using namespace sf;

template <typename T>
float DistanceBetweenVectors(Vector2<T> vectorX, Vector2<T> vectorY)
{
    float v1 = vectorY.x - vectorX.x;
    float v2 = vectorY.y - vectorX.y;
    
    float v1Pow = v1 * v1;
    float v2Pow = v2 * v2;
    
    float result = sqrt(v1Pow + v2Pow);

    return result;
}
#endif