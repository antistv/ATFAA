#include "main-win.hpp"

string activeTextS;
string wrireTextS;
sf::Text activeText;
sf::Text wrireText;
sf::Font font;
sf::Event event;
string command = "";
string countingEnter = "";

sf::RenderWindow window(sf::VideoMode(1200, 720), "ATFAA TERMINAL", sf::Style::Default);

void MainWindow::mainWindow(){

    KeybordFunc useKeyboard;

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(15);

    if(!font.loadFromFile("model/keyboard/fonts/arial.ttf")){
        cout << "error to load font";
    }

    activeText.setFont(font);
    activeText.setStyle(sf::Text::Italic);
    activeText.setFillColor(sf::Color::Red);
    activeText.setCharacterSize(30);

    wrireText.setFont(font);
    wrireText.setStyle(sf::Text::Italic);
    wrireText.setFillColor(sf::Color::Red);
    wrireText.setCharacterSize(30);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::MouseWheelScrolled) {
                if(event.mouseWheelScroll.delta > 0) {
                    cout<<"scroll w gore"<<endl;
                } else if(event.mouseWheelScroll.delta < 0) {
                    cout<<"scroll w dol"<<endl;
                }
            }

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
        window.display();
    }   
}    
