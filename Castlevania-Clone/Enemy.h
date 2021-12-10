#pragma once
#include "Actor.h"
#include "Player.h"

class Enemy : public Actor {
public:
	Enemy();
	Enemy(const char* textureSheet, Transform transform, Player* currentPlayer);
	~Enemy();

	Animation anim_LeftIdle;
	Animation anim_RightIdle;
	Animation anim_LeftAttack;
	Animation anim_RightAttack;
	Animation anim_LeftDeath;
	Animation anim_RightDeath;

	std::vector<GameObject*> FireballList;

	bool isAttacking = false;
	bool hasFired = false;
	float AttackRange = 100.0f;

	Player* currentPlayer;

	float DistanceToPlayer();
	virtual void LoadAllAnimations();
	virtual void update();
	virtual void render();
};