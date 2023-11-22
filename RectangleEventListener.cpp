//
// Created by kayman on 06.11.23.
//

#include "RectangleEventListener.h"


RectangleEventListener::RectangleEventListener(Rectangle *rectangle){
    this->rectangle = rectangle;
}

void RectangleEventListener::eventHandler(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed){
        if(event.key.code == sf::Mouse::Right){
            rectangle->startDrawing(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            std::cout << "right click" << std::endl;
        }
    } else if (event.type == sf::Event::MouseButtonReleased){
        if(event.key.code == sf::Mouse::Right){
            rectangle->endDrawing();
            std::cout << "right released" << std::endl;
        }
    }
}
