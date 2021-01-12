main:
	ifeq ($(OS), Windows_NT)
		g++ main.cpp main.hpp commands/*.cpp commands/*.hpp model/*.cpp model/*.hpp model/keyboard/*.cpp model/keyboard/*.hpp adminFunc/*.cpp adminFunc/*.hpp -o sfml-app.exe -lsfml-graphics -lsfml-window -lsfml-system
	else
		g++ main.cpp main.hpp model/*.cpp model/*.hpp model/keyboard/*.cpp model/keyboard/*.hpp commands/* adminFunc/*.cpp adminFunc/*.hpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system 
	endif