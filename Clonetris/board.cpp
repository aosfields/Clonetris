#include "board.h"
#include <iostream>
#include <string>
#include "game.h"

Board::Board() : boardRect({ 0, 0, Game::TILE_SIZE_, Game::TILE_SIZE_ })
{
	//Create the board for game logic
	board = new int*[BOARD_HEIGHT_];
	for (int i = 0; i < BOARD_HEIGHT_; i++) {
		board[i] = new int[BOARD_WIDTH_];
		for (int j = 0; j < BOARD_WIDTH_; j++) {
			if( j == 0 || j == (BOARD_WIDTH_ - 1) || i > (BOARD_HEIGHT_ - 3))
				board[i][j] = -1;
			else
				board[i][j] = 0;
		}
	}

	//load up the sprite to use for the borders of the board
	boardSprite = SDL_LoadBMP("boardSprite.bmp");
}


Board::~Board()
{

}

//Console view of the board
void Board::printBoard() {
	for (int i = 0; i < BOARD_HEIGHT_; i++) {
		for (int j = 0; j < BOARD_WIDTH_; j++) {
			if (i > (BOARD_HEIGHT_ - 3)) {
				std::cout << std::to_string(board[i][j]);
			}
			else {
				std::cout << std::to_string(board[i][j]) + ' ';
			}
		}
		std::cout << std::endl;
	}
}

void Board::draw(Graphics& graphics) {
	graphics.clearRenderer();

	int tilesize = Game::TILE_SIZE_;
	SDL_Rect dstrect = { 0, 0, tilesize, tilesize };

	for (int y = 0; y < BOARD_HEIGHT_; y++) {
		for (int x = 0; x < BOARD_WIDTH_; x++) {
			if (board[y][x] == -1) {
				// i=0,0 then we want to draw at 0, 0
				// 1,0 then we want to draw at 1*32, 0
				dstrect.x = x * tilesize;
				dstrect.y = y * tilesize;
				graphics.renderOnScreen(boardSprite, &boardRect, &dstrect);
			}
		}
	}
	graphics.presentRenderer();

}
