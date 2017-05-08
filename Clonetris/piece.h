#ifndef PIECE_H
#define PIECE_H
#include "board.h"
#define PIECE_ARRAY_SIZE 4
class Piece
{
public:
	int x, y;
	int pieceIndex;
	enum Clonetrominos { BLOCK, LENGTH };
	int currPiece[4][4];
	Piece();
	void printPiece();
	~Piece();

private:
	const int starting_pieces[1][4][4] = { {
			//Block Piece
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	} };
};

#endif