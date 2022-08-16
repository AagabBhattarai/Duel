#pragma once 
#include <SFML/Graphics.hpp>

class Power
{
    protected:
        sf::RectangleShape power_spark;
        sf::IntRect spark_uv;
    public:
        Power(sf::Texture* texture);
        void Draw(sf::RenderWindow& window);
        void Update(int left);
        void setPosition(sf::Vector2f power_position);
};