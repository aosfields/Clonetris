#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "board.h"
#include "graphics.h"
#include "piece.h"


class Game
{
public:
	Game();
	~Game();
	static int TILE_SIZE_;

private:
	Board* board;
	Piece* piece;
	bool piece_in_play = false;
	void eventloop();
	void update();
	void draw(Graphics& graphics);
};
#endif