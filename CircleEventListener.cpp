//
// Created by kayman on 21.11.23.
//

#include "CircleEventListener.h"

CircleEventListener::CircleEventListener(Circle *circle, sf::RenderWindow *window, std::vector<Circle> *circles) {
    this->circle = circle;
    this->window = window;
    this->circles = circles;
}

void CircleEventListener::eventHandler(sf::Event event) {
//    float distance;
//    sf::Vector2i center; // Srodek koła
    if (event.type == sf::Event::MouseButtonPressed){
        if (event.mouseButton.button == sf::Mouse::Left){
            drawing = true;
            circle->startDrawing(event.mouseButton.x, event.mouseButton.y);
//            center = sf::Mouse::getPosition(*this->window);
        }
    }

    if(drawing) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        float radius = static_cast<float>(std::abs(mousePosition.x - circle->getCircleShape().getPosition().x));
        circle->updateCircle(radius, *window);
        if (event.type == sf::Event::MouseButtonReleased){
            if(event.mouseButton.button == sf::Mouse::Left){
                drawing = false;
                circles->push_back(*circle);
            }
        }
    }
}