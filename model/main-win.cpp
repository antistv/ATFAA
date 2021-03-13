#include "main-win.hpp"

void MainWindow::mainWindow(string &path, string &version){
    sf::RenderWindow window(sf::VideoMode(1200, 720), "ATFAA TERMINAL", sf::Style::Default);

    camera = window.getDefaultView();
    rect.setSize(sf::Vector2f(textSize/2, textSize));

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    if(!font.loadFromFile("fonts/Consolas.ttf")){
        cout << "error to load font";
        return;
    }

//SET OBJECT
    activeText.setFont(font);
    activeText.setStyle(sf::Text::Italic);
    activeText.setFillColor(sf::Color::Red);
    activeText.setCharacterSize(textSize);
    countingEnter += "\n\n\n";
    activeTextS=utfFunction.fromUtf8(path+'>');
    activeText.setString(countingEnter + activeTextS);
    
    wrireText.setFont(font);
    wrireText.setStyle(sf::Text::Italic);
    wrireText.setFillColor(sf::Color::Red);
    wrireText.setCharacterSize(textSize);
    wrireTextS=utfFunction.fromUtf8("ATFAA Terminal " + version + '\n' + "Copyright (c) ATFAA Corporation. All rights reserved" + '\n' + "Type 'help' to get help." + '\n');
    wrireText.setString(wrireTextS);
    rect.setFillColor(sf::Color::Red);
    cursor.rectMove(rect, activeText, countingEnter, textSize, font);
//
    camera.setCenter(sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
    window.setView(camera);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::TextEntered) {
                useKeyboard.keyboard(activeTextS, wrireTextS, activeText, wrireText, event, command, countingEnter, window, textSize, font, scrollOrNo, camera, path, counter, rect, scrollEnter, command, version, background_color);
                useKeyboard.checkEdge(activeTextS, wrireTextS, activeText, wrireText, countingEnter, window);
            }
            if(scrollOrNo) cameraObj.moveCamera(camera, activeText, textSize, font);

            cameraObj.scrollMove(scrollOrNo, event, activeText, textSize, camera, rect, scrollEnter, font);
            useKeyboard.rememberCmd(activeTextS, activeText, countingEnter, command, path,  rect, textSize, font);
            cursor.arrowMove(rect, counter, command, textSize, font);

            //Zamkniecie okna
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
