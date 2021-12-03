#include "Actor.h"
Actor::Actor(const char* textureSheet, Transform transform) : GameObject(textureSheet, transform)
{
	horizontal = 0;
	vertical = 0;
}

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::update()
{
	this->transform.x += horizontal;
	this->transform.y -= 10*vertical;
	GameObject::update();
}
