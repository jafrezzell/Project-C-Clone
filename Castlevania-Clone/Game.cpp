#include "Game.h"
#include "GameObject.h";
#include "Actor.h"
#include "Player.h"
#include "WanderingObstacle.h"
#include "TextureManager.h"
#include <vector>
SDL_Renderer* Game::renderer = nullptr;
Camera Game::camera;
Transform transform;
Player player; 
WanderingObstacle obj;
GameObject box;
GameObject box1;
GameObject box2;
GameObject box3;
GameObject box4;
GameObject box5;
std::vector<GameObject*> objList;
SDL_Texture* backgroundtex;


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

	backgroundtex = TextureManager::LoadTexture("assets/background.jpg",Game::renderer);
	player = Player("assets/Enemy_Wizard.png",transform);
	box = GameObject("assets/wall.png", Transform(0, 300, 1));
	box1 = GameObject("assets/wall.png", Transform(32, 300, 1));
	box2 = GameObject("assets/wall.png", Transform(64, 300, 1));
	box3 = GameObject("assets/wall.png", Transform(96, 300, 1));
	box4 = GameObject("assets/wall.png", Transform(128, 300, 1));
	box5 = GameObject("assets/wall.png", Transform(160, 300, 1));
	objList.push_back(&box);
	objList.push_back(&box1);
	objList.push_back(&box2);
	objList.push_back(&box3);
	objList.push_back(&box4);
	objList.push_back(&box5);
	obj = WanderingObstacle("assets/wall.png", Transform(160, 400, 1), 1);
	objList.push_back(&obj);

	player = Player("assets/PlayerAnims/anim_IdleRight",transform);
	player.LoadAllAnimations();

	player.toggleGravity();
	player.update();
	for (auto& obj : objList) {
		obj->update();
	}
	Game::camera = Camera();
	Game::camera.setTarget(&player.origin);
	Game::camera.update();
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

		if (state[SDL_SCANCODE_D]) {
			player.horizontal = 1;
			player.isRight = true;
		}
		else if (state[SDL_SCANCODE_A]) {
			player.horizontal = -1;
			player.isRight = false;
		}
		else {
			player.horizontal = 0;
		}

		if (state[SDL_SCANCODE_SPACE] && !player.isAttacking) {
			if (player.isRight)
				player.PlayAnimation(player.anim_JumpRight, false);
			else
				player.PlayAnimation(player.anim_JumpLeft, false);
			player.vertical = 10;
			player.gravity = true;
		}
		if (state[SDL_SCANCODE_LSHIFT]) {
			player.horizontal *= 2;
		}

		if (e.type == SDL_MOUSEBUTTONDOWN && !player.isAttacking)
		{
			player.isAttacking = true;
			if (player.isRight)
				player.PlayAnimation(player.anim_AttackRight, false);
			else
				player.PlayAnimation(player.anim_AttackLeft, false);
		}
	}

	//Actual switch statement for managing movement animations, needs to be after event-polling loop
	if (!player.gravity && !player.isAttacking) {
		switch (player.horizontal)
		{
		case 1:
			player.PlayAnimation(player.anim_RightRun, true);
			break;
		case -1:
			player.PlayAnimation(player.anim_LeftRun, true);
			break;
		default:
			if (player.isRight)
				player.PlayAnimation(player.anim_RightIdle, true);
			else
				player.PlayAnimation(player.anim_LeftIdle, true);
			break;
		}
	}
	else if(!player.isAttacking){
		if (player.isRight)
			player.PlayAnimation(player.anim_JumpRight, false);
		else
			player.PlayAnimation(player.anim_JumpLeft, false);
	}

	for (auto& obj : objList) {
		if (obj->handleCollision(&player)) {
		}
	}
}

void Game::update()
{
	player.update();
	for (auto& obj : objList) {
		obj->update();
	}
	obj.update();
	Game::camera.update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	TextureManager::DrawBackground(backgroundtex,Game::renderer);
	player.render();
	for (auto& obj : objList) {
		obj->render();
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
