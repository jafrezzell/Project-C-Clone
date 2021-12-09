#include "Actor.h"
#include "TextureManager.h"

Actor::Actor(const char* textureSheet, Transform transform) : GameObject(textureSheet, transform)
{
	health = 100;
	maxHealth = 100;
}

Actor::Actor()
{

}

Actor::~Actor()
{
}

void Actor::update()
{
	GameObject::update();
}

void Actor::PlayAnimation(Animation animation, bool loop)
{
	if (this->currentAnimationPlaying.clips != animation.clips)
	{
		this->currentAnimationPlaying = animation;
		this->currentAnimFrame = 0;
	}
	else 
	{
		this->currentAnimFrame += this->currentAnimationPlaying.animationSpeed;
	}

	if (this->currentAnimFrame >= animation.animationLength - 1 && loop) 
	{
		this->currentAnimFrame = 0;
	}
	else if(this->currentAnimFrame >= animation.animationLength - 1 && !loop){//If character is "stuck" at the end of an animation, it's because of this if-statement
		this->currentAnimFrame = animation.animationLength - 1;
	}

	this->texture = animation.clips[this->currentAnimFrame];
}

void Actor::LoadAllAnimations() 
{

}