#pragma once
#include "GameObject.h"
class GoalTile : public GameObject {
public:
	GoalTile(const char* textureSheet, Transform transform);
	~GoalTile();
	virtual bool handleCollision(GameObject* other);
};