
#include "Refree.h"

Refree::Refree(float p1_health, float p2_health)
{
    this->p1_health=p1_health;
    this->p2_health=p2_health;
}

float Refree::getP1Health()
{
    return p1_health;
}

float Refree::getP2Health()
{
    return p2_health;
}

void Refree::mediate(PlayerState p1_state, PlayerState p2_state)
{
    if(p1_state == PlayerState::PUNCH && (p2_state != PlayerState::STAND_BLOCK) )
    {
        p2_health -=20;
    }
    else if(p2_state == PlayerState::PUNCH && (p1_state != PlayerState::STAND_BLOCK) )
    {
        p1_health -=20;
    }
    else if(p2_state == PlayerState::KICK && (p1_state != PlayerState::STAND_BLOCK) )
    {
        p1_health -=20;
    }
}


