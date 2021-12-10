#pragma once
#include "GameObject.h"
class GoalTile : public GameObject {
public:
	GoalTile();
	~GoalTile();
	bool handleCollision(GameObject* other);
};