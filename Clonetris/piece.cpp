#include "piece.h"
#include <random>
#include <iostream>


Piece::Piece() : x { BOARD_WIDTH_ / 2}, y{0}
{
	pieceIndex = Clonetrominos(rand() % LENGTH);

	for (int i = 0; i < PIECE_ARRAY_SIZE; i++) {
		for (int j = 0; j < PIECE_ARRAY_SIZE; j++) {
			currPiece[i][j] = starting_pieces[pieceIndex][i][j];
		}
	}
}

void Piece::printPiece() {
	for (int i = 0; i < PIECE_ARRAY_SIZE; i++) {
		for (int j = 0; j < PIECE_ARRAY_SIZE; j++) {
			std::cout << currPiece[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << x << " " << y << std::endl;
}

Piece::~Piece()
{
}
