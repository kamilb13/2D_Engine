//
// Created by kayman on 06.11.23.
//

#include "RectangleEventListener.h"


#include "RectangleEventListener.h"


RectangleEventListener::RectangleEventListener(Rectangle *rectangle, sf::RenderWindow *window, std::vector<Rectangle> *rectangles){
    this->rectangle = rectangle;
    this->window = window;
    this->rectangles = rectangles;
}

void RectangleEventListener::eventHandler(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right) {
            rectangle->startDrawing(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
        }
    } else if (event.type == sf::Event::MouseMoved) {
        rectangle->updateRectangle(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    } else if (event.type == sf::Event::MouseButtonReleased){
        if(event.mouseButton.button == sf::Mouse::Right){
            rectangle->endDrawing();
            rectangles->push_back(*rectangle);
        }
    }
}