#include "Player.h"

Player::Player()
{
}

Player::Player(const char* textureSheet, Transform transform) : Actor(textureSheet, transform)
{
	RightHitBox = GameObject("assets/wall.png", Transform(transform.x + 1, transform.y, transform.scale));
	LeftHitBox = GameObject("assets/wall.png", Transform(transform.x - 1, transform.y, transform.scale));
}

Player::~Player()
{
}

void Player::update()
{
	Actor::update();

	//Framework for continuing a player attack animation
	if ((currentAnimationPlaying.clips == anim_AttackLeft.clips || currentAnimationPlaying.clips == anim_AttackRight.clips))
	{
		if (currentAnimFrame == this->anim_AttackLeft.animationLength - 1)
			this->isAttacking = false;
		else if (currentAnimFrame >= 3 && currentAnimFrame <= 4)
		{
			if (this->isRight) {
				RightHitBox.isActive = true;
				LeftHitBox.isActive = false;
			}
			else {
				LeftHitBox.isActive = true;
				RightHitBox.isActive = false;
			}
		}
	}
	else {
		RightHitBox.isActive = false;
		LeftHitBox.isActive = false;
	}
	if (this->isAttacking) {
		if(this->isRight)
			this->PlayAnimation(anim_AttackRight, false);
		else
			this->PlayAnimation(anim_AttackLeft, false);
	}

	RightHitBox.transform.x = this->transform.x + 1;
	RightHitBox.transform.y = this->transform.y;
	LeftHitBox.transform.x = this->transform.x - 1;
	LeftHitBox.transform.y = this->transform.y;

	RightHitBox.update();
	LeftHitBox.update();
}

void Player::LoadAllAnimations()
{
	this->anim_LeftIdle = Animation("assets/PlayerAnims/anim_IdleLeft", 4, 0.05f);
	this->anim_RightIdle = Animation("assets/PlayerAnims/anim_IdleRight", 4, 0.05f);
	this->anim_LeftRun = Animation("assets/PlayerAnims/anim_RunLeft", 6, 0.25f);
	this->anim_RightRun = Animation("assets/PlayerAnims/anim_RunRight", 6, 0.25f);
	this->anim_JumpLeft = Animation("assets/PlayerAnims/anim_JumpLeft", 3, 0.25f);
	this->anim_JumpRight = Animation("assets/PlayerAnims/anim_JumpRight", 3, 0.25f);
	this->anim_AttackLeft = Animation("assets/PlayerAnims/anim_AttackLeft", 6, 0.25f);
	this->anim_AttackRight = Animation("assets/PlayerAnims/anim_AttackRight", 6, 0.25f);
	this->anim_DeathLeft = Animation("assets/PlayerAnims/anim_DeathLeft", 7, 0.25f);
	this->anim_DeathRight = Animation("assets/PlayerAnims/anim_DeathRight", 7, 0.25f);
}