#include "object-set.hpp"

void Camera::moveCamera(sf::View &camera, sf::Text &activeText, int &textSize, sf::Font &font){
    if(activeText.getLocalBounds().height >= camera.getCenter().y + camera.getSize().y/2 -30) {
        camera.move(0.f , font.getLineSpacing(textSize));
    }
}

void Camera::scrollMove(bool &scrollOrNo, sf::Event &event, sf::Text &activeText, int textSize, sf::View &camera, sf::RectangleShape &rect, int &scrollEnter, sf::Font &font){
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
