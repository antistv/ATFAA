#include "main-win.hpp"

sf::RenderWindow window(sf::VideoMode(1200, 720), "ATFAA TERMINAL", sf::Style::Default);

string activeTextS;
string wrireTextS;
sf::Text activeText;
sf::Text wrireText;
sf::Font font;
sf::Event event;
string command = "";
string countingEnter = "";
int textSize=30;
sf::RectangleShape rect(sf::Vector2f(textSize/2, textSize));
sf::View camera = window.getDefaultView();

bool scrollOrNo=true;

extern string path;

void MainWindow::mainWindow(){

    KeybordFunc useKeyboard;

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    if(!font.loadFromFile("fonts/arial.ttf")){
        cout << "error to load font";
    }

//SET TEXT
    activeText.setFont(font);
    activeText.setStyle(sf::Text::Italic);
    activeText.setFillColor(sf::Color::Red);
    activeText.setCharacterSize(textSize);
    activeTextS=path+"> ";
    activeText.setString(activeTextS);

    wrireText.setFont(font);
    wrireText.setStyle(sf::Text::Italic);
    wrireText.setFillColor(sf::Color::Red);
    wrireText.setCharacterSize(textSize);

    rect.setFillColor(sf::Color::Red);
    useKeyboard.rectMove();
//
    camera.setCenter(sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
    window.setView(camera);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            
            if(scrollOrNo) useKeyboard.moveCamera();
            useKeyboard.scrollMove();
            useKeyboard.keyboard();
            useKeyboard.checkEdge();

            if (event.type == sf::Event::Closed){
                window.close();
                break;
            }

        }

        window.clear();
        window.draw(wrireText);
        window.draw(activeText);
        window.draw(rect);
        window.setView(camera);
        window.display();
    }   
}    
