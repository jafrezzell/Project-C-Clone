#pragma once
#include "Actor.h"
class Player : public Actor {
public:
	Player();
	Player(const char* textureSheet, Transform transform);
	~Player();

private:
};