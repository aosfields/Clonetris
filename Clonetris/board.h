#ifndef BOARD_H
#define BOARD_H
#include "SDL.h"
#include "graphics.h"
//#include "game.h"
#define BOARD_WIDTH_ 12
#define BOARD_HEIGHT_ 21


class Piece;
class Board
{
public:
	Board();
	~Board();
	void printBoard();
	void draw(Graphics& graphics);
	bool drawPiece(Piece* p);

private:
	int **board;
	SDL_Surface * boardSprite;
	
	//Rectanlge used to find where in the surface to grab from
	//when making a texture. For the board sprite it will always be
	//x = 0, y = 0, w, h = 32 (going to use a 32 x 32 pixel)
	SDL_Rect boardRect;
};
#endif