#include <iostream>
#include <string.h>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//#include "../commands/commands-Set.hpp"


using namespace std;

class KeybordFunc{
    public:
        void keyboard();
        void checkEdge();
};