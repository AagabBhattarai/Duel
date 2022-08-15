#pragma once
#include <SFML/Graphics.hpp>

class EnergyBar
{
    private:
        sf::RectangleShape outline;
        sf::RectangleShape energy;
        sf::RectangleShape damage;
        bool player1_or_player2;
    public:
    EnergyBar(sf::Vector2f outline, sf::Vector2f energy, sf::Vector2f damage,bool player1_or_player2);
    // ~EnerthBar();
    
    void energyUpdate(float currentEnergy);
    void Draw(sf::RenderWindow& window);
};