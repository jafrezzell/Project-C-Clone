#pragma once
#include "Game.h"

class GameObject {
public:
	GameObject();
	GameObject(const char* textureSheet,Transform transform);
	~GameObject();

	void update();
	void render();

	bool handleCollision(SDL_Rect* a);

	void toggleGravity();
	Transform transform;

	SDL_Texture* texture;
	SDL_Rect srcR, destR;
	//SDL_Renderer* renderer;

	bool gravity;
	bool isFalling;
private:

};