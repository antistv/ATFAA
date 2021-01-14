#include "object-set.hpp"

extern sf::String activeTextS;
extern sf::String wrireTextS;
extern sf::Text activeText;
extern sf::Text wrireText;
extern sf::Event event;
extern string countingEnter;
extern int textSize;
extern sf::Font font;
extern bool scrollOrNo;
extern int scrollEnter;
extern sf::RectangleShape rect;
extern sf::View camera;

void Camera::moveCamera(){
    if(activeText.getLocalBounds().height >= camera.getCenter().y + camera.getSize().y/2 -30) {
        camera.move(0.f , font.getLineSpacing(textSize));
    }
}

void Camera::scrollMove(){
    scrollOrNo = false;
    if (event.type == sf::Event::MouseWheelScrolled) {
        if(event.mouseWheelScroll.delta > 0) {
            --scrollEnter;
            rect.setPosition(activeText.getLocalBounds().width , scrollEnter*font.getLineSpacing(textSize));
            camera.move(0.f , -font.getLineSpacing(textSize));
    } else if(event.mouseWheelScroll.delta < 0) {
            ++scrollEnter;
            rect.setPosition(activeText.getLocalBounds().width , scrollEnter*font.getLineSpacing(textSize));
            camera.move(0.f , font.getLineSpacing(textSize));
        }
    }
}
