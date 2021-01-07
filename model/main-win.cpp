#include "main-win.hpp"
#include <iostream>

sf::RenderWindow window(sf::VideoMode(1200, 720), "ATFAA TERMINAL", sf::Style::Default);

int main(){
    KeybordFunc useKeyboard;

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    if(!font.loadFromFile("keyboard/fonts/arial.ttf")){
        cout << "error to load font";
    }

    text.setFont(font);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(30);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            
            useKeyboard.keyboard(event, text);

            if (event.type == sf::Event::Closed){
                window.close();
                break;
            }
        }

        window.clear();
        window.draw(text);
        window.display();
    }   
}    
