//
// Created by kayman on 21.11.23.
//

#include "CircleEventListener.h"

CircleEventListener::CircleEventListener(Circle *circle, sf::RenderWindow *window) {
    this->circle = circle;
    this->window = window;
}

void CircleEventListener::eventHandler(sf::Event event) {
    float distance;
    sf::Vector2i center; // Srodek koła
    if (event.type == sf::Event::MouseButtonPressed){
        if(event.key.code == sf::Mouse::Left){
            drawing = true;
            std::cout << "left click" << std::endl;
            circle->startDrawing(event.mouseButton.x, event.mouseButton.y);
            center = sf::Mouse::getPosition(*this->window);
        }
    }

    if(drawing) {
        distance = std::sqrt(std::pow(event.mouseButton.x - center.x, 2) +
                             std::pow(event.mouseButton.y - center.y, 2));
        std::cout << distance << std::endl;
        circle->updateCircle(distance, *window);
        if (event.type == sf::Event::MouseButtonReleased){
            if(event.key.code == sf::Mouse::Left){
                drawing = false;
            }
        }
    }

    else if (event.type == sf::Event::MouseButtonReleased){
        if(event.key.code == sf::Mouse::Left){
            drawing = false;
        }
    }
}