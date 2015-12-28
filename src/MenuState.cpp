#include <SFML/Window/Event.hpp>

#include "MenuState.h"
#include "GameState.h"
#include "StateManager.h"

void MenuState::run(PointerPack &pack) {
	title.setFont(*pack.font);
	play.setFont(*pack.font);
	highScore.setFont(*pack.font);
	quit.setFont(*pack.font);

	title.setString("Connect Four");
	play.setString("[P]lay!");
	highScore.setString("[H]igh Scores!");
	quit.setString("[Q]uit!");

	title.setPosition(150.f,75.f);
	play.setPosition(150.f,200.f);
	highScore.setPosition(150.f,235.f);
	quit.setPosition(150.f,270.f);
	sf::Event event;
	while(true) {
		while (pack.window->pollEvent(event)) {
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)) {
				pack.manager->popState(100);
				return;
			} else if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::P) {
					pack.manager->pushState(new GameState());
					return;
				}
				if(event.key.code == sf::Keyboard::H) {
					//pack.manager->pushState(new ScoreState(-1));
					return;
				}
			}
		}
		pack.window->clear();
		pack.window->draw(title);
		pack.window->draw(play);
		pack.window->draw(highScore);
		pack.window->draw(quit);
		pack.window->display();
	}
}
