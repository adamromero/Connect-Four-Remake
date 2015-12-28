#include "StateManager.h"
#include "State.h"

StateManager::StateManager() { 
	window.create(sf::VideoMode(517, 536), "Connect-Four", sf::Style::Close | sf::Style::Titlebar);
	font.loadFromFile("../assets/SigmarOne.ttf");
	pack.font = &font;
	pack.window = &window;
	pack.manager = this;
}

StateManager::~StateManager() { 
	popState(removalStates.size());
	clearAllStates();
}

bool StateManager::hasState() const {
	return !additionStates.empty();
}

void StateManager::popState(int amount) {
	amount = std::min(amount, static_cast<int>(additionStates.size()));
  	for (int i = 0; i < amount; i++) {
    	removalStates.push(additionStates.top());
    	additionStates.pop();
  	}
}

void StateManager::pushState(State *state) {
	additionStates.push(state);
}

void StateManager::clearAllStates() {
	while (!removalStates.empty()) {
		delete removalStates.top();
		removalStates.pop();
	}
}

void StateManager::runState() {
	while (!additionStates.empty()) {
		additionStates.top()->run(pack);
		clearAllStates();
	}
}
