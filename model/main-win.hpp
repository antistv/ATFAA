#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "keyboard/useKeyboard.hpp"
#include "../adminFunc/adminDef.hpp"
#include "object/object-set.hpp"

using namespace std;

class MainWindow{
    public:
        void mainWindow(string &path, string &version);
    
    protected:
        string command {""};
        string countingEnter {""};
        int textSize  {20};
        bool scrollOrNo {true};
        sf::Color background_color {sf::Color::Black};
        sf::String activeTextS;
        sf::String wrireTextS;
        sf::Text activeText;
        sf::Text wrireText;
        sf::Font font;
        sf::Event event;
        sf::RectangleShape rect;
        sf::View camera;
        int counter {0};
        int scrollEnter {0};

        KeybordFunc useKeyboard;
        MainFunc utfFunction;
        Cursor cursor;
        Camera cameraObj;
};