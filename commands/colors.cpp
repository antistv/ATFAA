#include "commands-Set.hpp"
#include <SFML/Graphics.hpp>

extern sf::Text activeText;
extern sf::Text wrireText;
extern string countingEnter;
extern string activeTextS;
extern string wrireTextS;
extern sf::RectangleShape rect;

extern string path;

void Colors :: color(string clr) {
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
    } else if(clr == "magenta") {
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
    } else {
        wrireTextS += "Color not found\n";
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    }
}