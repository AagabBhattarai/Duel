#pragma once
#include <SFML/Graphics.hpp>

class HealthBar
{
    private:
        sf::RectangleShape outline;
        sf::RectangleShape health;
        sf::RectangleShape damage;
        bool player1_or_player2;
    public:
    HealthBar(sf::Vector2f outline, sf::Vector2f health, sf::Vector2f damage,bool player1_or_player2);
    ~HealthBar();
    
    void healthUpdate(float currentHealth);
    void Draw(sf::RenderWindow& window);
};


