#include "Game.h"
#include "GameObject.h";
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "WanderingObstacle.h"
#include "TextureManager.h"
#include <vector>
#include "Level.h"
SDL_Renderer* Game::renderer = nullptr;
int Game::curlvl = NULL;
Camera Game::camera;
Transform transform;
Player player; 
Level level1;
Level level2;
Level curLevel;

//Levels
int Level1[22][25] = {
1,1,1,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
3,5,5,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
3,5,5,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,0,0,3,3,3,0,1,
3,5,5,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,0,3,3,3,3,3,1,
3,5,5,5,5,5,5,5,5,3,0,0,0,0,9,0,0,0,3,3,3,3,3,3,3,
3,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,3,5,5,5,5,5,3,
3,5,5,4,4,4,4,4,4,3,7,7,7,6,6,0,0,0,3,3,5,5,5,3,3,
3,5,5,5,5,5,5,5,5,3,3,3,0,0,0,0,0,0,0,3,5,5,5,3,1,
3,4,5,5,5,5,5,5,5,3,3,0,0,0,0,0,0,0,0,3,5,5,4,3,1,
3,5,5,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,0,3,5,5,5,3,1,
3,5,4,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,0,5,4,5,5,3,1,
3,5,5,5,4,5,5,5,5,3,0,0,0,0,0,0,0,0,0,5,5,5,5,3,1,
3,5,5,5,5,5,4,5,5,3,0,0,0,0,0,0,0,0,0,3,5,5,4,3,1,
3,5,5,5,9,5,5,5,4,3,0,3,3,3,3,3,0,0,0,3,5,5,5,3,1,
3,5,5,5,5,5,5,5,5,3,0,3,5,5,5,3,0,3,3,3,4,5,5,3,1,
3,5,5,5,5,5,5,3,3,3,3,3,5,5,5,3,3,3,5,5,5,5,5,3,3,
3,5,5,5,5,3,3,3,3,3,5,5,5,5,5,5,5,5,5,5,5,5,4,5,3,
3,5,5,3,3,3,3,3,3,3,5,5,5,8,5,5,5,5,5,5,5,5,5,5,3,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
};
int Level2[22][25] = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,5,5,5,3,3,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,5,5,5,5,5,3,3,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,5,5,5,5,5,3,3,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,5,5,5,5,5,3,0,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,5,5,5,5,5,5,0,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,5,5,4,4,4,3,6,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,5,5,5,5,5,3,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,4,5,5,5,5,3,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,5,5,5,5,5,3,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,4,5,5,3,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,5,5,5,5,5,5,3,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,3,5,5,5,5,4,3,1,
0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,3,5,5,5,5,5,3,1,
0,0,0,0,0,0,0,3,3,5,5,3,3,0,0,0,0,3,5,5,4,5,5,3,1,
0,0,0,0,0,0,3,3,5,5,5,5,3,3,0,0,0,3,5,5,5,5,5,3,1,
0,0,0,0,0,0,5,5,5,5,5,5,5,3,3,0,0,3,4,5,5,5,5,3,1,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
};


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

	//player = Player("assets/PlayerAnims/anim_IdleRight",Transform(100,1300));
	//player.LoadAllAnimations();
	player = Player("assets/PlayerAnims/anim_IdleRight/frame_0.png", Transform(100,1300));
	player.LoadAllAnimations();
	player.toggleGravity();
	player.speed = 3;

	level1 = Level(&player, Level1);
	level2 = Level(&player, Level2);
	level2.showThird = true;
	level1.update();
	curLevel = level1;
	Game::curlvl = 1;

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
		const Uint8* state = SDL_GetKeyboardState(NULL);
		//User requests quit
		if (e.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE])
		{
			isRunning = false;
			return;
		}

		if (player.isDead || player.health <= 0) {
			player.horizontal = 0;
			if(player.isRight)
				player.PlayAnimation(player.anim_DeathRight, false);
			else
				player.PlayAnimation(player.anim_DeathLeft, false);
			if ((int)player.currentAnimFrame >= player.currentAnimationPlaying.animationLength - 1) {
				isRunning = false;
			}
			break;
		}

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
	if (curlvl == 2)
		curLevel = level2;
	curLevel.events();

	//Actual switch statement for managing movement animations, needs to be after event-polling loop
	if (!player.gravity && !player.isAttacking && !player.isDead) {
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
	else if(!player.isAttacking && !player.isDead){
		if (player.isRight)
			player.PlayAnimation(player.anim_JumpRight, false);
		else
			player.PlayAnimation(player.anim_JumpLeft, false);
	}
}

void Game::update()
{
	player.update();
	curLevel.update();
	Game::camera.update();
	/*GameObject playerCurrentHitBox;
	if (player.LeftHitBox.isActive || player.RightHitBox.isActive)
	{
		if (player.LeftHitBox.isActive)
			playerCurrentHitBox = player.LeftHitBox;
		else
			playerCurrentHitBox = player.RightHitBox;
		for (auto& obj : objList) {
			if (obj->isActive && dynamic_cast<Enemy*>(obj))
			{
				if(playerCurrentHitBox.handleCollision(obj))
					dynamic_cast<Enemy*>(obj)->isDead = true;
			}
		}
	}

	//wizard1.update();
	for (auto& obj : objList) {
		obj->update();
	}
	obj.update();*/
	
}

void Game::render()
{
	SDL_RenderClear(renderer);
	curLevel.renderBG();
	curLevel.render();
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
