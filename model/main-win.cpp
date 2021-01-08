#include "main-win.hpp"

string activeText;
string wrireText;
sf::Text text;
sf::Font font;
sf::Event event;

void MainWindow::mainWindow(){
    sf::RenderWindow window(sf::VideoMode(1200, 720), "ATFAA TERMINAL", sf::Style::Default);

    KeybordFunc useKeyboard;

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(24);

    if(!font.loadFromFile("/keyboard/fonts/arial.ttf")){
        cout << "error to load font";
    }

    text.setFont(font);
    text.setStyle(sf::Text::Italic);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(30);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            
            useKeyboard.keyboard();

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
