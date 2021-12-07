#pragma once
#include "Actor.h"
class Spawner : public Actor {
public:
	Spawner(const char* textureSheet, Transform transform, GameObject* enemyType, int spawnRate);
	Spawner();
	~Spawner();
	void Spawn();
	int spawnRate;
	GameObject* enemyType;

};