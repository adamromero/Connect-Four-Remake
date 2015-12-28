CC = g++

SOURCES = main.cc StateManager.cpp MenuState.cpp GameState.cpp

EXE = -o state

COMPILER_FLAGS = -std=c++11

LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

DEBUG_FLAG = -g

DEBUG_EXE = -o debug

all:
	$(CC) $(SOURCES) $(EXE) $(COMPILER_FLAGS) $(LINKER_FLAGS)

debug:
	$(CC) $(DEBUG_FLAG) $(SOURCES) $(DEBUG_EXE) $(COMPILER_FLAGS) $(LINKER_FLAGS)

clean:
	rm -rf *.o state
