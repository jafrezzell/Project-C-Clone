#include "Game.h"
#include "GameObject.h";
#include "Actor.h"
#include "Player.h"
#include "WanderingObstacle.h"
#include "TextureManager.h"
#include <vector>
#include "Level.h"
SDL_Renderer* Game::renderer = nullptr;
Camera Game::camera;
Transform transform;
Player player; 
Level level;


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
	player = Player("assets/PlayerAnims/anim_IdleRight",Transform(100,1300));
	player.LoadAllAnimations();
	player.toggleGravity();
	player.speed = 3;

	level = Level(&player);
	level.update();

	player.update();
	
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

		if (state[SDL_SCANCODE_SPACE] && !player.isAttacking && !player.gravity) {
			if (player.isRight)
				player.PlayAnimation(player.anim_JumpRight, false);
			else
				player.PlayAnimation(player.anim_JumpLeft, false);
			player.vertical = 13;
			player.gravity = true;
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
	level.events();

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
}

void Game::update()
{
	player.update();
	level.update();
	Game::camera.update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	level.renderBG();
	level.render();
	player.render();
	
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
