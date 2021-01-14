main:
	g++ main.cpp main.hpp model/*.cpp model/*.hpp model/keyboard/*.cpp model/keyboard/*.hpp commands/* adminFunc/*.cpp adminFunc/*.hpp model/object/*.cpp model/object/*.hpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system 
