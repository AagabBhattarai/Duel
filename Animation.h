#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerState.h"

class Animation
{
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();
    void Update(PlayerState playerstate, float deltaTime, bool faceRight);
    int getCurrrentState();
public:
    sf::IntRect uvRect;



};