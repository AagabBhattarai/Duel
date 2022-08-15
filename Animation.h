#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerState.h"

class Animation
{
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    float totalTime;
    static const float switchTime_p1[10][16]; // Stores all the frames delay(i.e how long to display a particular frame)
    static const float switchTime_p2[10][16]; // Stores all the frames delay(i.e how long to display a particular frame)
    
    PlayerState previous_playerState;

public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount);
    ~Animation();
    void Update_p1(PlayerState playerstate, float deltaTime, bool faceRight);
    void Update_p2(PlayerState playerstate, float deltaTime, bool faceRight);

    //int getCurrrentState();
public:
    sf::IntRect uvRect;
protected:
    InputStatus input_status;
    bool reaction_done;
    bool impact_phase;
    bool transition_phase;
    bool combo_move;
public:
    bool isImpactPhase();
    bool isTransitionPhase();
};

