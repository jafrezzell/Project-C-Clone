#include "Player.h"

Player::Player()
{
}

Player::Player(const char* textureSheet, Transform transform) : Actor(textureSheet, transform)
{

}

Player::~Player()
{
}

void Player::LoadAllAnimations()
{
	this->LoadAnimation(this->anim_RightIdle, "assets/PlayerAnims/anim_IdleRight", 4);
	this->LoadAnimation(this->anim_LeftIdle, "assets/PlayerAnims/anim_IdleLeft", 4);
	this->LoadAnimation(this->anim_RightRun, "assets/PlayerAnims/anim_RunRight", 6);
	this->LoadAnimation(this->anim_LeftRun, "assets/PlayerAnims/anim_RunLeft", 6);
	this->LoadAnimation(this->anim_JumpLeft, "assets/PlayerAnims/anim_JumpLeft", 3);
	this->LoadAnimation(this->anim_JumpRight, "assets/PlayerAnims/anim_JumpRight", 3);
}