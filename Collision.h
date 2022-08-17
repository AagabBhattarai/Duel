#pragma once
#include <SFML/Graphics.hpp>


class Collision
{
public:
	Collision();
	static bool checkCollision(float p1x, float p2x, float p1y, float p2y);
	static bool checkCollisionPower(float p1x, float p2x, float p1y, float p2y);

};