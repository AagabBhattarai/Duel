#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerState.h"

class Refree
{
    private:
        float p1_health;
        float p2_health;
        PlayerState new_state_p1;
        PlayerState new_state_p2;
        bool p1_hit_p2;
        bool p2_hit_p1;

    public:
        Refree(float p1_health, float p2_health);
        float getP1Health();
        void setP1Health(float p1_h);


        float getP2Health();


        bool getP1_impact();
        void setP1_impact(bool set);

        bool getP2_impact();
        void setP2_impact(bool set);


        void mediate(PlayerState p1_state, PlayerState p2_state, bool p1_impact_phase, bool p2_impact_phase, bool p1_right_facing, bool p2_left_facing, bool isCombo);
        PlayerState getNewState_p1();
        PlayerState getNewState_p2();

};
