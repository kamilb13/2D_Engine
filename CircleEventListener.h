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
    std::vector<Circle> *circles;
    bool drawing;

public:
    CircleEventListener(Circle *circle, sf::RenderWindow *window, std::vector<Circle> *circles);

    void eventHandler(sf::Event event);
};


#endif INC_2D_ENGINE_CIRCLEEVENTLISTENER_H