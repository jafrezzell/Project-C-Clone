#include "Game.h"
#include "GameObject.h";
#include "Actor.h"
#include "Player.h"
#include <vector>
SDL_Renderer* Game::renderer = nullptr;
Transform transform;
Player player; 

std::vector<GameObject> objList;


Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		Game::renderer = SDL_CreateRenderer(window, -1, 0);
		if (Game::renderer) {
			std::cout << "Renderer Created" << std::endl;
			SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}
	player = Player("assets/Enemy_Wizard.png",transform);
	GameObject box = GameObject("assets/wall.png", Transform(0,300,1));
	objList.push_back(box);
	GameObject box1 = GameObject("assets/wall.png", Transform(32, 300, 1));
	objList.push_back(box1);
	GameObject box2 = GameObject("assets/wall.png", Transform(64, 300, 1));
	objList.push_back(box2);
	GameObject box3 = GameObject("assets/wall.png", Transform(96, 300, 1));
	objList.push_back(box3);
	GameObject box4 = GameObject("assets/wall.png", Transform(128, 300, 1));
	objList.push_back(box4);
	GameObject box5 = GameObject("assets/wall.png", Transform(160, 300, 1));
	objList.push_back(box5);
	player.toggleGravity();
	
	player.update();
	for (auto& obj : objList) {
		obj.update();
	}

}

void Game::events()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			isRunning = false;
		}
		const Uint8* state = SDL_GetKeyboardState(NULL);
		if (state[SDL_SCANCODE_RIGHT]) {
			player.horizontal = 1;
		}
		else if (state[SDL_SCANCODE_LEFT]) {
			player.horizontal = -1;
		}
		else {
			player.horizontal = 0;
		}
		if (state[SDL_SCANCODE_SPACE]) {
			player.vertical = 10;
			player.gravity = true;
		}
		else if (state[SDL_SCANCODE_DOWN]) {
			player.vertical = -1;
		}


	}
	for (auto& obj : objList) {
		if (obj.handleCollision(&player)) {
		}
	}
}

void Game::update()
{
	player.update();
	for (auto& obj : objList) {
		obj.update();
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player.render();
	for (auto& obj : objList) {
		obj.render();
	}
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::running()
{
	return isRunning;
}
