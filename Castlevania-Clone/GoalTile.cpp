#include "GoalTile.h"

GoalTile::GoalTile()
{
}

GoalTile::~GoalTile()
{
}

bool GoalTile::handleCollision(GameObject* other)
{
	return GameObject::handleCollision(other);
	
}
