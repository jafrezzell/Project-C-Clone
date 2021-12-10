#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "WorldSpaceConstructs.h"
#include "Camera.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void events();
	void update();
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static Camera camera;
	static int curlvl;
	static const int tileSize = 64;

	bool running();

private:
	int count = 0;
	bool isRunning;
	SDL_Window* window;
};