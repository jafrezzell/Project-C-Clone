#include "WanderSpawner.h"

WanderSpawner::WanderSpawner(const char* textureSheet, Transform transform, int spawnRate): Actor(textureSheet, transform)
{
	this->spawnRate = spawnRate;
	this->counter = 0;
}

WanderSpawner::WanderSpawner()
{
	this->spawnRate = 10;
	this->counter = 0;
}

WanderSpawner::~WanderSpawner()
{
}

void WanderSpawner::update()
{
	counter++;
	if (counter >= spawnRate) {
		counter = 0;
	}
}
