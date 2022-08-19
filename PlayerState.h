#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum PlayerState
{
    IDLE,
    PUNCH,
    WALK,
    JUMP,
    CROUCH,
    KICK,
    REACTION,
    STAND_BLOCK,
    STOMACH_REACTION,
    POWER
};
enum InputStatus
{
    isPressed,
    isReleased
};
