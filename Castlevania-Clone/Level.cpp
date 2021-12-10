#include "Level.h"
#include "TextureManager.h"
#include <iostream>
#include "Enemy.h"
const int height = 22;
const int width = 25;
Level::Level(Player* player, int map[22][25])
{
	this->playerRef = player;
	this->bgtex1 = TextureManager::LoadTexture("assets/Temple/background.png", Game::renderer);
	this->bgtex2 = TextureManager::LoadTexture("assets/Temple/background2.png", Game::renderer);
	this->bgtex3 = TextureManager::LoadTexture("assets/Temple/background4.png", Game::renderer);
	this->showThird = false;
	processIntMap(map);
}

Level::Level()
{
}

Level::~Level()
{
}

void Level::update()
{
	GameObject playerCurrentHitBox;
	if (playerRef->LeftHitBox.isActive || playerRef->RightHitBox.isActive)
	{
		if (playerRef->LeftHitBox.isActive)
			playerCurrentHitBox = playerRef->LeftHitBox;
		else
			playerCurrentHitBox = playerRef->RightHitBox;
		for (auto& obj : gameObjects) {
			if (obj->isActive && dynamic_cast<Enemy*>(obj))
			{
				if (playerCurrentHitBox.handleCollision(obj))
					dynamic_cast<Enemy*>(obj)->isDead = true;
			}
		}
	}
	for (auto& obj : this->gameObjects) {
		obj->update();
		if (dynamic_cast<Enemy*>(obj)) {
			std::cout << "Yo" << std::endl;
			dynamic_cast<Enemy*>(obj)->update();
		}
	}
}

void Level::render()
{
	for (auto& obj : this->gameObjects) {
		obj->render();
	}
}

void Level::renderBG()
{
	TextureManager::DrawBackground(bgtex1, Game::renderer, 6);
	TextureManager::DrawBackground(bgtex2, Game::renderer, 2);
	if(showThird)
		TextureManager::DrawBackground(bgtex3, Game::renderer, 1);
}

void Level::events()
{
	for (auto& obj : this->gameObjects) {
		if (obj->handleCollision(playerRef)) {
		}
	}
}

void Level::processIntMap(int map[22][25])
{
	GameObject* g;
	Enemy* e;
	for (int i = 0;i< height; i++) {
		for (int j = 0; j < width; j++) {
			switch (map[i][j]) {
			case 1://Invis Wall
				//std::cout << i<< " "<< j << std::endl;
				g = new GameObject("", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			case 2:
				g = new GameObject("assets/floor.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			case 3:
				g = new GameObject("assets/bricks.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			case 4:
				g = new GameObject("assets/backwbridge.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			case 5:
				g = new GameObject("assets/backbricks.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				g->collision = false;
				this->gameObjects.push_back(g);
				break;
			case 6:
				g = new GameObject("assets/bridge.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			case 7: 
				g = new GameObject("assets/supportedbridge.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				this->gameObjects.push_back(g);
				break;
			case 8:
				g = new GameObject("assets/door.png", Transform(j * Game::tileSize, i * Game::tileSize, 1));
				g->collision = false;
				this->gameObjects.push_back(g);
				break;
			case 9: 
				e = new Enemy("assets/EnemyAnims/anim_IdleLeft/frame_0.png", Transform(j * Game::tileSize, i * Game::tileSize, 1), playerRef);
				e->LoadAllAnimations();
				this->gameObjects.push_back(e);
				break;
			}


		}
	}
}


