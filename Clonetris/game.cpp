#include "game.h"

int Game::TILE_SIZE_ = 24;

Game::Game()
{
	board = new Board;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_ShowCursor(SDL_DISABLE);
	eventloop();
}

Game::~Game()
{
	//Might want to use a boost scoped ptr for this later
	delete board;
	SDL_Quit();
}

void Game::eventloop()
{
	Graphics graphics;
	SDL_Event event;
	bool running = true;
	int last_update_time = SDL_GetTicks();
	const int FPS = 60;
	
	while (running) {
		/*const int start_time_ms = SDL_GetTicks();*/
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_ESCAPE)
						running = false;
					break;
				default:
					break;
			}
		}

		//if the piece isn't in play create a new one
		if (!piece_in_play) {
			piece = new Piece;
		}
		update();

		//if the piece hit a border, delete it
		if (!piece_in_play) {
			delete piece;
		}

		draw(graphics);
		/*const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;*/
		SDL_Delay(1000 / FPS);
	}
}

void Game::update()
{
	piece_in_play = board->drawPiece(piece);
}

void Game::draw(Graphics& graphics)
{
	/*board->printBoard();*/
	board->draw(graphics);
}
