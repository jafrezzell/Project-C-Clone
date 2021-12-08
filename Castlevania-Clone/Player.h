#pragma once
#include "Actor.h"
class Player : public Actor {
public:
	Player();
	Player(const char* textureSheet, Transform transform);
	~Player();

	std::vector<SDL_Texture*> anim_LeftIdle;
	std::vector<SDL_Texture* > anim_RightIdle;
	std::vector<SDL_Texture*> anim_LeftRun;
	std::vector<SDL_Texture*> anim_RightRun;
	std::vector<SDL_Texture*> anim_JumpLeft;
	std::vector<SDL_Texture*> anim_JumpRight;

	virtual void LoadAllAnimations();
private:
};