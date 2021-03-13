#include "commands-Set.hpp"
#include <SFML/Graphics.hpp>

void Colors :: Fcolor(string clr, string clr2, string clr3, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, sf::RectangleShape &rect, string &path) {
    if(clr3!=""){
        if(is_number(clr) && is_number(clr2) && is_number(clr3) && clr.length()<=3 && clr2.length()<=3 && clr3.length()<=3){
            int r, g, b;
            r = stoi(clr); g = stoi(clr2); b = stoi(clr3);
            activeText.setFillColor(sf::Color(r,g,b));
            wrireText.setFillColor(sf::Color(r,g,b));
            rect.setFillColor(sf::Color(r,g,b));
        } else {
            wrireTextS += "This color is not exist\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    } else {
        if(clr == "red") {
            activeText.setFillColor(sf::Color::Red);
            wrireText.setFillColor(sf::Color::Red);
            rect.setFillColor(sf::Color::Red);
        } else if(clr == "green") {
            activeText.setFillColor(sf::Color::Green);
            wrireText.setFillColor(sf::Color::Green);
            rect.setFillColor(sf::Color::Green);
        } else if(clr == "yellow") {
            activeText.setFillColor(sf::Color::Yellow);
            wrireText.setFillColor(sf::Color::Yellow);
            rect.setFillColor(sf::Color::Yellow);
        } else if(clr == "blue") {
            activeText.setFillColor(sf::Color::Blue);
            wrireText.setFillColor(sf::Color::Blue);
            rect.setFillColor(sf::Color::Blue);
        } else if(clr == "magenta" || clr == "violet" || clr == "purple") {
            activeText.setFillColor(sf::Color::Magenta);
            wrireText.setFillColor(sf::Color::Magenta);
            rect.setFillColor(sf::Color::Magenta);
        } else if(clr == "cyan") {
            activeText.setFillColor(sf::Color::Cyan);
            wrireText.setFillColor(sf::Color::Cyan);
            rect.setFillColor(sf::Color::Cyan);
        } else if(clr == "white" || clr == "default" || clr == "standard") {
            activeText.setFillColor(sf::Color::White);
            wrireText.setFillColor(sf::Color::White);
            rect.setFillColor(sf::Color::White);
        } else if(clr == "orange") {
            activeText.setFillColor(sf::Color(254,127,0));
            wrireText.setFillColor(sf::Color(254,127,0));
            rect.setFillColor(sf::Color(254,127,0));
        } else if(clr == "black") {
            activeText.setFillColor(sf::Color::Black);
            wrireText.setFillColor(sf::Color::Black);
            rect.setFillColor(sf::Color::Black);
        } else if(clr == "infusiowy") {
            activeText.setFillColor(sf::Color::Transparent);
            wrireText.setFillColor(sf::Color::Transparent);
            rect.setFillColor(sf::Color::Transparent);
        } else {
            wrireTextS += "Color not found\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    }
}

void Colors :: Bcolor(string clr, string clr2, string clr3, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, string &path, sf::Color &background_color) {
    if(clr3!=""){
        if(is_number(clr) && is_number(clr2) && is_number(clr3) && clr.length()<=3 && clr2.length()<=3 && clr3.length()<=3){
            int r, g, b;
            r = stoi(clr); g = stoi(clr2); b = stoi(clr3);
            background_color = sf::Color(r,g,b);
        } else {
            wrireTextS += "This color is not exist\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    } else {
        if(clr == "red") {
            background_color = sf::Color::Red;
        } else if(clr == "green") {
            background_color = sf::Color::Green;
        } else if(clr == "yellow") {
            background_color = sf::Color::Yellow;
        } else if(clr == "blue") {
            background_color = sf::Color::Blue;
        } else if(clr == "magenta" || clr == "violet" || clr == "purple") {
            background_color = sf::Color::Magenta;
        } else if(clr == "cyan") {
            background_color = sf::Color::Cyan;
        } else if(clr == "white") {
            background_color = sf::Color::White;
        } else if(clr == "orange") {
            background_color = sf::Color(254,127,0);
        } else if(clr == "black" || clr == "default" || clr == "standard") {
            background_color = sf::Color::Black;
        } else if(clr == "infusiowy") {
            background_color = sf::Color::Transparent;
        } else {
            wrireTextS += "Color not found\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    }
}

bool Colors :: is_number(const std::string &s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}