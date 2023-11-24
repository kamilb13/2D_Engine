
//
// Created by kayman on 06.11.23.
//
#ifndef RECTANGLEEVENTLISTENER_H
#define RECTANGLEEVENTLISTENER_H

#include "Rectangle.h"
#include <SFML/Graphics.hpp>
#include "iostream"




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


#endif