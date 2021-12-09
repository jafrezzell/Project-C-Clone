#pragma once
#include "Actor.h"

class Player : public Actor {
public:
	Player();
	Player(const char* textureSheet, Transform transform);
	~Player();

	Animation anim_LeftIdle;
	Animation anim_RightIdle;
	Animation anim_LeftRun;
	Animation anim_RightRun;
	Animation anim_JumpLeft;
	Animation anim_JumpRight;
	Animation anim_AttackLeft;
	Animation anim_AttackRight;

	bool isAttacking = false;


	virtual void LoadAllAnimations();
	virtual void update();
private:
};