
#include "Refree.h"

Refree::Refree(float p1_health, float p2_health)
{
    this->p1_health=p1_health;
    this->p2_health=p2_health;
    p1_hit_p2 = false;
    p2_hit_p1 = false;

}

float Refree::getP1Health()
{
    return p1_health;
}

float Refree::getP2Health()
{
    return p2_health;
}

void Refree::mediate(PlayerState p1_state, PlayerState p2_state, bool p1_impact_phase, bool p2_impact_phase, bool p1_right_facing, bool p2_left_facing)
{
    //initally no player has struck a blow
    p1_hit_p2 = false;
    p2_hit_p1 = false;

    //check if any of the player has been struck    
    if(p1_right_facing == true) // this means this player1
    {
        if(p1_state == PlayerState::PUNCH && (p2_state != PlayerState::STAND_BLOCK) && p1_impact_phase)
        {
            p2_health -=20;
            new_state_p2 = PlayerState::REACTION;
            new_state_p1 = p1_state;
            p1_hit_p2 = true;
            //is p2 is getting punched that means p2 is obviouly not punching so,
            p2_hit_p1 = false;
        }
        else if(p1_state == PlayerState::KICK && (p2_state != PlayerState::STAND_BLOCK) && p1_impact_phase)
        {
            p2_health -=20;
            new_state_p2 = PlayerState::REACTION;
            new_state_p1 = p1_state;
            p1_hit_p2 = true;
            //is p2 is getting punched that means p2 is obviouly not punching so,
            p2_hit_p1 = false;
        }
    }
    if(p2_left_facing == true)
    {
        if(p2_state == PlayerState::PUNCH && (p1_state != PlayerState::STAND_BLOCK) && p2_impact_phase)
        {
            p1_health -=20;
            new_state_p1 = PlayerState::REACTION;
            new_state_p2 = p2_state;
            p2_hit_p1 = true;
            //if player 1 iis getting punched that means p1 is not punching
            p1_hit_p2 = false;
        }
        else if(p2_state == PlayerState::KICK && (p1_state != PlayerState::STAND_BLOCK) &&p2_impact_phase )
        {
            p1_health -=20;
            new_state_p2 = p2_state;
            p2_hit_p1 = true;
            //if player 1 iis getting punched that means p1 is not punching
            p1_hit_p2 = false;
        }
    }
}

PlayerState Refree::getNewState_p1()
{
    return new_state_p1;
}

PlayerState Refree::getNewState_p2()
{
    return new_state_p2;
}
bool Refree::getP1_impact()
{
    return p1_hit_p2;
}
void Refree::setP1_impact(bool set)
{
     p1_hit_p2 = set;
}

bool Refree::getP2_impact()
{
    return p2_hit_p1;
}
void Refree::setP2_impact(bool set)
{
     p2_hit_p1 = set;
}
