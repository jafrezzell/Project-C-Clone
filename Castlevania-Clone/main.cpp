#include "Game.h"
#include "Utils.h"
#include <iostream>

int main(int argc, char* argv[]) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//Should alert to memory leaks in debug console.
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Game game;
	game.init("Castlevania-Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Utilities::getscreenwidth(), Utilities::getscreenheight(), false);
	/*Utilities::RandomGenerator gen = Utilities::RandomGenerator();
	for (int i = 0; i < 5; i++) {
		std::cout << gen.generateint(100) << std::endl;
	}*/
	while (game.running()) {
		frameStart = SDL_GetTicks();
		game.events();
		game.update();
		game.render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game.clean();

	return 0;
}