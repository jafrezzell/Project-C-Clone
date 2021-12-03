#pragma once
#include "GameObject.h"
class Actor : public GameObject {
public:
	Actor(const char* textureSheet, Transform transform);
	Actor();
	~Actor();
	void update();
	int horizontal;
	int vertical;

private:
};