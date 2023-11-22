//
// Created by kayman on 21.11.23.
//

#ifndef INC_2D_ENGINE_CIRCLEEVENTLISTENER_H
#define INC_2D_ENGINE_CIRCLEEVENTLISTENER_H
#include <SFML/Graphics.hpp>
#include "Circle.h"
#include <cmath>
#include "iostream"


class CircleEventListener {
private:
    Circle *circle;
    sf::RenderWindow *window;
    bool drawing;

public:
    CircleEventListener(Circle *circle, sf::RenderWindow *window);

    void eventHandler(sf::Event event);
};


#endif //INC_2D_ENGINE_CIRCLEEVENTLISTENER_H
