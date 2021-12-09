#include "Animation.h"
#include "TextureManager.h"

Animation::Animation() 
{

}

Animation::~Animation()
{

}

Animation::Animation(std::string filePath, int numOfFrames, float animationSpeed)
{
	this->animationSpeed = animationSpeed;
	this->animationLength = numOfFrames;
	LoadAnimation(filePath, numOfFrames);
}

void Animation::LoadAnimation(std::string filePath, int numOfFrames)
{
	int lenOfAnim = numOfFrames;
	std::string fullPngName = "";

	for (int i = 0; i < numOfFrames; i++) {
		fullPngName = filePath + "/frame_";
		fullPngName += std::to_string(i) + ".png";
		this->clips.push_back(TextureManager::LoadTexture(fullPngName.c_str(), Game::renderer));
	}
}

