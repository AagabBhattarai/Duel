#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerState.h"

class Animation
{
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    float totalTime;
    static const float switchTime[10][16]; // Stores all the frames delay(i.e how long to display a particular frame)
    // PlayerState previous_playerState;

public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount);
    ~Animation();
    void Update(PlayerState playerstate, float deltaTime, bool faceRight);
    //int getCurrrentState();
public:
    sf::IntRect uvRect;
protected:
    InputStatus input_status;
};

