#pragma once
#include "Game.h"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_Renderer* renderer);
	static void DrawBackground(SDL_Texture* texture, SDL_Renderer* renderer);
private:

};