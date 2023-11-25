//
// Created by kamil on 24.11.2023.
//

#ifndef INC_2D_ENGINE_BITMAPRECTANGLEEVENTLISTENER_H
#define INC_2D_ENGINE_BITMAPRECTANGLEEVENTLISTENER_H


#pragma once
#include "BitmapRectangle.h"
#include <SFML/Graphics.hpp>

class BitmapRectangleEventListener {
public:
    BitmapRectangleEventListener(BitmapRectangle* bitmapRectangle, sf::RenderWindow* window, std::vector<BitmapRectangle>* bitmapRectangles);

    void eventHandler(sf::Event event);

private:
    BitmapRectangle* bitmapRectangle;
    sf::RenderWindow* window;
    std::vector<BitmapRectangle>* bitmapRectangles;
};



#endif //INC_2D_ENGINE_BITMAPRECTANGLEEVENTLISTENER_H
