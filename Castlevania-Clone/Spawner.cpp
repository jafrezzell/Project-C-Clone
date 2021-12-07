#include "Spawner.h"

Spawner::Spawner(const char* textureSheet, Transform transform, GameObject* enemyType, int spawnRate): Actor(textureSheet, transform)
{
	this->spawnRate = spawnRate;
	this->enemyType = enemyType;
}

Spawner::Spawner()
{
}

Spawner::~Spawner()
{
}

void Spawner::Spawn()
{
}
