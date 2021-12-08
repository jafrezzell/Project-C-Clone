#pragma once
#include "GameObject.h"
class Actor : public GameObject {
public:
	Actor(const char* textureSheet, Transform transform);
	Actor();
	~Actor();
	void update();
	void LoadAnimation(std::vector<SDL_Texture*> &animation, std::string filePath, int numOfFrames);//Note:  Need to specify the number of animation frames in folder (don't need to have png at the end, just the directory), because i'm lazy...
	void PlayAnimation(std::vector<SDL_Texture*> &animation, bool loop);
	virtual void LoadAllAnimations();//Must be individually implemented for each Actor type.

	int health;
	int maxHealth = 100;

	//Represents the current frame an animation is at, if it is playing.
	int currentAnimFrame = 0;
	//Self explanatory
	std::vector<SDL_Texture*> currentAnimationPlaying;
private:
};