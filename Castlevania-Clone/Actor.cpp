#include "Actor.h"
#include "TextureManager.h"

Actor::Actor(const char* textureSheet, Transform transform) : GameObject(textureSheet, transform)
{
	horizontal = 0;
	vertical = 0;
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

void Actor::LoadAnimation(std::vector<SDL_Texture*> &animation, std::string filePath, int numOfFrames) 
{
	int lenOfAnim = numOfFrames;
	std::string fullPngName = "";

	for (int i = 0; i < numOfFrames; i++) {
		fullPngName = filePath + "/frame_";
		fullPngName += std::to_string(i) + ".png";
		animation.push_back(TextureManager::LoadTexture(fullPngName.c_str(), Game::renderer));
	}
}

void Actor::PlayAnimation(std::vector<SDL_Texture*> &animation, bool loop)
{
	if (this->currentAnimationPlaying != animation)
	{
		currentAnimationPlaying = animation;
		this->currentAnimFrame = 0;
	}
	else 
	{
		this->currentAnimFrame++;
	}

	if (currentAnimFrame >= animation.size() && loop) 
	{
		this->currentAnimFrame = 0;
	}
	else if(currentAnimFrame >= animation.size() && !loop){//If character is "stuck" at the end of an animation, it's because of this if-statement
		this->currentAnimFrame = animation.size() - 1;
	}

	this->texture = animation[currentAnimFrame];
}

void Actor::LoadAllAnimations() 
{

}