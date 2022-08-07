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
    CROUCH_BLOCK,
    JUMP_BLOCK
};
enum InputStatus
{
    isPressed,
    isRealeased
};
