#include "Level.h"
#include "TextureManager.h"
#include <iostream>
const int arr[22][25] = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
};
const int height = 22;
const int width = 25;
Level::Level(Player* player, int[22][25])
{
	this->playerRef = player;
	this->bgtex1 = TextureManager::LoadTexture("assets/Temple/background.png", Game::renderer);
	this->bgtex2 = TextureManager::LoadTexture("assets/Temple/background2.png", Game::renderer);
	this->bgtex3 = TextureManager::LoadTexture("assets/Temple/background4.png", Game::renderer);
	processIntMap();
}

Level::Level()
{
}

Level::~Level()
{
}

void Level::update()
{
	for (auto& obj : this->gameObjects) {
		obj.update();
	}
}

void Level::render()
{
	for (auto& obj : this->gameObjects) {
		obj.render();
	}
}

void Level::renderBG()
{
	TextureManager::DrawBackground(bgtex1, Game::renderer, 4);
	TextureManager::DrawBackground(bgtex2, Game::renderer, 2);
	TextureManager::DrawBackground(bgtex3, Game::renderer, 1);
}

void Level::events()
{
	for (auto& obj : this->gameObjects) {
		if (obj.handleCollision(playerRef)) {
		}
	}
}

void Level::processIntMap()
{
	GameObject g;
	for (int i = 0;i< height; i++) {
		for (int j = 0; j < width; j++) {
			switch (arr[i][j]) {
			case 1://Invis Wall
				//std::cout << i<< " "<< j << std::endl;
				g = GameObject("", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			case 2:
				g = GameObject("assets/floor.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			}
		}
	}
}


