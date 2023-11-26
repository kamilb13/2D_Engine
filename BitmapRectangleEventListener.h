//
// Created by kamil on 24.11.2023.
//

#ifndef INC_2D_ENGINE_BITMAPRECTANGLEEVENTLISTENER_H
#define INC_2D_ENGINE_BITMAPRECTANGLEEVENTLISTENER_H

/**
 * @file BitmapRectangleEventListener.h
 * @brief Plik naglowkowy zawierajacy definicje klasy BitmapRectangleEventListener
 */

#pragma once
#include "BitmapRectangle.h"
#include <SFML/Graphics.hpp>

/**
 * @class BitmapRectangleEventListener
 * @brief Klasa, ktora nasluchuje zdarzen dla klasy BitmapRectangle
 */
class BitmapRectangleEventListener {
public:
    /**
* @brief Konstruktor BitmapRectangleEventListener
* @param *line Aktualnie rysowany BitmapRectangle
* @param *window Okno w ktorym rysujemy
* @param *lines Wektor do ktorego zapisujemy BitmapRectangle
*/
    BitmapRectangleEventListener(BitmapRectangle* bitmapRectangle, sf::RenderWindow* window, std::vector<BitmapRectangle>* bitmapRectangles);

    /**
* @brief Funkcja eventHandler
* Funkcja czekajaca na zdarzenie zwiazene z rysowaniem BitmapRectangle
* @return Funkcja nic nie zwraca
*/
    void eventHandler(); //event

private:
    BitmapRectangle* bitmapRectangle;
    sf::RenderWindow* window;
    std::vector<BitmapRectangle>* bitmapRectangles;
};



#endif //INC_2D_ENGINE_BITMAPRECTANGLEEVENTLISTENER_H
