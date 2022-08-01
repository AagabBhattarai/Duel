#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerState.h"

class Refree
{
    private:
        float p1_health;
        float p2_health;
    public:
        Refree(float p1_health, float p2_health);
        float getP1Health();
        float getP2Health();
        void mediate(PlayerState p1_state, PlayerState p2_state);
};