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
	
	while (running) {
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

		update();
		draw(graphics);
	}
}

void Game::update()
{
}

void Game::draw(Graphics& graphics)
{
	/*board->printBoard();*/
	board->draw(graphics);
}
