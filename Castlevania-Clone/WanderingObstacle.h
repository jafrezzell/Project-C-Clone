#pragma once
#include "Actor.h"

class WanderingObstacle : public Actor {
public:
	WanderingObstacle(const char* textureSheet, Transform transform, float speed);
	WanderingObstacle();
	~WanderingObstacle();

	void update();

	float speed;
	float time;

private:
};