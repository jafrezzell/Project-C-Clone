#include "GameObject.h";
#include "TextureManager.h"
#include <map>
#include <algorithm>
#include <iostream>
#include <stdio.h>
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
GameObject::GameObject()
{
}

GameObject::GameObject(const char* textureSheet,Transform transform)
{
	this->transform = transform;
	//this->renderer = renderer;
	srcR.h = Game::tileSize * transform.scale;
	srcR.w = Game::tileSize * transform.scale;
	srcR.x = 0;
	srcR.y = 0;

	destR.h = Game::tileSize * transform.scale;
	destR.w = Game::tileSize * transform.scale;
	destR.x = 0;
	destR.y = 0;

	texture = TextureManager::LoadTexture(textureSheet, Game::renderer);
	this->gravity = false;
	this->isFalling = false;
	horizontal = 0;
	vertical = 0;
}

GameObject::~GameObject()
{
}

void GameObject::update()
{
	this->transform.x += horizontal;
	this->transform.y -= vertical;
	if (gravity) {
		if (vertical > -4)
			vertical -= 1;
	}
	destR.x = transform.x;
	destR.y = transform.y;
	destR.w = Game::tileSize * transform.scale;
	destR.h = Game::tileSize * transform.scale;
}

void GameObject::render()
{
	TextureManager::Draw(texture, srcR, destR, Game::renderer);
}
/*a is usually the player and b is always 'this' game object*/
bool GameObject::handleCollision(GameObject* other)
{
	SDL_Rect* a = &other->destR;
	SDL_Rect* b = &this->destR;
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a->x;
	rightA = a->x + a->w;
	topA = a->y;
	bottomA = a->y + a->h;

	//Calculate the sides of rect B
	leftB = b->x;
	rightB = b->x + b->w;
	topB = b->y;
	bottomB = b->y + b->h;
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}
	//If none of the sides from A are outside B
	std::map<char, int> diffs;
	diffs['l'] = std::abs(rightA - leftB);
	diffs['r'] = std::abs(leftA - rightB);
	diffs['t'] = std::abs(bottomA - topB);
	diffs['b'] = std::abs(topA - bottomB);
	int minDist = NULL;
	char direction = 'e';
	for (auto thing : diffs) {
		if (minDist == NULL || thing.second <= minDist) {
			minDist = thing.second;
			direction = (char)thing.first;
		}
	}
	switch (direction) {
	case 'l': other->transform.x -= diffs['l'];
		break;
	case 'r': other->transform.x += diffs['r'];
		break;
	case 't': other->transform.y = topB - other->destR.h;
		other->gravity = false;
		other->vertical = 0;
		break;
	case 'b': other->transform.y += diffs['b'];
		break;
	}
	return true;
}


void GameObject::toggleGravity()
{
	this->gravity = !this->gravity;
}
