#include <iostream>
#include <string.h>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../main-win.hpp"

using namespace std;

class KeybordFunc{
    public:
        void keyboard(sf::Event event, sf::Text text);
};