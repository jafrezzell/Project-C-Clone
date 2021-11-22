#pragma once
#include "Game.h"

class GameObject {
public:
	GameObject();
	GameObject(const char* textureSheet,Transform transform);
	~GameObject();

	void update();
	void render();
private:
	SDL_Texture* texture;
	SDL_Rect srcR, destR;
	//SDL_Renderer* renderer;
	
	Transform transform;
};