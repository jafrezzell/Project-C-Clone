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
	GameObject box = GameObject("assets/wall.png", Transform(50,0,1));
	objList.push_back(box);
	//player.toggleGravity();

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
			player.vertical = 1;
		}
		else {
			player.vertical = 0;
		}

		for (auto& obj : objList) {
			obj.handleCollision(&player.destR);
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
