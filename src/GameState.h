#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "State.h"

struct GameState : public State {
	GameState();
	virtual void run(PointerPack &pack); 
private:
	sf::Texture textureBoard, textureBlack, textureRed;
	sf::Sprite board, blackPiece, redPiece, sprites[3];
};

#endif