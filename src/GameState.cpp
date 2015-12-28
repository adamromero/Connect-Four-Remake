#include <SFML/Window/Event.hpp>

#include "GameState.h"
#include "StateManager.h"

#define ROWS 6
#define COLS 7

GameState::GameState() {
	textureBoard.loadFromFile("../assets/board.png");
	board.setTexture(textureBoard);
	textureRed.loadFromFile("../assets/red.gif");
	textureBlack.loadFromFile("../assets/black.gif");
	blackPiece.setTexture(textureBlack);
	redPiece.setTexture(textureRed);

	sprites[0] = board;
	sprites[1] = blackPiece;
	sprites[2] = redPiece;
}

void GameState::run(PointerPack &pack) {
	sf::Event event;
	while (true) {
		while (pack.window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				pack.manager->popState(100);
				return;
			} else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					//pack.manager->pushState(new QuitState());
					pack.manager->popState(100);
					return;
				}
			}
		}
		
		pack.window->clear(sf::Color::White);
		for (sf::Sprite sprite : sprites) {
			pack.window->draw(sprite);
		}
		pack.window->display();
	}
}
