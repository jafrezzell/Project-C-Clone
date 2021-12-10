#pragma once
#include "Game.h"

class GameObject {
public:
	GameObject();
	GameObject(const char* textureSheet,Transform transform);
	~GameObject();

	virtual void update();
	virtual void render();

	bool handleCollision(GameObject* other);

	void toggleGravity();
	Transform transform;
	Transform origin;

	SDL_Texture* texture;
	SDL_Rect srcR, destR;
	//SDL_Renderer* renderer;

	bool gravity;
	bool isFalling;
	bool collision;

	int horizontal;
	int vertical;
	int speed;

	bool isRight = true;
	bool isActive = true;

private:

};