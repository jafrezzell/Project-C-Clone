#include "WanderingObstacle.h"
#include "Utils.h"
using namespace Utilities;
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

void WanderingObstacle::update()
{
	RandomGenerator gen = RandomGenerator();
	bool vertFlip = gen.coinflip();
	bool horFlip = gen.coinflip();
	if (vertFlip)
		this->vertical = vertFlip;
	else
		this->vertical = -1;

	if (horFlip)
		this->horizontal = horFlip;
	else
		this->horizontal = -1;
	Actor::update();
}
