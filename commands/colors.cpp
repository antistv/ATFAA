#include "commands-Set.hpp"
#include <SFML/Graphics.hpp>

extern sf::Text activeText;
extern sf::Text wrireText;
extern string countingEnter;
extern string activeTextS;
extern string wrireTextS;
extern sf::RectangleShape rect;
extern sf::RenderWindow window;
extern string path;
extern sf::Color BgC;

void Colors :: Fcolor(string clr, string clr2, string clr3) {
    if(clr3!=""){
        int r, g, b;
        r = stoi(clr); g = stoi(clr2); b = stoi(clr3);
        activeText.setFillColor(sf::Color(r,g,b));
        wrireText.setFillColor(sf::Color(r,g,b));
        rect.setFillColor(sf::Color(r,g,b));
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

void Colors :: Bcolor(string clr, string clr2, string clr3) {
    if(clr3!=""){
        int r, g, b;
        r = stoi(clr); g = stoi(clr2); b = stoi(clr3);
        BgC = sf::Color(r,g,b);
    } else {
        if(clr == "red") {
            BgC = sf::Color::Red;
        } else if(clr == "green") {
            BgC = sf::Color::Green;
        } else if(clr == "yellow") {
            BgC = sf::Color::Yellow;
        } else if(clr == "blue") {
            BgC = sf::Color::Blue;
        } else if(clr == "magenta" || clr == "violet" || clr == "purple") {
            BgC = sf::Color::Magenta;
        } else if(clr == "cyan") {
            BgC = sf::Color::Cyan;
        } else if(clr == "white") {
            BgC = sf::Color::White;
        } else if(clr == "orange") {
            BgC = sf::Color(254,127,0);
        } else if(clr == "black" || clr == "default" || clr == "standard") {
            BgC = sf::Color::Black;
        } else if(clr == "infusiowy") {
            BgC = sf::Color::Transparent;
        } else {
            wrireTextS += "Color not found\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    }
}