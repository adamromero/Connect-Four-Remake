#include "StateManager.h"
#include "MenuState.h"

int main(int argc, char *argv[]) {
	StateManager manager;
	manager.pushState(new MenuState());
	manager.runState();
	return 0;
}
