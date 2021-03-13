#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>

using namespace  std;

class Cursor {
    public:
        void rectMove(sf::RectangleShape &rect, sf::Text &activeText, string &countingEnter, int &textSize, sf::Font &font);
        void arrowMove(sf::RectangleShape &rect, int &counter, string &command, int &textSize, sf::Font &font);
};

class Camera {
    public:
        void scrollMove(bool &scrollOrNo, sf::Event &event, sf::Text &activeText, int textSize, sf::View &camera, sf::RectangleShape &rect, int &scrollEnter, sf::Font &font);
        void moveCamera(sf::View &camera, sf::Text &activeText, int &textSize, sf::Font &font);
};

