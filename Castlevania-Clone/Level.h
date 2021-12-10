#pragma once
#include "Player.h";
#include <vector>
#include "Utils.h"
class Level {
public:
	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> wizards;
	SDL_Texture* bgtex1;
	SDL_Texture* bgtex2;
	SDL_Texture* bgtex3;
	Player* playerRef;
	Level(Player* player, int map[22][25], int id);
	Level();
	~Level();
	void update();
	void render();
	void renderBG();
	void events();
	void processIntMap(int map[22][25]);
	bool showThird;
	int id;
};