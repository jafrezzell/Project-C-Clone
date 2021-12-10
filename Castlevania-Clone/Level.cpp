#include "Level.h"
#include "TextureManager.h"
#include <iostream>
const int arr[22][25] = {
1,1,1,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
3,5,5,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
3,5,5,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,0,0,3,3,0,0,1,
3,5,5,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,0,3,3,3,3,0,1,
3,5,5,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,3,3,3,3,3,3,1,
3,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,3,5,5,5,5,3,1,
3,5,5,4,4,4,4,4,4,3,7,7,7,6,6,0,0,0,3,3,5,5,3,3,1,
3,5,5,5,5,5,5,5,5,3,3,3,0,0,0,0,0,0,0,3,5,4,3,0,1,
3,4,5,5,5,5,5,5,5,3,3,0,0,0,0,0,0,0,0,3,5,5,3,0,1,
3,5,5,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,0,3,4,5,3,0,1,
3,5,4,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,0,5,5,5,3,0,1,
3,5,5,5,4,5,5,5,5,3,0,0,0,0,0,0,0,0,0,5,5,4,3,0,1,
3,5,5,5,5,5,4,5,5,3,0,0,0,0,0,0,0,0,0,3,5,5,3,0,1,
3,5,5,5,5,5,5,5,4,3,0,3,3,3,3,3,0,0,0,3,5,5,3,0,1,
3,5,5,5,5,5,5,5,5,3,0,3,5,5,5,3,0,3,3,5,4,5,3,0,1,
3,5,5,5,5,5,5,3,3,3,3,5,5,5,5,3,3,3,5,5,5,5,3,3,3,
3,5,5,5,5,3,3,3,3,3,5,5,5,5,5,5,5,5,5,5,5,4,5,5,3,
3,5,5,3,3,3,3,3,3,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
};
const int height = 22;
const int width = 25;
Level::Level(Player* player)
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
			case 3:
				g = GameObject("assets/bricks.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			case 4:
				g = GameObject("assets/backwbridge.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			case 5:
				g = GameObject("assets/backbricks.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				g.collision = false;
				this->gameObjects.push_back(g);
				break;
			case 6:
				g = GameObject("assets/bridge.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			case 7: 
				g = GameObject("assets/supportedbridge.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			}

		}
	}
}


