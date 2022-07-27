
#include "Collision.h"

Collision::Collision(){}
bool  Collision::checkCollision(float p1x, float p2x)
{
	if (p1x +46 > p2x -46)
	{
		return true;
	}
	else 
		return false;
}
