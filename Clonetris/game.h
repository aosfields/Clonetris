#pragma once
#include "SDL.h"
#include "graphics.h"
#include "board.h"
class Game
{
public:
	Game();
	~Game();
	static int TILE_SIZE_;

private:

	Board* board;
	void eventloop();
	void update();
	void draw(Graphics& graphics);
};

