#pragma once
#include <SFML/Graphics.hpp>


class Collision
{
public:
	Collision();
	static bool checkCollision(float p1x, float p2x);
	static bool checkCollisionPower(float p1x, float p2x);

};