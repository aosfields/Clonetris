#include "graphics.h"

namespace {
	const int SCREEN_WIDTH_ = 640;
	const int SCREEN_HEIGHT_ = 480;
	const int FPS_ = 60;
}

Graphics::Graphics()
{
	window_ = SDL_CreateWindow("Clonetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH_, SCREEN_HEIGHT_, SDL_WINDOW_SHOWN);
	renderer_ = SDL_CreateRenderer(window_, -1, 0);
}


Graphics::~Graphics()
{
	SDL_DestroyWindow(window_);
}

void Graphics::renderOnScreen(SDL_Surface * src, SDL_Rect * src_rect, SDL_Rect * dst_rect)
{
	SDL_Texture* texture;
	texture = SDL_CreateTextureFromSurface(renderer_, src);
	SDL_RenderCopy(renderer_, texture, src_rect, dst_rect);
	SDL_DestroyTexture(texture);
}

void Graphics::clearRenderer() {
	SDL_RenderClear(renderer_);
}

void Graphics::presentRenderer() {
	SDL_RenderPresent(renderer_);
}