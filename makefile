main:
	g++ main.cpp main.hpp model/*.cpp model/*.hpp model/keyboard/*.cpp model/keyboard/*.hpp commands/* -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system 