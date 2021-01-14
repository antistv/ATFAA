#include "main-win.hpp"
#include "../adminFunc/adminDef.hpp"
#include "object/object-set.hpp"

sf::RenderWindow window(sf::VideoMode(1200, 720), "ATFAA TERMINAL", sf::Style::Default);

string command = "";
string countingEnter = "";
int textSize = 20;
bool scrollOrNo=true;
sf::Color background_color = sf::Color::Black;
sf::String activeTextS;
sf::String wrireTextS;
sf::Text activeText;
sf::Text wrireText;
sf::Font font;
sf::Event event;
sf::RectangleShape rect;
sf::View camera;
int counter=0;

extern string path;
extern string version;

void MainWindow::mainWindow(){
    camera = window.getDefaultView();
    rect.setSize(sf::Vector2f(textSize/2, textSize));

    KeybordFunc useKeyboard;
    MainFunc utfFunction;
    Cursor cursor;
    Camera cameraObj;

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    if(!font.loadFromFile("fonts/DejaVuSans-Bold.ttf")){
        cout << "error to load font";
    }

//SET OBJECT
    activeText.setFont(font);
    activeText.setStyle(sf::Text::Italic);
    activeText.setFillColor(sf::Color::Red);
    activeText.setCharacterSize(textSize);
    countingEnter += "\n\n\n";
    activeTextS=utfFunction.fromUtf8(path+">");
    activeText.setString(countingEnter + activeTextS);
    
    wrireText.setFont(font);
    wrireText.setStyle(sf::Text::Italic);
    wrireText.setFillColor(sf::Color::Red);
    wrireText.setCharacterSize(textSize);
    wrireTextS=utfFunction.fromUtf8("ATFAA Terminal " + version + '\n' + "Copyright (c) ATFAA Corporation. All rights reserved" + '\n' + "Type 'help' to get help." + '\n');
    wrireText.setString(wrireTextS);
    rect.setFillColor(sf::Color::Red);
    cursor.rectMove();
//
    camera.setCenter(sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
    window.setView(camera);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::TextEntered) {
                useKeyboard.keyboard();
                useKeyboard.checkEdge();
            }
            if(scrollOrNo) cameraObj.moveCamera();
            cameraObj.scrollMove();
            useKeyboard.rememberCmd();
            cursor.arrowMove();

            //Zamknięcie okna
            if (event.type == sf::Event::Closed){
                window.close();
                break;
            }

        }
        window.clear(background_color);
        window.draw(wrireText);
        window.draw(activeText);
        window.draw(rect);
        window.setView(camera);
        window.display();
    }   
}    
