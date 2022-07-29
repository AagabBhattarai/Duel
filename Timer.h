#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Timer
{
    private:
        sf::Text text;
        int time;
    public:
    Timer(sf::Font& font, int time);
    ~Timer();
    void update(int time);
    void Draw(sf::RenderWindow& window);
};