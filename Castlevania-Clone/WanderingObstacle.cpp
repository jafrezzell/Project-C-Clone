#include "WanderingObstacle.h"

WanderingObstacle::WanderingObstacle(const char* textureSheet, Transform transform, float speed): Actor(textureSheet, transform)
{
	this->speed = speed;
}

WanderingObstacle::WanderingObstacle()
{
}

WanderingObstacle::~WanderingObstacle()
{
}
