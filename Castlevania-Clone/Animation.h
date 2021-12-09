#pragma once
#include "Game.h"

class Animation {

public:
	std::vector<SDL_Texture*> clips;
	int animationLength = 1;
	float animationSpeed = 1.0f;

	Animation(std::string filePath, int numOfFrames, float animationSpeed);
	Animation();
	~Animation();

	void LoadAnimation(std::string filePath, int numOfFrames);//Note:  Need to specify the number of animation frames in folder (don't need to have png at the end, just the directory), because i'm lazy...
};