//
// Created by kayman on 06.11.23.
//
#include "Rectangle.h"
#include <SFML/Graphics.hpp>
#include "iostream"

#ifndef INC_2D_ENGINE_RECTANGLEEVENTLISTENER_H
#define INC_2D_ENGINE_RECTANGLEEVENTLISTENER_H


class RectangleEventListener {
private:
    Rectangle *rectangle;
    sf::RenderWindow *window;
    std::vector<Rectangle> *rectangles;
    bool drawing;

public:
    RectangleEventListener(Rectangle *rectangle, sf::RenderWindow *window,  std::vector<Rectangle> *rectangles);

    void eventHandler(sf::Event event);
};


#endif //INC_2D_ENGINE_RECTANGLEEVENTLISTENER_H
