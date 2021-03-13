#include "useKeyboard.hpp"

void KeybordFunc::keyboard(sf::String &activeTextS, sf::String &wrireTextS, sf::Text &activeText, sf::Text &wrireText, sf::Event &event, string &command, string &countingEnter, sf::RenderWindow &window, int &textSize, sf::Font &font, bool &scrollOrNo, sf::View &camera, string &path, int &counter, sf::RectangleShape &rect, int &scrollEnter, string &cmd, string &version, sf::Color &background_color) { 
    if(event.text.unicode == 8){
        if(command.length() > 0){
            if(counter > 0){
                activeTextS.erase(counter+path.length(), 1);
                command.erase(counter-1, 1);
                --counter;
                rect.move(-font.getLineSpacing(textSize)/2 , 0);
                activeText.setString(countingEnter+activeTextS);
                scrollEnter = countingEnter.length();
            }
        }
    } else if(event.text.unicode == 13){
        counter = 0;
        wrireTextS += activeTextS;
        wrireText.setString(wrireTextS);
        wrireTextS += '\n';
        countingEnter += '\n';
        //Wysłanie komendy
        if(!operation.runCommand(cmd, activeText, wrireText, countingEnter, activeTextS, wrireTextS, rect, version, path, background_color)){
            if(!systemCommands.checkAndExecuteCmd(command, path, activeText, wrireText, countingEnter, activeTextS, wrireTextS)){
                wrireTextS += FunctionUtf.fromUtf8("Command not found\n");
                wrireText.setString(wrireTextS);
                countingEnter += "\n";
                activeTextS= FunctionUtf.fromUtf8(path+">");
                activeText.setString(countingEnter+activeTextS);
            }
        }
        //
        if(command != "") cmdSaver.push_back(command);
        cmdPointer = cmdSaver.size();
        activeTextS= FunctionUtf.fromUtf8(path+'>');
        command = "";
        activeText.setString(countingEnter+activeTextS);
        scrollEnter = countingEnter.length();
        cursor.rectMove(rect, activeText, countingEnter, textSize, font);
    } else {
        activeTextS.insert(counter+path.length()+1, FunctionUtf.fromUtf8(letterMap[event.text.unicode]));
        command.insert(counter, FunctionUtf.fromUtf8(letterMap[event.text.unicode]));
        saveBackCommand = command;
        ++counter;
        activeText.setString(countingEnter+activeTextS);
        scrollEnter = countingEnter.length();
        rect.move(+font.getLineSpacing(textSize)/2 , 0);
        cursor.rectMove(rect, activeText, countingEnter, textSize, font);
    }
    
    scrollOrNo = true;
    if(activeText.getLocalBounds().height < camera.getCenter().y-window.getSize().y/2 || activeText.getLocalBounds().height > camera.getCenter().y+window.getSize().y/2) {
        camera.setCenter(window.getSize().x/2 , countingEnter.length()*font.getLineSpacing(textSize)-window.getSize().y / 2);
    }
}

void KeybordFunc::checkEdge(sf::String &activeTextS, sf::String &wrireTextS, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::RenderWindow &window){
    if (activeText.getLocalBounds().width >= window.getSize().x-20 ) { 
        wrireTextS += FunctionUtf.fromUtf8(activeTextS+'\n');
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = "";
        activeText.setString(countingEnter+activeTextS);
    }
}

void KeybordFunc::rememberCmd(sf::String &activeTextS, sf::Text &activeText, string &countingEnter, string &command, string &path,  sf::RectangleShape &rect, int &textSize,  sf::Font &font){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(cmdPointer > 0 && cmdSaver.size() > 0){
            --cmdPointer;
            activeTextS =  FunctionUtf.fromUtf8(path+'>'+cmdSaver[cmdPointer]);
            activeText.setString(countingEnter+activeTextS);
            command = cmdSaver[cmdPointer];
            cursor.rectMove(rect, activeText, countingEnter, textSize, font);
        } else {
            cmdPointer = cmdSaver.size();
            activeTextS =  FunctionUtf.fromUtf8(path+'>'+saveBackCommand);
            activeText.setString(countingEnter+activeTextS);
            command = saveBackCommand;
            cursor.rectMove(rect, activeText, countingEnter, textSize, font);    
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if(cmdPointer < cmdSaver.size()-1 && cmdSaver.size()>0) {
            ++cmdPointer;
            activeTextS =  FunctionUtf.fromUtf8(path+'>'+cmdSaver[cmdPointer]);
            activeText.setString(countingEnter+activeTextS);
            command = cmdSaver[cmdPointer];
            cursor.rectMove(rect, activeText, countingEnter, textSize, font);;
        } else {
            cmdPointer = cmdSaver.size();
            activeTextS =  FunctionUtf.fromUtf8(path+'>'+saveBackCommand);
            activeText.setString(countingEnter+activeTextS);
            command = saveBackCommand;
            cursor.rectMove(rect, activeText, countingEnter, textSize, font);  
        }
    }
}