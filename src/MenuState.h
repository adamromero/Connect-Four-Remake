#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SFML/Graphics/Text.hpp>
#include "State.h"

struct MenuState : public State {
	virtual void run(PointerPack &pack); 
private:
	sf::Text title, play, highScore, quit;
};

#endif