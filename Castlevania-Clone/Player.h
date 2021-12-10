#pragma once
#include "Actor.h"

class Player : public Actor {
public:
	Player();
	Player(const char* textureSheet, Transform transform);
	~Player();

	GameObject RightHitBox;
	GameObject LeftHitBox;

	Animation anim_LeftIdle;
	Animation anim_RightIdle;
	Animation anim_LeftRun;
	Animation anim_RightRun;
	Animation anim_JumpLeft;
	Animation anim_JumpRight;
	Animation anim_AttackLeft;
	Animation anim_AttackRight;
	Animation anim_DeathLeft;
	Animation anim_DeathRight;

	bool isAttacking = false;
	bool isLeftAttack = false;
	bool isRightAttack = false;

	virtual void LoadAllAnimations();
	virtual void update();

private:
};