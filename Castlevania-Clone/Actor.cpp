#include "Actor.h"
Actor::Actor(const char* textureSheet, Transform transform) : GameObject(textureSheet, transform)
{
	horizontal = 0;
	vertical = 0;
	health = 100;
	maxHealth = 100;
}

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::update()
{
	GameObject::update();
}
