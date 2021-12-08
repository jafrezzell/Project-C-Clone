#pragma once
#include "Actor.h"
class WanderSpawner : public Actor {
public:
	WanderSpawner(const char* textureSheet, Transform transform, int spawnRate);
	WanderSpawner();
	~WanderSpawner();
	void update();
	int spawnRate;
	int counter;


};