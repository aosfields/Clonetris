#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "SDL.h"
class Graphics
{
private:
	SDL_Window* window_;
	SDL_Renderer* renderer_;

public:
	Graphics();
	~Graphics();
	void renderOnScreen(SDL_Surface* src, SDL_Rect* src_rect, SDL_Rect* dst_rect);
	void clearRenderer();
	void presentRenderer();
};

#endif