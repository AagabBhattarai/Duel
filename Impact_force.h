#pragma once 
#include <SFML/Graphics.hpp>

class ImpactForce
{
    protected:
        sf::RectangleShape hit_spark;
        ImpactForce(sf::Texture* texture);
        sf::IntRect spark_uv;
    public:
        void Draw(sf::RenderWindow& window);
        void Update(int left);
};