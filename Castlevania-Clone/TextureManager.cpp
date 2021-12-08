#include "TextureManager.h"
#include "Utils.h"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* renderer)
{
	SDL_Surface* temp = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);
	return tex;
}



void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_Renderer* renderer)
{
	SDL_Rect shiftDest = { dest.x - Game::camera.position.x, dest.y - Game::camera.position.y, dest.w, dest.h };
	/*std::cout << Game::camera.position.x << std::endl;
	std::cout << Game::camera.position.y << std::endl;*/
	SDL_RenderCopy(renderer, texture, &src, &shiftDest);
}

void TextureManager::DrawBackground(SDL_Texture* texture, SDL_Renderer* renderer) {
	//SDL_Rect shiftDest = { 0 - Game::camera.position.x, 0 - Game::camera.position.y, NULL, NULL };
	SDL_Rect source = { 0,0,Utilities::getwidth(),Utilities::getwidth()};
	SDL_Rect shiftDest = { 0 - (Game::camera.position.x/2), 0 - (Game::camera.position.y/2), source.w, source.h };
	SDL_RenderCopy(renderer, texture, &source, &shiftDest);
}
