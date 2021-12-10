#include "GoalTile.h"

GoalTile::GoalTile(const char* textureSheet, Transform transform): GameObject(textureSheet, transform)
{
}

GoalTile::~GoalTile()
{
}

bool GoalTile::handleCollision(GameObject* other)
{
	bool val = GameObject::handleCollision(other);
	if (val) {
		Game::curlvl = 2;
	}
	return val;

	
}
