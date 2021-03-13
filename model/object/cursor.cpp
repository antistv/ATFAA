#include "object-set.hpp"

void Cursor::rectMove(sf::RectangleShape &rect, sf::Text &activeText, string &countingEnter, int &textSize, sf::Font &font){
    rect.setPosition(activeText.getLocalBounds().width , countingEnter.length()*font.getLineSpacing(textSize));
}

void Cursor::arrowMove(sf::RectangleShape &rect, int &counter, string &command, int &textSize, sf::Font &font){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(counter < command.length()) {
            rect.move(font.getLineSpacing(textSize)/2 , 0);
            ++counter;
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(counter >= 1) {
            rect.move(-font.getLineSpacing(textSize)/2 , 0);
            --counter;
        }
    }
}