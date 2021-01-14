#include "object-set.hpp"

extern sf::RectangleShape rect;
extern sf::String activeTextS;
extern sf::String wrireTextS;
extern sf::Text activeText;
extern sf::Text wrireText;
extern string countingEnter;
extern int textSize;
extern sf::Font font;
extern int counter;
extern string command;

void Cursor::rectMove(){
    rect.setPosition(activeText.getLocalBounds().width , countingEnter.length()*font.getLineSpacing(textSize));
}

void Cursor::arrowMove(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(counter < command.length()) {
            rect.move(font.getLineSpacing(textSize)/2 , 0);
            ++counter;
            //cout << counter << " right\n";
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(counter >= 1) {
            rect.move(-font.getLineSpacing(textSize)/2 , 0);
            --counter;
            //cout << counter << " left\n";
        }
    }
}