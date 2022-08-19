
#include "Collision.h"

Collision::Collision(){}
bool  Collision::checkCollision(float p1x, float p2x, float p1y, float p2y)
{
	if (abs((p1x-p2x)) /10 <=15 &&  abs(p1y-p2y)/10 <= 6)//p1x-p2x /10 <=10 	
	{
		return true;
	}
	else 
		return false;
}
bool  Collision::checkCollisionPower(float p1x, float p2x, float p1y, float p2y)
{
	if (abs((p1x-p2x)) /10 <=2  &&  abs(p1y-p2y)/10 <= 6)//p1x-p2x /10 <=10 	
	{
		return true;
	}
	else 
		return false;
}
