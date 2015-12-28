#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <stack>

struct StateManager;
struct State;

struct PointerPack {
	sf::RenderWindow *window;
	sf::Font *font;
	StateManager *manager;
};

struct StateManager {
   StateManager();
   ~StateManager();

   void pushState(State *state);
   void popState(int amount);
   bool hasState() const;
   void runState();

private:
   void clearAllStates();
   std::stack<State*> additionStates, removalStates;
   sf::RenderWindow window;
   sf::Font font;
   PointerPack pack;
};

#endif
