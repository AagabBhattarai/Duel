
#include "Collision.h"

Collision::Collision(){}
bool  Collision::checkCollision(float p1x, float p2x)
{
	if (abs((p1x-p2x)) /10 <=15)//p1x-p2x /10 <=10 	
	{
		return true;
	}
	else 
		return false;
}
