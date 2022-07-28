
#include "Collision.h"

Collision::Collision(){}
bool  Collision::checkCollision(float p1x, float p2x)
{
	if (abs(p1x-p2x)/10 <= 5) //instead of p1x>p2x
	{
		return true;
	}
	else 
		return false;
}
