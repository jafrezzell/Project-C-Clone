#include "GameObject.h";
#include "TextureManager.h"

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
}

GameObject::~GameObject()
{
}

void GameObject::update()
{
	destR.x = transform.x;
	destR.y = transform.y;
	destR.w = Game::tileSize * transform.scale;
	destR.h = Game::tileSize * transform.scale;
}

void GameObject::render()
{
	TextureManager::Draw(texture, srcR, destR, Game::renderer);
}
